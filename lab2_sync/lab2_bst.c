/*
*    Operating System Lab
*        Lab2 (Synchronization)
*        Student id :
*        Student name :
*
*   lab2_bst.c :
*       - thread-safe bst code.
*       - coarse-grained, fine-grained lock code
*
*   Implement thread-safe bst for coarse-grained version and fine-grained version.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <string.h>

#include "lab2_sync_types.h"


/*
 * TODO
 *  Implement funtction which traverse BST in in-order
 *
 *  @param lab2_tree *tree  : bst to print in-order.
 *  @return                 : status (success or fail)
 */
int lab2_node_print_inorder(lab2_node *root,int count) {                          //변경
    // You need to implement lab2_node_print_inorder function.
    if (root == NULL){
        return count;
    }
    count += 1;
    count = lab2_node_print_inorder(root->left,count);                              //왼쪽부터 중간 오른쪽 순으로 출력
    //printf("%d ",root->key);
    count = lab2_node_print_inorder(root->right,count);
    return count;
}

/*
 * TODO
 *  Implement function which creates struct lab2_tree
 *  ( refer to the ./include/lab2_sync_types.h for structure lab2_tree )
 *
 *  @return                 : bst which you created in this function.
 */
lab2_tree *lab2_tree_create() {
    // You need to implement lab2_tree_create function.
    lab2_tree *tree;
    tree = (lab2_tree*)malloc(sizeof(lab2_tree));                   //tree에 메모리할당
    tree->root = NULL;                                              //tree의 root에 NULL을 넣어준다(아직 아무것도 안들어왔기 때문)
    pthread_mutex_init(&tree->tree_mutex,NULL);
    return tree;
}

/*
 * TODO
 *  Implement function which creates struct lab2_node
 *  ( refer to the ./include/lab2_sync_types.h for structure lab2_node )
 *
 *  @param int key          : bst node's key to creates
 *  @return                 : bst node which you created in this function.
 */
lab2_node * lab2_node_create(int key) {
    // You need to implement lab2_node_create function.
    lab2_node *node;
    node = (lab2_node*)malloc(sizeof(lab2_node));                   //새로운 Node에 메모리할당
    node->key = key;                                                //주어진 key값을 입력, 자식들을 NULL로 초기화
    node->left = NULL;
    node->right = NULL;
    pthread_mutex_init(&node->mutex,NULL);
    return node;                                                    //node 반환
}

/*
 * TODO
 *  Implement a function which insert nodes from the BST.
 *
 *  @param lab2_tree *tree      : bst which you need to insert new node.
 *  @param lab2_node *new_node  : bst node which you need to insert.
 *  @return                 : satus (success or fail)
 */
int lab2_node_insert(lab2_tree *tree, lab2_node *new_node){
    // You need to implement lab2_node_insert function.
    lab2_node *tmp;
    tmp = tree->root;
    if(tmp == NULL){
        tree->root = new_node;
        return 1;                                       //입력 성공
    }
    while(1){
        if(tmp->key == new_node->key){
            return 0;                                   //입력 실패(이미 같은 값을 데이터 보관)
        }
        else if(tmp->key > new_node->key){              //부모보다 작을때  left를 확인
            if(tmp->left){
                tmp = tmp->left;
            }
            else{
                tmp->left = new_node;
                return 1;                               //입력 성공
            }
        }
        else{                                           //부모보다 클때 right를 확인
            if(tmp->right){
                tmp = tmp->right;
            }
            else{
                tmp->right = new_node;
                return 1;                               //입력 성공
            }
        }
    }
}

/*
 * TODO
 *  Implement a function which insert nodes from the BST in fine-garined manner.
 *
 *  @param lab2_tree *tree      : bst which you need to insert new node in fine-grained manner.
 *  @param lab2_node *new_node  : bst node which you need to insert.
 *  @return                     : status (success or fail)
 */
