/*
 * stack.c
 *
 *  Created on: 20-Jul-2018
 *  Author: Abhishek Mane <https://abhishek-mane.github.io>
 */

#include <malloc.h>
#include <stack/stack.h>

StackNode *stack_create_node(int data) {

    StackNode *node = malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;

    return node;
}

Bool stack_is_empty(Stack *stack) {

    if (stack->length == 0)
        return True;

    return False;
}

Bool stack_is_full(Stack *stack) {

    if (stack->length == stack->size)
        return True;

    return False;

}

void stack_push(Stack *stack, int data) {

    StackNode *node = stack->create_node(data);

    // return if stack is full
    if (stack->is_full(stack))
        return;

    if (stack->top != NULL)
        node->next = stack->top;

    stack->top = node;

    stack->length += 1;

}

Array *stack_get_array(Stack *stack) {

    Array *arr = malloc(sizeof(Array));
    arr->length = stack->length;
    arr->ptr = malloc(arr->length * sizeof(int));

    StackNode *p = stack->top;
    int *a = arr->ptr;
    while (p != NULL) {
        *(a) = p->data;
        ++a;
        p = p->next;
    }

    return arr;

}

Stack *create_stack(int size) {

    Stack *stack = malloc(sizeof(Stack));

    // initialize members
    stack->top = NULL;
    stack->length = 0;
    stack->size = size;

    // initialize methods
    stack->create_node = &stack_create_node;
    stack->is_full = &stack_is_full;
    stack->is_empty = &stack_is_empty;
    stack->get_array = &stack_get_array;

    return stack;
}