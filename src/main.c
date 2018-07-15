/*
 * main.c
 *
 * Created on: 15-Jul-2018
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#include <stdio.h>
#include <utils.h>
#include <linkedlist/singly_circular.h>
#include <linkedlist/doubly.h>

void display(Array *arr) {
	printf("List => ");
	for (int i = 0; i < arr->length; ++i) {
		printf("%d, ", arr->ptr[i]);
	}
}

int main() {

//	SinglyCircularLinkedList *list = create_singly_circular_ll();
//
//	list->insert_node(list, 12);
//	list->insert_node(list, 23);
//	list->insert_node(list, 34);
//	list->insert_node(list, 45);
//	list->insert_node(list, 56);
//
//	display(list->get_array(list));

	DoublyLinkedList *list = create_doubly_linked_list();

	list->insert(list, 12);
	list->insert(list, 23);
	list->insert(list, 34);

	display(list->get_array(list));
	printf("\n");

	list->delete_head(list);

	display(list->get_array(list));
	printf("\n");

	list->delete_head(list);

	display(list->get_array(list));
	printf("\n");

	return 0;
}
