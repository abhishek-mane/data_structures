cmake_minimum_required(VERSION 3.10)

project(data_structures C)
set(SOURCE src/main.c)

set(CMAKE_C_STANDARD 99)

# ============= headers/includes =============
include_directories(src/includes)

add_executable(
        # Project
        data_structures

        # Main
        src/main.c

        # ============= Sources =============
        src/sources/linkedlist/singly.c
        src/sources/linkedlist/doubly.c
        src/sources/linkedlist/singly_circular.c
        src/sources/trees/binary_search_tree.c
        src/sources/stack/stack_array.c
        src/sources/stack/stack_ll.c
        src/includes/queue/circular_queue.h src/sources/queue/circular_queue.c)