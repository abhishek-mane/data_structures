/*
 * singly.c
 *
 * Created on: 15-Jul-2018
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#include <stdlib.h>
#include <utils.h>
#include <linkedlist/singly.h>

SinglyLinkedListNode *create_singly_ll_node(int data) {

    SinglyLinkedListNode *node = malloc(sizeof(SinglyLinkedListNode));

    node->data = data;
    node->next = NULL;

    return node;
}

Bool singly_ll_is_empty(SinglyLinkedList *list) {
    return (list->head == NULL ? True : False);
}

void singly_ll_insert_node_at_head(SinglyLinkedList *list, int data) {

    SinglyLinkedListNode *node = list->create_node(data);

    if (list->is_empty(list)) {
        list->tail = node;
    } else {
        node->next = list->head;
    }

    list->head = node;

    list->length += 1;
}

void singly_ll_insert_node_at_tail(SinglyLinkedList *list, int data) {

    SinglyLinkedListNode *node = list->create_node(data);

    if (list->is_empty(list)) {
        list->head = node;
    } else {
        list->tail->next = node;
    }

    list->tail = node;

    list->length += 1;
}

void singly_ll_insert(SinglyLinkedList *list, int data) {
    list->insert_at_tail(list, data);
}

void singly_ll_remove_head(SinglyLinkedList *list) {

    if (list->is_empty(list))
        return;

    // delete head
    SinglyLinkedListNode *tmp = list->head;
    list->head = list->head->next;
    free(tmp);

    // decrement length
    list->length -= 1;
}

void singly_ll_remove_tail(SinglyLinkedList *list) {

    if (list->is_empty(list))
        return;

    // get 2nd last pos
    SinglyLinkedListNode *p, *tmp;
    for (p = list->head; p->next != list->tail; p = p->next) {}

    tmp = list->tail;
    list->tail = p;
    list->tail->next = NULL;
    free(tmp);

    // decrement length
    list->length -= 1;
}

void singly_ll_remove(SinglyLinkedList *list, int data) {

    if (list->is_empty(list))
        return;

    if (list->head->data == data) {
        list->remove_head(list);
        return;
    }

    if (list->tail->data == data) {
        list->remove_tail(list);
        return;
    }

    // find prev of the node to be deleted
    SinglyLinkedListNode *p = list->head;
    while (p->next != NULL) {
        if (p->next->data == data)
            break;
        p = p->next;
    }

    // if not found
    if (p->next == NULL)
        return;

    // delete p->next
    SinglyLinkedListNode *tmp = p->next;
    p->next = p->next->next;
    free(tmp);

    // decrement length
    list->length -= 1;
}

void singly_ll_reverse(SinglyLinkedList *list) {

    if (list->is_empty(list))
        return;

    // update head
    list->tail = list->head;

    // reverse linked list
    SinglyLinkedListNode *p = list->head, *prev_node = NULL, *next_node = NULL;
    while (p != NULL) {
        next_node = p->next;
        p->next = prev_node;
        prev_node = p;
        p = next_node;
    }

    // update head
    list->head = prev_node;

}

SinglyLinkedList *singly_ll_copy(SinglyLinkedList *list) {

    SinglyLinkedList *new_list = create_singly_linked_list();

    if (list->is_empty(list))
        return new_list;

    SinglyLinkedListNode *p = list->head;
    while (p != NULL) {
        new_list->insert(new_list, p->data);
        p = p->next;
    }

    return new_list;
}

void singly_ll_sort(SinglyLinkedList *list) {

    if (list->is_empty(list))
        return;

    SinglyLinkedListNode *p, *pprev, *q, *qprev, *min, *minprev, *temp = NULL;

    for (pprev = NULL, p = list->head; p != NULL;) {

        for (qprev = p, q = qprev->next, min = p, minprev = pprev; q != NULL; qprev = q, q = q->next) {

            if (q->data < p->data) {
                min = q;
                minprev = qprev;
            }
        }

        // found min in min, now swap with p
        if (p == min) {
            pprev = p;
            p = p->next;
            continue;
        }

        temp = p->next;
        p->next = min->next;
        min->next = temp;

        minprev->next = p;

        if (pprev == NULL) {
            list->head = min;
            continue;
        }
        pprev->next = min;

        // move ahead
        pprev = min;
        p = pprev->next;
    }

}

void singly_ll_destroy(SinglyLinkedList *list) {

    SinglyLinkedListNode *p = list->head, *tmp;

    // delete all nodes 1 by 1
    while (p != NULL) {
        tmp = p;
        p = p->next;
        free(tmp);
    }

    // initialize metadata
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

Array *singly_ll_get_array(SinglyLinkedList *list) {

    Array *arr = malloc(sizeof(Array));
    arr->ptr = calloc(sizeof(int), (size_t) list->length);
    arr->length = list->length;

    int i = 0;
    SinglyLinkedListNode *p = list->head;
    while (p != NULL) {
        (arr->ptr)[i++] = p->data;
        p = p->next;
    }

    return arr;
}

SinglyLinkedList *singly_ll_set_union(SinglyLinkedList *list1, SinglyLinkedList *list2) {


}

SinglyLinkedList *singly_ll_set_intersection(SinglyLinkedList *list1, SinglyLinkedList *list2) {

}

void singly_ll_remove_duplicates(SinglyLinkedList *list) {}

SinglyLinkedList *create_singly_linked_list() {

    SinglyLinkedList *list = malloc(sizeof(SinglyLinkedList));

    // members
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    // methods
    list->create_node = &create_singly_ll_node;
    list->is_empty = &singly_ll_is_empty;
    list->insert_at_head = &singly_ll_insert_node_at_head;
    list->insert_at_tail = &singly_ll_insert_node_at_tail;
    list->insert = &singly_ll_insert;
    list->get_array = &singly_ll_get_array;
    list->remove = &singly_ll_remove;
    list->remove_head = &singly_ll_remove_head;
    list->remove_tail = &singly_ll_remove_tail;
    list->reverse = &singly_ll_reverse;
    list->destroy = &singly_ll_destroy;
    list->sort = &singly_ll_sort;
    list->copy = &singly_ll_copy;
    list->set_union = &singly_ll_set_union;
    list->set_intersection = &singly_ll_set_intersection;
    list->remove_duplicates = &singly_ll_remove_duplicates;

    return list;
}