int lab2_node_insert_fg(lab2_tree *tree, lab2_node *new_node){
      // You need to implement lab2_node_insert_fg function.
    lab2_node *tmp_parents, *tmp;

    tmp = tree->root;

    if(tmp == NULL){
        pthread_mutex_lock(&tree->tree_mutex);                                      //tree_mutex lock
        tree->root = new_node;
        pthread_mutex_unlock(&tree->tree_mutex);                                    //tree_mutex unlock
        return 1;                                                                   //입력 성공
    }
    pthread_mutex_lock(&tmp->mutex);                                                //처음 lock
    while(1){
        if(tmp->key == new_node->key){
            pthread_mutex_unlock(&tmp->mutex);                                      //같은값이 있을경우 unlock
            return 0;                                                               //입력 실패(이미 같은 값을 데이터 보관)
        }
        else if(tmp->key > new_node->key){                                          //부모보다 작을때  left를 확인
            if(tmp->left){

                tmp_parents = tmp;
                tmp = tmp->left;
                pthread_mutex_lock(&tmp->mutex);                                    //현재 노드 lock
                pthread_mutex_unlock(&tmp_parents->mutex);                          //부모 노드 unlock

            }
            else{
                tmp->left = new_node;
                pthread_mutex_unlock(&tmp->mutex);                                  //현재 노드 unlock
                return 1;                                                           //입력 성공
            }
        }
        else{                                                                       //부모보다 클때 right를 확인
            if(tmp->right){
                tmp_parents = tmp;
                tmp = tmp->right;
                pthread_mutex_lock(&tmp->mutex);                                    //현재 노드 lock
                pthread_mutex_unlock(&tmp_parents->mutex);                          //부모 노드 unlock
            }
            else{
                tmp->right = new_node;
                pthread_mutex_unlock(&tmp->mutex);                                  //현재 노드 lock
                return 1;                                                           //입력 성공

            }
        }
    }
}

/*
 * TODO
 *  Implement a function which insert nodes from the BST in coarse-garined manner.
 *
 *  @param lab2_tree *tree      : bst which you need to insert new node in coarse-grained manner.
 *  @param lab2_node *new_node  : bst node which you need to insert.
 *  @return                     : status (success or fail)
 */
int lab2_node_insert_cg(lab2_tree *tree, lab2_node *new_node){
    // You need to implement lab2_node_insert_cg function.
    lab2_node *tmp;
    pthread_mutex_lock(&tree->tree_mutex);                                              //coarse grained lock 시작할때 lock
    tmp = tree->root;
    if(tmp == NULL){

        tree->root = new_node;
        tmp = tree->root;
        pthread_mutex_unlock(&tree->tree_mutex);                                        //return 하기전에 unlock
        return 1;                                                                       //입력 성공
    }

    while(1){
        if(tmp->key == new_node->key){
            pthread_mutex_unlock(&tree->tree_mutex);                                    //return 하기전에 unlock
            return 0;                                                                   //입력 실패(이미 같은 값을 데이터 보관)
        }
        else if(tmp->key > new_node->key){                                              //부모보다 작을때  left를 확인
            if(tmp->left){
                tmp = tmp->left;
            }
            else{
                tmp->left = new_node;
                pthread_mutex_unlock(&tree->tree_mutex);                                //return 하기전에 unlock
                return 1;                                                               //입력 성공
            }
        }
        else{                                                                           //부모보다 클때 right를 확인
            if(tmp->right){
                tmp = tmp->right;
            }
            else{
                tmp->right = new_node;
                pthread_mutex_unlock(&tree->tree_mutex);                                //return 하기전에 unlock
                return 1;                                                               //입력 성공
            }
        }
    }
}

/*
 * TODO
 *  Implement a function which remove nodes from the BST.
 *
 *  @param lab2_tree *tree  : bst tha you need to remove node from bst which contains key.
 *  @param int key          : key value that you want to delete.
 *  @return                 : status (success or fail)
 */
