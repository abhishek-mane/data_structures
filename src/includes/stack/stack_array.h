/*
 * main.c
 *
 * Created on: 5/8/18
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#ifndef DATA_STRUCTURES_STACK_ARRAY_H
#define DATA_STRUCTURES_STACK_ARRAY_H

#include <utils.h>

typedef struct _array_stack {

    int *arr;
    int top;
    unsigned int size;

    // methods
    void (*push)(struct _array_stack *, int);

    int (*pop)(struct _array_stack *);

    int (*peek)(struct _array_stack *);

    Bool (*is_empty)(struct _array_stack *);

    Bool (*is_full)(struct _array_stack *);

    Array *(*get_array)(struct _array_stack *);

} ArrayStack;

ArrayStack *create_array_stack(unsigned int);

#endif //DATA_STRUCTURES_STACK_ARRAY_H
