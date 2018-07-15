/*
 * main.c
 *
 *  Created on: 15-Jul-2018
 *  Author: Abhishek Mane <https://abhishek-mane.github.io>
 */

#include <stdio.h>

#include "includes/linkedlist/singly.h"
#include "includes/utils.h"

void display(Array *arr) {
	printf("List => ");
	for (int i = 0; i < arr->length; ++i) {
		printf("%d, ", arr->ptr[i]);
	}
}

int main() {

	SinglyLinkedList * list = create_list();

	add_node(list, 34);
	add_node(list, 34);
	add_node(list, 34);
	add_node(list, 34);

	display(get_array(list));

	return 0;
}