int lab2_node_remove(lab2_tree *tree, int key) {
    // You need to implement lab2_node_remove function.
    lab2_node *del_parent, *del, *change, *change_parent, *child;
    del_parent = NULL;
    del = tree->root;
    pthread_mutex_t remove;
    while((del != NULL ) &&( del->key != key)){                                 //p가 NULL이거나 key값이 같을때까지반복
        del_parent = del;
        if(key < del->key){                                                     //주어진 key값이 p의 key값보다 작으면 left로이동
            del = del->left;
        }
        else{                                                                   //주어진 key값이 p의 key값보다 크면 right로 이동
            del = del->right;
        }
    }
    if(del == NULL){                                                            //NULL이면 주어진 key값이 없는것 이므로 return
        return 0;
    }
    if(del->left == NULL && del->right == NULL){                                //삭제하고자하는 node의 자식이 없을때
        if(del_parent != NULL){
            if(del_parent->left == del)                                         //삭제하고자하는 node가 왼쪽에 존재했을경우
                del_parent->left = NULL;
            else                                                                //삭제하고자하는 node가 오른쪽에 존재했을경우
                del_parent->right = NULL;
        }
        else                                                                    //삭제하고자하는 node가 root인경우
            tree->root = NULL;
    }
    else if(del->left != NULL && del->right != NULL){                           //삭제하고자하는 node의 자식이 2개 모두 있을때
        change_parent = del;
        change = del->left;                                                     //왼쪽에서 가장 큰 node를 찾기위해
        while(change->right != NULL){                                           //NULL이 될때까지 오른쪽으로
            change_parent = change;
            change = change->right;
        }
        if(change_parent->left == change)                                       //바꾸고자 하는 node가 왼쪽자식일때
            change_parent->left = change->left;
        else                                                                    //오른쪽 자식일때
            change_parent->right = change->left;
        del->key = change->key;
        del = change;
    }
    else{                                                                       //삭제하고자하는 node의 자식이 1개만 있을때
        if(del->left != NULL)                                                   //왼쪽 자식이 있을때
            child = del->left;
        else                                                                    //오른쪽에 자식이 있을때
            child = del->right;
        if(del_parent != NULL){
            if(del_parent->left == del)                                         //삭제하고자 하는 node가 왼쪽에 있을때
                del_parent->left = child;
            else                                                                //삭제하고자 하는 node가 오른쪽에 있을때
                del_parent->right = child;
        }
        else
            tree->root = child;
    }
    free(del);
    del = NULL;
}

/*
 * TODO
 *  Implement a function which remove nodes from the BST in fine-grained manner.
 *
 *  @param lab2_tree *tree  : bst tha you need to remove node in fine-grained manner from bst which contains key.
 *  @param int key          : key value that you want to delete.
 *  @return                 : status (success or fail)
 */
