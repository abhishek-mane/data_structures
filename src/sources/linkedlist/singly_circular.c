/*
 * singly_circular.c
 *
 *  Created on: 15-Jul-2018
 *  Author: Abhishek Mane <https://abhishek-mane.github.io>
 */

#include <stdio.h>
#include <stdlib.h>
#include <utils.h>
#include <linkedlist/singly_circular.h>

Node* create_singly_circular_ll_node(int data) {
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	return node;
}

void singly_circular_ll_insert_node(SinglyCircularLinkedList *list, int data) {

	Node *node = list->create_node(data);

	if (list->head == NULL) {
		list->head = list->tail = node;
		list->tail->next = list->head;
	} else {
		list->tail->next = node;
		list->tail = node;
	}

	list->tail->next = list->head;
	list->length += 1;
}

Array* singly_circular_ll_get_array(SinglyCircularLinkedList *list) {

	Array *arr = malloc(sizeof(Array));

	arr->ptr = calloc(sizeof(int), (size_t) list->length);
	arr->length = list->length;

	int i = 0;
	Node *p = list->head;
	do {
		(arr->ptr)[i++] = p->data;
		p = p->next;
	} while (p != list->head);

	return arr;
}

SinglyCircularLinkedList *create_singly_circular_ll() {

	SinglyCircularLinkedList *list = malloc(sizeof(SinglyCircularLinkedList));

// initialize vars
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;

// initialize methods
	list->create_node = &create_singly_circular_ll_node;
	list->insert_node = &singly_circular_ll_insert_node;
	list->get_array = &singly_circular_ll_get_array;

	return list;
}
