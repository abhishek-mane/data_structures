/*
 * singly.c
 *
 *  Created on: 15-Jul-2018
 *  Author: Abhishek Mane <https://abhishek-mane.github.io>
 */

#include <stdlib.h>
#include <utils.h>
#include <linkedlist/singly.h>

Node *create_singly_ll_node(int data) {
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

SinglyLinkedList *create_singly_ll() {
	SinglyLinkedList *list = malloc(sizeof(SinglyLinkedList));
	list->head = NULL;
	list->length = 0;
	return list;
}

Bool is_empty(SinglyLinkedList *list) {
	return (list->head == NULL ? True : False);
}

void singly_ll_insert_node_at_head(SinglyLinkedList *list, int data) {

	Node *node = create_singly_ll_node(data);

	if (is_empty(list)) {
		list->tail = node;
	} else {
		node->next = list->head;
	}

	list->head = node;

	list->length += 1;
}

void singly_ll_insert_node_at_tail(SinglyLinkedList *list, int data) {

	Node *node = create_singly_ll_node(data);

	if (is_empty(list)) {
		list->head = node;
	} else {
		list->tail->next = node;
	}

	list->tail = node;

	list->length += 1;
}

void singly_ll_insert_node(SinglyLinkedList *list, int data) {
	singly_ll_insert_node_at_tail(list, data);
}

Array *singly_ll_get_array(SinglyLinkedList *list) {

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
