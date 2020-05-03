cmake_minimum_required(VERSION 3.16)
project(lab2_sync C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(lab2_sync
        include/lab2_sync_types.h
        include/lab2_timeval.c
        lab2_bst.c
        lab2_bst_test.c)
