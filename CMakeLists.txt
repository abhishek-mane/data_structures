cmake_minimum_required(VERSION 3.10)
project(data_structures C)

set(CMAKE_C_STANDARD 99)

add_executable(
        # Project
        data_structures
        # Main
        main.c
        # Utils
        lib/utils.h
        # Linked lists
        ds/linkedlist/headers/singly.h ds/linkedlist/src/singly.c
        ds/linkedlist/headers/singly_circular.h ds/linkedlist/src/singly_circular.c
        ds/linkedlist/src/doubly_list.c ds/linkedlist/headers/doubly_list.h ds/queue/headers/dequeue.h ds/queue/src/dequeue.c)