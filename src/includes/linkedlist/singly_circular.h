/*
 * singly_circular.h
 *
 * Created on: 15-Jul-2018
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#ifndef INCLUDES_LINKEDLIST_SINGLY_CIRCULAR_H_
#define INCLUDES_LINKEDLIST_SINGLY_CIRCULAR_H_

#include <stdio.h>
#include <utils.h>

typedef struct _node {
	int data;
	struct _node *next;
} Node;

typedef struct _singly_circular_linked_list {

	Node *head;
	Node *tail;
	int length;

	Node* (*create_node)(int);
	void (*insert_node)(struct _singly_circular_linked_list *, int);
	Array* (*get_array)(struct _singly_circular_linked_list *);

} SinglyCircularLinkedList;

// Creates & returns the singly linked list
SinglyCircularLinkedList *create_singly_circular_ll();

#endif /* INCLUDES_LINKEDLIST_SINGLY_CIRCULAR_H_ */
