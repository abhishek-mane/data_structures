/*
 * doubly.c
 *
 *  Created on: 15-Jul-2018
 *  Author: Abhishek Mane <https://abhishek-mane.github.io>
 */

#include <stdio.h>
#include <stdlib.h>
#include "lib/headers/linkedlist/doubly.h"
#include "lib/utils.h"

DoublyLinkedList *create_list() {
	DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}

Node *create_node(int data) {
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

Bool insert_at_index(DoublyLinkedList *list, int data, int index) {

	Node *node = create_node(data);

	if (index > list->length)
		return False;

	if (list->head == NULL) {
		list->head = list->tail = node;
	} else {
		Node *p = list->head;
		while (--index)
			p = p->next;

		if (p->next != NULL) {
			p->next->prev = node;
		}
		node->next = p->next;
		node->prev = p;
		p->next = node;
	}

	return True;
}

Array *get_array(DoublyLinkedList *list) {

	Array *arr = malloc(sizeof(Array));
	arr->ptr = calloc(sizeof(int), (size_t) list->length);
	arr->length = list->length;

	int i = 0;
	Node *p = list->head;
	while (p != NULL ) {
		(arr->ptr)[i++] = p->data;
		p = p->next;
	}

	return arr;
}
