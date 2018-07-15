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

void display(Array *arr) {
	printf("List => ");
	for (int i = 0; i < arr->length; ++i) {
		printf("%d, ", arr->ptr[i]);
	}
}

int main() {

	SinglyCircularLinkedList *list = create_singly_circular_ll();

	list->insert_node(list, 12);
	list->insert_node(list, 23);
	list->insert_node(list, 34);
	list->insert_node(list, 45);
	list->insert_node(list, 56);

	display(list->get_array(list));

	return 0;
}
