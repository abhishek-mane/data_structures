/*
 * main.c
 *
 * Created on: 5/8/18
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#ifndef DATA_STRUCTURES_CIRCULAR_QUEUE_H
#define DATA_STRUCTURES_CIRCULAR_QUEUE_H

#include <utils.h>

typedef struct _circular_queue {

    // members
    int *ptr;
    int front;
    int rear;
    int length; // denotes current size of queue
    int size;   // denotes allowable size of queue

    // methods
    void (*insert)(struct _circular_queue *, int);

    int (*delete)(struct _circular_queue *);

    int (*peek)(struct _circular_queue *);

    Bool (*is_empty)(struct _circular_queue *);

    Bool (*is_full)(struct _circular_queue *);

} CircularQueue;

CircularQueue *create_circular_queue(unsigned int);

#endif //DATA_STRUCTURES_CIRCULAR_QUEUE_H
