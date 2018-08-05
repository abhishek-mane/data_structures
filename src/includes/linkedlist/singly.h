/*
 * singly.h
 *
 * Created on: 15-Jul-2018
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#ifndef LIB_HEADERS_LINKEDLIST_SINGLY_H_
#define LIB_HEADERS_LINKEDLIST_SINGLY_H_

#include <stdio.h>
#include <utils.h>

typedef struct _node {
    int data;
    struct _node *next;
} SinglyLinkedListNode;

typedef struct _singly_linked_list {

    // ========== vars ==========
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;
    int length;

    // ========== methods ==========
    SinglyLinkedListNode *(*create_node)(int);

    void (*insert_at_head)(struct _singly_linked_list *, int);

    void (*insert_at_tail)(struct _singly_linked_list *, int);

    void (*insert)(struct _singly_linked_list *, int);

    Bool (*is_empty)(struct _singly_linked_list *);

    Array *(*get_array)(struct _singly_linked_list *);

    void (*remove)(struct _singly_linked_list *, int);

    void (*remove_head)(struct _singly_linked_list *);

    void (*remove_tail)(struct _singly_linked_list *);

    void (*reverse)(struct _singly_linked_list *);

    void (*sort)(struct _singly_linked_list *);

    void (*destroy)(struct _singly_linked_list *);

    struct _singly_linked_list *(*copy)(struct _singly_linked_list *);

    struct _singly_linked_list *(*set_intersection)(struct _singly_linked_list *, struct _singly_linked_list *);

    struct _singly_linked_list *(*set_union)(struct _singly_linked_list *, struct _singly_linked_list *);

    void (*remove_duplicates)(struct _singly_linked_list *);

} SinglyLinkedList;

SinglyLinkedList *create_singly_linked_list();

#endif /* LIB_HEADERS_LINKEDLIST_SINGLY_H_ */
