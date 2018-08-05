/*
 * main.c
 *
 * Created on: 5/8/18
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#include <stack/stack_array.h>
#include <malloc.h>

Bool stack_array_is_empty(ArrayStack *stack) {

    return (stack->top == -1 ? True : False);

}

Bool stack_array_is_full(ArrayStack *stack) {

    return (stack->top == (stack->size - 1) ? True : False);

}

void stack_array_push(ArrayStack *stack, int item) {

    if (stack->is_full(stack)) {
        printf("\nStack is full, cannot push");
        return;
    }

    ++stack->top;
    (stack->arr)[stack->top] = item;
}

int stack_array_pop(ArrayStack *stack) {

    if (stack->is_empty(stack)) {
        printf("\nStack is empty, cannot pop");
        return -1;
    }

    return (stack->arr)[(stack->top)--];

}

int stack_array_peek(ArrayStack *stack) {

    if (stack->is_empty(stack)) {
        printf("\nStack is empty !");
        return -1;
    }

    return (stack->arr)[stack->top];

}

Array *stack_array_get_array(ArrayStack *stack) {

    if (stack->is_empty(stack))
        return NULL;

    Array *arr = malloc(sizeof(Array));
    arr->length = stack->top + 1;
    arr->ptr = calloc((size_t) arr->length, sizeof(int));

    for (register int i = 0; i < arr->length; ++i) {
        arr->ptr[i] = stack->arr[i];
    }

    return arr;

}

ArrayStack *create_array_stack(unsigned int size) {

    if (size < 0) {
        printf("\nStack size cannot be a negative value");
        return NULL;
    }

    ArrayStack *stack = malloc(sizeof(ArrayStack));

    stack->arr = calloc(size, sizeof(int));
    stack->top = -1;
    stack->size = size;

    // methods
    stack->push = &stack_array_push;
    stack->pop = &stack_array_pop;
    stack->peek = &stack_array_peek;
    stack->is_empty = &stack_array_is_empty;
    stack->is_full = &stack_array_is_full;
    stack->get_array = &stack_array_get_array;
}