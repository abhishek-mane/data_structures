//
// Created by abhishek on 13/7/18.
//

#ifndef DATA_STRUCTURES_DEQUEUE_H
#define DATA_STRUCTURES_DEQUEUE_H

#include <stdio.h>
#include "../../linkedlist/headers/doubly_list.h"

typedef struct _dequeue {
    DoublyLinkedList *queue;
} Dequeue;

Dequeue *dequeue_create();

void dequeue_push(Dequeue *,);

int dequeue_pop();

int dequeue_is_empty();

#endif //DATA_STRUCTURES_DQUEUE_H
