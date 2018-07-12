cmake_minimum_required(VERSION 3.10)
project(data_structures C)

set(CMAKE_C_STANDARD 99)

add_executable(data_structures main.c ds/linkedlist/src/singly_linked_list.c ds/linkedlist/headers/singly_linked_list.h lib/utils.h)