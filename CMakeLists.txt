cmake_minimum_required(VERSION 3.16)
project(bst C)

set(CMAKE_C_STANDARD 11)

include_directories(lab2_sync/include)

add_executable(bst
        lab2_sync/include/lab2_sync_types.h
        lab2_sync/include/lab2_timeval.c
        lab2_sync/lab2_bst.c
        lab2_sync/lab2_bst_test.c)