int lab2_node_remove_fg(lab2_tree *tree, int key) {
    // You need to implement lab2_node_remove_fg function.
    lab2_node *del_parent, *del, *change, *change_parent, *child;
    del_parent = NULL;
    del = tree->root;
    pthread_mutex_lock(&del->mutex);
    while((del != NULL ) &&( del->key != key)){                                  //p가 NULL이거나 key값이 같을때까지반복
        del_parent = del;
        if(key < del->key){                                                      //주어진 key값이 p의 key값보다 작으면 left로이동
            del_parent = del;
            del = del->left;
            if(del != NULL) {
                pthread_mutex_lock(&del->mutex);                                 //탐색하면서 돌아가면서 현제노드에 lock 부모노드를 unlock
                pthread_mutex_unlock(&del_parent->mutex);
            }
        }
        else if (key > del->key){                                                //주어진 key값이 p의 key값보다 크면 right로 이동
            del_parent = del;
            del = del->right;
            if(del != NULL) {
                pthread_mutex_lock(&del->mutex);                                //탐색하면서 돌아가면서 현제노드에 lock 부모노드를 unlock
                pthread_mutex_unlock(&del_parent->mutex);
            }
        }
    }
    if(del != NULL)
        pthread_mutex_unlock(&del->mutex);                                          //탐색이 끝났으므로 unlock
    else{                                                            //NULL이면 주어진 key값이 없는것 이므로 return
        pthread_mutex_unlock(&del_parent->mutex);
        return 0;
    }
    if (del_parent != NULL)                                                     //del이 root노드가 아닐때 부모노드에 lock (root노드는 부모X)
        pthread_mutex_lock(&del_parent->mutex);
    pthread_mutex_lock(&del->mutex);
    if(del->left == NULL && del->right == NULL){
        if(del_parent != NULL){
            if(del_parent->left == del) {
                del_parent->left = NULL;
            }
            else {
                del_parent->right = NULL;
            }
            pthread_mutex_unlock(&del_parent->mutex);                           //del의 부모노드 사용이 끝났으므로 unlock
        }
        else {                                                                  //삭제하고자하는 node가 root인경우
            tree->root = NULL;
        }
        pthread_mutex_unlock(&del->mutex);                                      //삭제함수가 종료됬으므로 del unlock
        free(del);
        del = NULL;
    }
    else if(del->left != NULL && del->right != NULL){                           //삭제하고자하는 node의 자식이 2개 모두 있을때
        change_parent = del;
        change = del->left;                                                     //왼쪽에서 가장 큰 node를 찾기위해
        pthread_mutex_lock(&change->mutex);                                     //change를 돌아다니면서 찾을 것 이므로 lock 위의 del을 찾는거와 유사
        while(change->right != NULL){
            change_parent = change;
            change = change->right;
            pthread_mutex_lock(&change->mutex);                                 //현재 node를 lock 이전에 있었던 node(부모)를 unlock
            pthread_mutex_unlock(&change_parent->mutex);
        }
        if (change_parent != del)
            pthread_mutex_lock(&change_parent->mutex);                          //change의 부모노드 사용 lock
        if (change_parent->left == change) {                                    //바꾸고자 하는 node가 왼쪽자식일때
            change_parent->left = change->left;
        }
        else {                                                                  //오른쪽 자식일때
            change_parent->right = change->left;
        }
        if (change_parent != del)
            pthread_mutex_unlock(&change_parent->mutex);                        //change의 부모노드 사용이 끝났으므로 unlock
        del->key = change->key;
        pthread_mutex_unlock(&change->mutex);                                   //삭제함수가 끝났으므로 change와 del, del_parent unlock
        pthread_mutex_unlock(&del->mutex);
        free(change);
        change = NULL;
        if(del_parent != NULL)
            pthread_mutex_unlock(&del_parent->mutex);
    }
    else {                                                                       //삭제하고자하는 node의 자식이 1개만 있을때

        if (del->left != NULL) {                                                 //왼쪽 또는 오른쪽 자식 (존재하는곳) lock
            pthread_mutex_lock(&del->left->mutex);
            child = del->left;
        } else if (del->right !=NULL) {
            pthread_mutex_lock(&del->right->mutex);
            child = del->right;
        }
        if (child != NULL) {                                                         //다른 thread가 지워서 양쪽노드에 아무것도 없어질 경우
            if (del_parent != NULL) {
                if (del_parent->left == del) {                                       //삭제하고자 하는 node가 왼쪽에 있을때
                    del_parent->left = child;
                } else {                                                              //삭제하고자 하는 node가 오른쪽에 있을때
                    del_parent->right = child;
                }
                pthread_mutex_unlock(&del_parent->mutex);                           //del_parent 사용 종료 unlock
            } else {
                tree->root = child;
            }
            pthread_mutex_unlock(&child->mutex);                                //왼쪽 혹은 오른쪽 자식 unlock
        }
        pthread_mutex_unlock(&del->mutex);                                      //삭제함수 종료 del unlock
        free(del);
        del = NULL;

    }
}


