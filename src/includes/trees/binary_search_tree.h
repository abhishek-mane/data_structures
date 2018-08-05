/*
 * main.c
 *
 * Created on: 1/8/18
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#ifndef DATA_STRUCTURES_BINARY_SEARCH_TREE_H
#define DATA_STRUCTURES_BINARY_SEARCH_TREE_H

#include <utils.h>

typedef struct _binary_search_tree_node {

    struct _binary_search_tree_node *left;
    int data;
    struct _binary_search_tree_node *right;

} BinarySearchTreeNode;

typedef struct _binary_search_tree {

    BinarySearchTreeNode *root;

    // Methods

    BinarySearchTreeNode *(*create_node)(int data);

    Bool (*isempty)(struct _binary_search_tree *);

    void (*inorder)(BinarySearchTreeNode *);

    void (*insert)(struct _binary_search_tree *, int data);

    Bool (*exists)(BinarySearchTreeNode *, int);

    int (*min)(BinarySearchTreeNode *);

    int (*max)(BinarySearchTreeNode *);

    void (*delete)(struct _binary_search_tree *, int);

    BinarySearchTreeNode *(*search)(struct _binary_search_tree *, int);

    void (*delete_node_having_no_child)(struct _binary_search_tree *, BinarySearchTreeNode *, BinarySearchTreeNode *);

    void (*delete_node_having_one_child)(struct _binary_search_tree *, BinarySearchTreeNode *, BinarySearchTreeNode *);

    void (*delete_node_having_two_child)(struct _binary_search_tree *, BinarySearchTreeNode *, BinarySearchTreeNode *);

} BinarySearchTree;

BinarySearchTree *create_binary_search_tree();

#endif //DATA_STRUCTURES_BINARY_SEARCH_TREE_H
