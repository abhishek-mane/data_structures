/*
 * main.c
 *
 * Created on: 5/8/18
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#ifndef DATA_STRUCTURES_STACK_LL_H
#define DATA_STRUCTURES_STACK_LL_H

#include <utils.h>

typedef struct _stack_ll_node {
    int data;
    struct _stack_ll_node *next;
} StackNode;

typedef struct _stack_ll {

    // ========== vars ==========
    StackNode *head;
    int size;
    int allowed_size;

    // ========== methods ==========
    StackNode *(*create_node)(int);

    Bool (*is_full)(struct _stack_ll *);

    Bool (*is_empty)(struct _stack_ll *);

    void (*push)(struct _stack_ll *, int);

    Array *(*get_array)(struct _stack_ll *);

    int (*peek)(struct _stack_ll *);

    int (*pop)(struct _stack_ll *);

} LLStack;

LLStack *create_stack_ll(int);

#endif //DATA_STRUCTURES_STACK_LL_H
