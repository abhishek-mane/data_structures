//
// Created by abhishek on 13/7/18.
//

#ifndef DATA_STRUCTURES_DOUBLY_LIST_H
#define DATA_STRUCTURES_DOUBLY_LIST_H

#include <stdio.h>

typedef struct _node {
    int data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _linked_list {
    Node *head;
    Node *tail;
    int length;
} DoublyLinkedList;

DoublyLinkedList *create_list();

Node *create_node(int);

//Bool insert_at_index(DoublyLinkedList *, int, int);

#endif //DATA_STRUCTURES_DOUBLY_LIST_H