/*
 * TODO
 *  Implement a function which remove nodes from the BST in coarse-grained manner.
 *
 *  @param lab2_tree *tree  : bst tha you need to remove node in coarse-grained manner from bst which contains key.
 *  @param int key          : key value that you want to delete.
 *  @return                 : status (success or fail)
 */
int lab2_node_remove_cg(lab2_tree *tree, int key) {
    // You need to implement lab2_node_remove_cg function.
    lab2_node *del_parent, *del, *change, *change_parent, *child;
    del_parent = NULL;
    del = tree->root;
    pthread_mutex_lock(&tree->tree_mutex);                                      //coarse grained lock
    while((del != NULL ) &&( del->key != key)){                                 //p가 NULL이거나 key값이 같을때까지반복
        del_parent = del;
        if(key < del->key)                                                      //주어진 key값이 p의 key값보다 작으면 left로이동
            del = del->left;
        else                                                                    //주어진 key값이 p의 key값보다 크면 right로 이동
            del = del->right;
    }
    if(del == NULL){                                                            //NULL이면 주어진 key값이 없는것 이므로 return
        pthread_mutex_unlock(&tree->tree_mutex);
        return 0;
    }
    if(del->left == NULL && del->right == NULL){                                //삭제하고자하는 node의 자식이 없을때
        if(del_parent != NULL){
            if(del_parent->left == del)                                         //삭제하고자하는 node가 왼쪽에 존재했을경우
                del_parent->left = NULL;
            else                                                                //삭제하고자하는 node가 오른쪽에 존재했을경우
                del_parent->right = NULL;
        }
        else                                                                    //삭제하고자하는 node가 root인경우
            tree->root = NULL;
    }
    else if(del->left != NULL && del->right != NULL){                           //삭제하고자하는 node의 자식이 2개 모두 있을때
        change_parent = del;
        change = del->left;                                                     //왼쪽에서 가장 큰 node를 찾기위해
        while(change->right != NULL){                                           //NULL이 될때까지 오른쪽으로
            change_parent = change;
            change = change->right;
        }
        if(change_parent->left == change)                                       //바꾸고자 하는 node가 왼쪽자식일때
            change_parent->left = change->left;
        else                                                                    //오른쪽 자식일때
            change_parent->right = change->left;
        del->key = change->key;
        del = change;
    }
    else {                                                                      //삭제하고자하는 node의 자식이 1개만 있을때
        if(del->left != NULL)                                                   //왼쪽 자식이 있을때
            child = del->left;
        else                                                                    //오른쪽에 자식이 있을때
            child = del->right;
        if(del_parent != NULL){

            if(del_parent->left == del)                                         //삭제하고자 하는 node가 왼쪽에 있을때
                del_parent->left = child;
            else                                                                //삭제하고자 하는 node가 오른쪽에 있을때
                del_parent->right = child;
        }
        else
            tree->root = child;
    }
    pthread_mutex_unlock(&tree->tree_mutex);                                    //unlock
    free(del);
    del = NULL;
    return 1;
}


/*
 * TODO
 *  Implement function which delete struct lab2_tree
 *  ( refer to the ./include/lab2_sync_types.h for structure lab2_node )
 *
 *  @param lab2_tree *tree  : bst which you want to delete.
 *  @return                 : status(success or fail)
 */
void lab2_tree_delete(lab2_tree *tree) {
    // You need to implement lab2_tree_delete function.
    lab2_node_delete(tree->root,tree->root);
    free(tree);
    tree = NULL;
}

/*
 * TODO
 *  Implement function which delete struct lab2_node
 *  ( refer to the ./include/lab2_sync_types.h for structure lab2_node )
 *
 *  @param lab2_tree *tree  : bst node which you want to remove.
 *  @return                 : status(success or fail)
 */
void lab2_node_delete(lab2_node *node,lab2_node *parents) {
    // You need to implement lab2_node_delete function.
    if(node)
    {
        lab2_node_delete(node->left,node);
        lab2_node_delete(node->right,node);
        free(node);
        node = NULL;
        if(parents == node){
            return;
        }
    }
}
