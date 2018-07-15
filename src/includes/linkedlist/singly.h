/*
 * singly.h
 *
 * Created on: 15-Jul-2018
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#ifndef LIB_HEADERS_LINKEDLIST_SINGLY_H_
#define LIB_HEADERS_LINKEDLIST_SINGLY_H_

#include <stdio.h>
#include <utils.h>

typedef struct _node {
	int data;
	struct _node *next;
} Node;

typedef struct _linked_list {
	Node *head;
	Node *tail;
	int length;
} SinglyLinkedList;

Node *create_singly_ll_node(int data);

SinglyLinkedList *create_singly_ll();

void singly_ll_insert_node_at_head(SinglyLinkedList *, int);

void singly_ll_insert_node_at_tail(SinglyLinkedList *, int);

void singly_ll_insert_node(SinglyLinkedList *, int);

Array *singly_ll_get_array(SinglyLinkedList *);

#endif /* LIB_HEADERS_LINKEDLIST_SINGLY_H_ */
