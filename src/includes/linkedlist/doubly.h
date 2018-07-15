/*
 * doubly.h
 *
 *  Created on: 15-Jul-2018
 *  Author: Abhishek Mane <https://abhishek-mane.github.io>
 */

#ifndef INCLUDES_LINKEDLIST_DOUBLY_H_
#define INCLUDES_LINKEDLIST_DOUBLY_H_

#include <stdio.h>
#include <utils.h>

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

Node *create_doubly_ll_node(int data);

DoublyLinkedList *create_doubly_ll();

Array *doubly_ll_get_array(DoublyLinkedList *);

Bool doubly_ll_insert_at_index(DoublyLinkedList *, int, int);

#endif /* INCLUDES_LINKEDLIST_DOUBLY_H_ */
