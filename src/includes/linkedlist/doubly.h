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

typedef struct _doubly_ll_node {
	int data;
	struct _doubly_ll_node *next;
	struct _doubly_ll_node *prev;
} DoublyLinkedListNode;

typedef struct _doubly_linked_list {

	// ========== vars ==========
	DoublyLinkedListNode *head;
	DoublyLinkedListNode *tail;
	int length;

	// ========== methods ==========
	DoublyLinkedListNode* (*create_node)(int);
	Bool (*is_empty)(struct _doubly_linked_list *);
	void (*insert)(struct _doubly_linked_list *, int);
	Array* (*get_array)(struct _doubly_linked_list *);

} DoublyLinkedList;

DoublyLinkedList *create_doubly_linked_list();
#endif /* INCLUDES_LINKEDLIST_DOUBLY_H_ */
