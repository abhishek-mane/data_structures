#include <stdio.h>
#include "ds/linkedlist/headers/singly_linked_list.h"

void display(Array *arr) {
    printf("List => ");
    for (int i = 0; i < arr->length; ++i) {
        printf("%d, ", arr->ptr[i]);
    }
}

int main() {

    SinglyLinkedList *l = create_list();

    add_node_at_head(l, 5);
    add_node_at_head(l, 6);
    add_node_at_head(l, 7);
    add_node_at_head(l, 3);
    display(get_array(l));
    return 0;
}