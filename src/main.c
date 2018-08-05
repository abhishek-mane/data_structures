/*
 * main.c
 *
 * Created on: 15-Jul-2018
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#include <stdio.h>
#include <utils.h>
#include <malloc.h>
#include <linkedlist/singly.h>
#include <trees/binary_search_tree.h>
#include <stack/stack_array.h>
#include <stack/stack_ll.h>
#include <queue/circular_queue.h>

void display_list(SinglyLinkedList *list) {

    printf("\n");

    Array *arr = list->get_array(list);

    printf("List => ");
    for (int i = 0; i < arr->length; ++i) {
        printf("%d, ", arr->ptr[i]);
    }

    if (list->is_empty(list))
        return;

    printf("\nLength => %d", list->length);
    printf("\nHead => %d", list->head->data);
    printf("\nTail => %d", list->tail->data);

    printf("\n");
}

void display_stack(ArrayStack *stack) {

    Array *arr = stack->get_array(stack);

    if (arr == NULL) {
        printf("\n\nStack is empty");
        return;
    }

    printf("\n\n+----------------------------------------+");
    printf("\nStack => ");
    for (int i = 0; i < arr->length; ++i) {
        printf("%d, ", arr->ptr[i]);
    }

    printf("\nsize => %d", stack->size);
    printf("\ntop => %d", stack->arr[stack->top]);

    printf("\n+----------------------------------------+");
}

void singly_linked_list_sorting() {

    SinglyLinkedList *list = create_singly_linked_list();

    list->insert(list, 23);
    list->insert(list, 3);
    list->insert(list, 34);
    list->insert(list, 12);
    list->insert(list, 45);

    display_list(list);
    list->sort(list);
    display_list(list);
}

void singly_linked_list_find_nth_from_last() {

    SinglyLinkedList *list = create_singly_linked_list();

    list->insert(list, 23);
    list->insert(list, 3);
    list->insert(list, 34);
    list->insert(list, 12);
    list->insert(list, 45);
    list->insert(list, 76);
    list->insert(list, 65);
    list->insert(list, 43);

    display_list(list);


    int find_nth_from_last(SinglyLinkedList *l, int n) {

        SinglyLinkedListNode *p = l->head, *q = l->head;

        int count = n - 1;
        while (count--)
            q = q->next;

        while (q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        return p->data;
    }

    int n;
    printf("\nEnter n : ");
    scanf("%d", &n);
    printf("ANSWER => %d", find_nth_from_last(list, n));

}

void singly_linked_list_copy() {

    SinglyLinkedList *list = create_singly_linked_list();

    list->insert(list, 23);
    list->insert(list, 3);
    list->insert(list, 34);
    list->insert(list, 12);
    list->insert(list, 45);

    display_list(list);

    SinglyLinkedList *new_list = list->copy(list);

    list->remove_tail(list);

    display_list(new_list);

    display_list(list);

}

void singly_linked_list_remove_duplicates() {

    SinglyLinkedList *list = create_singly_linked_list();

    list->insert(list, 34);
    list->insert(list, 23);
    list->insert(list, 3);
    list->insert(list, 34);
    list->insert(list, 12);
    list->insert(list, 45);
    list->insert(list, 3);
    list->insert(list, 12);
    list->insert(list, 34);

    display_list(list);

    void remove_duplicates(SinglyLinkedList *l) {

        SinglyLinkedListNode *p, *q, *qprev;

        for (p = l->head; p != NULL; p = p->next) {

            qprev = p;
            q = qprev->next;

            while (q != NULL) {

                if (q->data == p->data) {

                    qprev->next = q->next;
                    free(q);
                    q = qprev->next;

                    if (q == NULL)
                        l->tail = qprev;

                    l->length -= 1;
                    continue;
                }

                qprev = q;
                q = q->next;
            }

        }

    }

    remove_duplicates(list);
    display_list(list);
}

void binary_search_tree_basics() {

    BinarySearchTree *tree = create_binary_search_tree();

    tree->insert(tree, 43);
    tree->insert(tree, 32);
    tree->insert(tree, 45);
    tree->insert(tree, 12);
    tree->insert(tree, 35);
    tree->insert(tree, 45);
    tree->insert(tree, 56);
    tree->insert(tree, 49);
    tree->insert(tree, 70);

//    tree->inorder(tree->root);
//    printf("\n");
//
//    tree->delete(tree, 49);
//    tree->inorder(tree->root);
//    printf("\n");
//
//    tree->delete(tree, 56);
//    tree->inorder(tree->root);
//    printf("\n");
//
//    tree->delete(tree, 43);
//    tree->inorder(tree->root);
//    printf("\n");

//    printf("%d", tree->exists(tree->root, 90));
//    printf("%d", tree->exists(tree->root, 98));
//    printf("%d", tree->exists(tree->root, 1));
//    printf("%d", tree->exists(tree->root, 21));

//    printf("min => %d, max => %d", tree->min(tree->root), tree->max(tree->root));

}

void stack_arrays() {

    ArrayStack *stack = create_array_stack(5);
    display_stack(stack);

    stack->push(stack, 12);
    stack->push(stack, 23);
    stack->push(stack, 34);
    stack->push(stack, 45);
    stack->push(stack, 56);

    display_stack(stack);

    printf("\n Peek => %d", stack->peek(stack));
    display_stack(stack);

    printf("\n Popped => %d", stack->pop(stack));
    display_stack(stack);

    printf("\n Popped => %d", stack->pop(stack));
    printf("\n Popped => %d", stack->pop(stack));
    printf("\n Popped => %d", stack->pop(stack));
    printf("\n Popped => %d", stack->pop(stack));
    display_stack(stack);

    stack->push(stack, 76);
    stack->push(stack, 87);
    stack->push(stack, 98);
    display_stack(stack);
}

void stack_ll() {

    void display(LLStack *stack) {

        Array *arr = stack->get_array(stack);

        if (arr == NULL) {
            printf("\n\nStack is empty");
            return;
        }

        printf("\n\n+----------------------------------------+");
        printf("\nStack => ");
        for (int i = 0; i < arr->length; ++i) {
            printf("%d, ", arr->ptr[i]);
        }

        printf("\nlength => %d", stack->size);
        printf("\nsize => %d", stack->allowed_size);
        printf("\ntop => %d", stack->head->data);

        printf("\n+----------------------------------------+");
    }

    LLStack *stack = create_stack_ll(5);
    display(stack);

    stack->push(stack, 12);
    stack->push(stack, 23);
    display(stack);

    printf("\nPeek => %d", stack->peek(stack));
    display(stack);

    printf("\nPopped => %d", stack->pop(stack));
    display(stack);

    stack->push(stack, 98);
    stack->push(stack, 87);
    stack->push(stack, 76);
    stack->push(stack, 65);
    display(stack);

    stack->push(stack, 21);
}

void circular_queue() {

    void display(CircularQueue *q) {

        if (q->is_empty(q)) {
            printf("\n\nQueue is empty");
            return;
        }

        printf("\n\n+----------------------------------------+");
        printf("\nQueue => ");

        for (int i = (q->front), len = q->length; len != 0; i = (i + 1) % (q->size), --len) {
            printf("%d, ", (q->ptr)[i]);
        }

        printf("\nlength => %d", q->length);
        printf("\nsize => %d", q->size);
        printf("\nfront => %d", (q->ptr)[q->front]);
        printf("\nrear => %d", (q->ptr)[q->rear]);

        printf("\n+----------------------------------------+");

    }

    CircularQueue *q = create_circular_queue(5);
    display(q);

    q->insert(q, 12);
    q->insert(q, 23);
    q->insert(q, 34);
    display(q);

    printf("\nDeleted = %d", q->delete(q));
    display(q);

    q->insert(q, 98);
    q->insert(q, 87);
    q->insert(q, 76);
    display(q);

    printf("\nDeleted = %d", q->delete(q));
    printf("\nDeleted = %d", q->delete(q));
    display(q);

    q->insert(q, 123);
    q->insert(q, 432);
    display(q);

    q->insert(q, 889);

}

int main() {

//    singly_linked_list_sorting();
//    singly_linked_list_find_nth_from_last();
//    singly_linked_list_copy();
//    singly_linked_list_remove_duplicates();
//    binary_search_tree_basics();
//    stack_arrays();
//    stack_ll();
    circular_queue();
    return 0;

}
