/*
 * main.c
 *
 * Created on: 5/8/18
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#include <malloc.h>
#include <stack/stack_ll.h>

StackNode *stack_ll_create_node(int data) {

    StackNode *node = malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;

    return node;
}

Bool stack_ll_is_empty(LLStack *stack) {

    return (stack->head == NULL ? True : False);

}

Bool stack_ll_is_full(LLStack *stack) {

    return (stack->size == stack->allowed_size ? True : False);

}

void stack_ll_push(LLStack *stack, int data) {

    StackNode *node = stack->create_node(data);

    // return if stack is full
    if (stack->is_full(stack)) {
        printf("\nStack is full");
        return;
    }

    node->next = stack->head;
    stack->head = node;

    ++(stack->size);

}

int stack_ll_peek(LLStack *stack) {

    if (stack->is_empty(stack)) {
        printf("\nStack is empty !");
        return -1;
    }

    return stack->head->data;
}

int stack_ll_pop(LLStack *stack) {

    if (stack->is_empty(stack)) {
        printf("\nStack is empty !");
        return -1;
    }

    int tmp_data = stack->head->data;
    StackNode *tmp_node = stack->head;

    stack->head = stack->head->next;
    --(stack->size);

    free(tmp_node);

    return tmp_data;

}

Array *stack_ll_get_array(LLStack *stack) {

    if (stack->is_empty(stack))
        return NULL;

    Array *arr = malloc(sizeof(Array));
    arr->length = stack->size;
    arr->ptr = calloc((size_t) arr->length, sizeof(int));

    StackNode *p = stack->head;
    int *ptr = arr->ptr;
    while (p != NULL) {
        *(ptr++) = p->data;
        p = p->next;
    }

    return arr;
}

LLStack *create_stack_ll(int size) {

    LLStack *stack = malloc(sizeof(LLStack));

    // initialize members
    stack->head = NULL;
    stack->size = 0;
    stack->allowed_size = size;

    // initialize methods
    stack->create_node = &stack_ll_create_node;
    stack->is_full = &stack_ll_is_full;
    stack->is_empty = &stack_ll_is_empty;
    stack->push = &stack_ll_push;
    stack->peek = &stack_ll_peek;
    stack->pop = &stack_ll_pop;
    stack->get_array = &stack_ll_get_array;

    return stack;
}