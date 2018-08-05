/*
 * main.c
 *
 * Created on: 5/8/18
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#include <queue/circular_queue.h>
#include <malloc.h>

Bool circular_queue_is_empty(CircularQueue *q) {
    return (q->length == 0 ? True : False);
}

Bool circular_queue_is_full(CircularQueue *q) {
    return (q->length == q->size ? True : False);
}

void circular_queue_insert(CircularQueue *q, int item) {

    if (q->is_full(q)) {
        printf("\nQueue is full, cannot insert");
        return;
    }

    if (q->rear == -1)
        q->front = 0;

    q->rear = (q->rear + 1) % (q->size);
    (q->ptr)[q->rear] = item;
    ++q->length;
}

int circular_queue_peek(CircularQueue *q) {

    if (q->is_empty(q)) {
        printf("\nQueue is empty !");
        return -1;
    }

    return (q->ptr)[q->front];

}

int circular_queue_delete(CircularQueue *q) {

    if (q->is_empty(q)) {
        printf("Queue is empty !");
        return -1;
    }

    int tmp = (q->ptr)[q->front];

    // delete logic
    q->front = (q->front + 1) % (q->size);
    --(q->length);

    return tmp;
}

void circular_queue_display(CircularQueue *q) {

    printf("\n\n+---------------------------------+");
    printf("\n| Elements\t\t=> ");

    for (int i = (q->front), len = q->length; len != 0; i = (i + 1) % (q->size), --len) {
        printf("%d, ", (q->ptr)[i]);
    }

    printf("\n| Length\t\t=> %d", q->length);
    printf("\n| Size\t\t\t=> %d", q->size);
    printf("\n| Front Element => %d", (q->ptr)[q->front]);
    printf("\n| Rear Element\t=> %d", (q->ptr)[q->rear]);

    printf("\n+---------------------------------+");

}

CircularQueue *create_circular_queue(unsigned int size) {

    // allocate
    CircularQueue *q = malloc(sizeof(CircularQueue));

    // members
    q->ptr = calloc(size, sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->length = 0;
    q->size = size;

    // methods
    q->is_empty = &circular_queue_is_empty;
    q->is_full = &circular_queue_is_full;
    q->insert = &circular_queue_insert;
    q->delete = &circular_queue_delete;
    q->peek = &circular_queue_peek;
    q->display = &circular_queue_display;
}