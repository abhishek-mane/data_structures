/*
 * stack.h
 *
 *  Created on: 20-Jul-2018
 *  Author: Abhishek Mane <https://abhishek-mane.github.io>
 */

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <utils.h>

typedef struct _stack_node {
    int data;
    struct _stack_node *next;
} StackNode;

typedef struct _stack {

    // ========== vars ==========
    StackNode *head;
    int length;
    int size;

    // ========== methods ==========
    StackNode *(*create_node)(int);

    Bool (*is_full)(struct _stack *);

    Bool (*is_empty)(struct _stack *);

    void (*push)(struct _stack *, int);

    Array *(*get_array)(struct _stack *);

    int (*top)(struct _stack *);

    int (*pop)(struct _stack *);

} Stack;

Stack *create_stack(int);

#endif //DATA_STRUCTURES_STACK_H
