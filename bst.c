#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
}Node;

Node *root =NULL;

Node* insert(Node *root, int key){
    if(root == NULL){
        root = (Node*)malloc(sizeof(Node));
        root->left = NULL;
        root->right = NULL;
        root->key = key;
        return root;
    }
    else{
        if(root->key > key){
            root->left = insert(root->left,key);
        }
        else{
            root->right = insert(root->right,key);
        }
    }
    return root;
}
Node *Minnode(Node* root){
    Node* tmp = root;
    while(tmp->left != NULL){
        tmp = root->left;
    }
    return tmp;
}
Node *delete(Node* root,int key){
    Node* change =NULL;
    if(root == NULL){
        return NULL;
    }
    if(root->key > key){
        root->left = delete(root->left,key);
    }
    else if(root->key < key){
        root -> right = delete(root->right,key);
    }
    else{
        if(root->right !=NULL &&root->left !=NULL){
            change = Minnode(root->right);
            root->key =  change->key;
            root->right = delete(root->right,change->key);
        }
        else{
            change = (root->left == NULL) ? root->right : root->left;
            free(root);
            return change;
        }
    }
    return root;
}
Node * search(Node* root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->key == key){
        return root;
    }
    else if(root->key > key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
void print(Node* root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->key);
    print(root->left);
    print(root->right);
}
int main(){
    int i,key;
    for(i=0;i<6;i++){
        scanf("%d",&key);
        root = insert(root,key);
    }
    root = delete(root,7);
    
    print(root);
}

