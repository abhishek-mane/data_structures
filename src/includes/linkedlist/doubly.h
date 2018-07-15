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

DoublyLinkedList *create_list();

#endif /* INCLUDES_LINKEDLIST_DOUBLY_H_ */
