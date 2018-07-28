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

    return (stack->length == 0 ? True : False);

}

Bool stack_is_full(Stack *stack) {

    return (stack->length == stack->size ? True : False);

}

void stack_push(Stack *stack, int data) {

    StackNode *node = stack->create_node(data);

    // return if stack is full
    if (stack->is_full(stack))
        return;

    if (stack->head != NULL)
        node->next = stack->head;

    stack->head = node;

    stack->length += 1;

}

Array *stack_get_array(Stack *stack) {

    Array *arr = malloc(sizeof(Array));
    arr->length = stack->length;
    arr->ptr = malloc(arr->length * sizeof(int));

    StackNode *p = stack->head;
    int *ptr = arr->ptr;
    while (p != NULL) {
        *(ptr++) = p->data;
        p = p->next;
    }

    return arr;

}

int stack_top(Stack *stack) {

    return (stack->is_empty(stack) ? False : stack->head->data);

}

int stack_pop(Stack *stack) {

    if (stack->is_empty(stack)) {
        return False;
    }

    int temp = stack->head->data;
    stack->head = stack->head->next;
    stack->length -= 1;

    return temp;

}

Stack *create_stack(int size) {

    Stack *stack = malloc(sizeof(Stack));

    // initialize members
    stack->head = NULL;
    stack->length = 0;
    stack->size = size;

    // initialize methods
    stack->create_node = &stack_create_node;
    stack->push = &stack_push;
    stack->is_full = &stack_is_full;
    stack->is_empty = &stack_is_empty;
    stack->top = &stack_top;
    stack->get_array = &stack_get_array;
    stack->pop = &stack_pop;

    return stack;
}