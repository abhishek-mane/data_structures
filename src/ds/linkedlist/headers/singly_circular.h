//
// Created by abhishek on 12/7/18.
//

#ifndef DATA_STRUCTURES_SINGLY_CIRCULAR_H
#define DATA_STRUCTURES_SINGLY_CIRCULAR_H

#include <stdio.h>

typedef struct _node {
    int data;
    struct _node *next;
} Node;

typedef struct _linked_list {
    Node *head;
    Node *tail;
    int length;
} SinglyCircularLinkedList;

SinglyCircularLinkedList *create_list();

void add_node(SinglyCircularLinkedList *, int);


#endif //DATA_STRUCTURES_SINGLY_CIRCULAR_H
