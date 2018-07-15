/*
 * doubly.c
 *
 * Created on: 15-Jul-2018
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <linkedlist/doubly.h>

DoublyLinkedListNode *doubly_ll_create_node(int data) {

	// allocate size
	DoublyLinkedListNode *node = malloc(sizeof(DoublyLinkedListNode));

	// initialize members
	node->data = data;
	node->next = NULL;
	node->prev = NULL;

	// return
	return node;
}

void doubly_ll_insert(DoublyLinkedList *list, int data) {

	// allocate node
	DoublyLinkedListNode *node = list->create_node(data);

	// insert node
	if (list->is_empty(list)) {
		list->head = node;
	} else {
		list->tail->next = node;
		node->prev = list->tail;
	}

	// inserted node is new tail now
	list->tail = node;

	// increase length
	list->length += 1;
}

Bool doubly_ll_is_empty(DoublyLinkedList *list) {
	return (list->head == NULL ? True : False);
}

Array *doubly_ll_get_array(DoublyLinkedList *list) {

	// allocate array
	Array *arr = malloc(sizeof(Array));

	// initialize array members
	arr->ptr = calloc(sizeof(int), (size_t) list->length);
	arr->length = list->length;

	// traverse list & put it into array
	int i = 0;
	DoublyLinkedListNode *p = list->head;
	while (p != NULL) {
		(arr->ptr)[i++] = p->data;
		p = p->next;
	}

	// return
	return arr;
}

DoublyLinkedList *create_doubly_linked_list() {

	// allocate size
	DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));

	// initialize variables
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;

	// initialize methods
	list->insert = &doubly_ll_insert;
	list->is_empty = &doubly_ll_is_empty;
	list->create_node = &doubly_ll_create_node;
	list->get_array = &doubly_ll_get_array;

	return list;
}
