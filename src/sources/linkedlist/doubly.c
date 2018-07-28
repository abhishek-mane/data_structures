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

DoublyLinkedListNode* doubly_ll_insert(DoublyLinkedList *list, int data) {

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

	// return node
	return node;
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

void doubly_ll_delete_head(DoublyLinkedList *list) {

	// if list is empty
	if (list->is_empty(list))
		return;

	// if there is only 1 node in the list
	if (list->head == list->tail) {
		free(list->head);
		list->head = list->tail = NULL;
	}
	// multiple nodes : now, delete head
	else {
		DoublyLinkedListNode *temp = list->head;
		list->head->next->prev = NULL;
		list->head = list->head->next;
		free(temp);
	}

	// decrease length count
	list->length -= 1;

	return;
}

void doubly_ll_delete_tail(DoublyLinkedList *list) {

	// if list is empty
	if (list->is_empty(list))
		return;

	// if there is only 1 node in the list
	if (list->head == list->tail) {
		free(list->tail);
		list->head = list->tail = NULL;

	}
	// multiple nodes : now, delete tail
	else {

		DoublyLinkedListNode *temp = list->tail;
		list->tail->prev->next = NULL;
		list->tail = list->tail->prev;
		free(temp);
	}

	// decrease length count
	list->length -= 1;

	return;
}

void doubly_ll_delete(DoublyLinkedList *list, DoublyLinkedListNode *node) {

	// return if list is empty
	if (list->is_empty(list))
		return;

	// if node to be deleted is head
	if (node == list->head) {
		list->delete_head(list);
		return;
	}

	if (node == list->tail) {
		list->delete_tail(list);
		return;
	}

	/* Search prev of node to be deleted
	 * p will start searching from head
	 * q will start searching from tail
	 */
	DoublyLinkedListNode *p = list->head, *q = list->tail, *nodes_prev = NULL;

	for (; p != q && p->prev != q; p = p->next, q = q->prev) {

		// break if found
		if (p->next == node) {
			nodes_prev = p;
			break;
		}

		// break if found
		if (q->prev == node) {
			nodes_prev = q->prev->prev;
			break;
		}
	}

	// node not found
	if (nodes_prev == NULL)
		return;

	// node found, now delete it
	nodes_prev->next = node->next;
	node->next->prev = nodes_prev;
	free(node);

	// decrement length
	list->length -= 1;
}

DoublyLinkedList *create_doubly_linked_list() {

	// allocate size
	DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));

	// initialize variables
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;

	// initialize methods
	list->create_node = &doubly_ll_create_node;
	list->is_empty = &doubly_ll_is_empty;
	list->insert = &doubly_ll_insert;
	list->delete_head = &doubly_ll_delete_head;
	list->delete_tail = &doubly_ll_delete_tail;
	list->delete_node = &doubly_ll_delete;
	list->get_array = &doubly_ll_get_array;

	return list;
}

