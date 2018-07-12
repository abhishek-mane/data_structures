//
// Created by abhishek on 11/7/18.
//

#include <stdlib.h>
#include "../headers/singly_linked_list.h"

Node *create_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

SinglyLinkedList *create_list() {
    SinglyLinkedList *list = malloc(sizeof(SinglyLinkedList));
    list->head = NULL;
    list->length = 0;
}

void increment_length(SinglyLinkedList *list) {
    list->length += 1;
}

void decrement_length(SinglyLinkedList *list) {
    list->length -= 1;
}

void add_node_at_head(SinglyLinkedList *list, int data) {
    Node *node = create_node(data);
    node->next = list->head;
    list->head = node;
    increment_length(list);
}

void add_node_at_tail(SinglyLinkedList *list, int data) {
    Node *node = create_node(data);
    list->tail->next = node;
    increment_length(list);
}

void add_node_after(SinglyLinkedList *list, int data) {

}

void add_node(SinglyLinkedList *list, int data) {
    add_node_at_tail(list, data);
}

Array *get_array(SinglyLinkedList *list) {

    Array *arr = malloc(sizeof(Array));
    arr->ptr = calloc(sizeof(int), (size_t) list->length);
    arr->length = list->length;

    int i = 0;
    Node *p = list->head;
    while (p != NULL) {
        (arr->ptr)[i++] = p->data;
        p = p->next;
    }

    return arr;
}