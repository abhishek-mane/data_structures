#include <stdio.h>
#include "ds/linkedlist/headers/doubly_list.h"
#include "lib/utils.h"

void display(Array *arr) {
    printf("List => ");
    for (int i = 0; i < arr->length; ++i) {
        printf("%d, ", arr->ptr[i]);
    }
}

int main() {

    DoublyLinkedList *list = create_list();

    insert_at_index(list, 1, 0);
    insert_at_index(list, 2, 1);
    insert_at_index(list, 3, 2);

    display(list);


    return 0;
}