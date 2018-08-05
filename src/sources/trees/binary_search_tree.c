/*
 * main.c
 *
 * Created on: 1/8/18
 * Author: Abhishek Mane <https://abhishek-mane.github.io>
 *
 */

#include <malloc.h>
#include <trees/binary_search_tree.h>

Bool binary_search_tree_isempty(BinarySearchTree *tree) {

    return (tree->root == NULL ? True : False);

}

void binary_search_tree_inorder(BinarySearchTreeNode *root) {

    if (root == NULL)
        return;

    binary_search_tree_inorder(root->left);
    printf("%d, ", root->data);
    binary_search_tree_inorder(root->right);

}

BinarySearchTreeNode *binary_search_tree_create_node(int data) {

    BinarySearchTreeNode *node = malloc(sizeof(BinarySearchTreeNode));
    node->left = NULL;
    node->right = NULL;
    node->data = data;

    return node;

}

void binary_search_tree_insert(BinarySearchTree *tree, int data) {

    BinarySearchTreeNode *node = tree->create_node(data);

    if (tree->isempty(tree)) {
        tree->root = node;
        return;
    }

    BinarySearchTreeNode *p = tree->root, *parent = NULL;

    while (p != NULL) {

        parent = p;

        if (data < p->data)
            p = p->left;
        else if (data > p->data)
            p = p->right;
        else                // if equal
            return;

    }

    if (data < parent->data)
        parent->left = node;
    else
        parent->right = node;

}

Bool binary_search_tree_exists(BinarySearchTreeNode *root, int data) {

    if (root == NULL)
        return False;

    if (root->data == data)
        return True;

    if (data < root->data)
        binary_search_tree_exists(root->left, data);
    else
        binary_search_tree_exists(root->right, data);

}

int binary_search_tree_min(BinarySearchTreeNode *root) {

    if (root->left == NULL)
        return root->data;

    return binary_search_tree_min(root->left);

}

int binary_search_tree_max(BinarySearchTreeNode *root) {

    if (root->right == NULL)
        return root->data;

    return binary_search_tree_max(root->right);

}

BinarySearchTreeNode *binary_sarch_tree_search(BinarySearchTree *tree, int data) {

    BinarySearchTreeNode *p = tree->root;

    while (p != NULL) {

        if (data == p->data)
            return p;
        else if (data < p->data)
            p = p->left;
        else
            p = p->right;

    }

    return NULL;
}

void binary_sarch_tree_delete_node_having_no_child(BinarySearchTree *tree, BinarySearchTreeNode *ptr,
                                                   BinarySearchTreeNode *parent) {

    if (parent == NULL)
        tree->root = NULL;
    else if (ptr == parent->left)
        parent->left = NULL;
    else
        parent->right = NULL;

    free(ptr);
}

void binary_sarch_tree_delete_node_having_one_child(BinarySearchTree *tree, BinarySearchTreeNode *ptr,
                                                    BinarySearchTreeNode *parent) {

    BinarySearchTreeNode *node = (ptr->left != NULL ? ptr->left : ptr->right);

    if (parent == NULL)
        tree->root = node;
    else if (ptr == parent->left)
        parent->left = node;
    else
        parent->right = node;

    free(ptr);
}

void binary_sarch_tree_delete_node_having_two_child(BinarySearchTree *tree, BinarySearchTreeNode *ptr,
                                                    BinarySearchTreeNode *parent) {


    BinarySearchTreeNode *inorder_successor = ptr->right, *inorder_successor_parent = ptr;

    // find inorder successor of ptr
    while (inorder_successor->left != NULL) {
        inorder_successor_parent = inorder_successor;
        inorder_successor = inorder_successor->left;
    }

    // copy node info
    ptr->data = inorder_successor->data;

    if (inorder_successor->right != NULL)
        tree->delete_node_having_one_child(tree, inorder_successor, inorder_successor_parent);
    else
        tree->delete_node_having_no_child(tree, inorder_successor, inorder_successor_parent);

}

void binary_sarch_tree_delete(BinarySearchTree *tree, int data) {

    if (tree->isempty(tree))
        return;

    BinarySearchTreeNode *ptr = tree->root, *parent = NULL;

    while (ptr != NULL) {

        // node to be delete found
        if (ptr->data == data) {
            if (ptr->left == NULL && ptr->right == NULL)
                tree->delete_node_having_no_child(tree, ptr, parent);
            else if (ptr->left != NULL && ptr->right != NULL)
                tree->delete_node_having_two_child(tree, ptr, parent);
            else
                tree->delete_node_having_one_child(tree, ptr, parent);
        }

        parent = ptr;

        if (data < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

}


BinarySearchTree *create_binary_search_tree() {

    BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
    tree->root = NULL;

    tree->create_node = &binary_search_tree_create_node;
    tree->insert = &binary_search_tree_insert;
    tree->isempty = &binary_search_tree_isempty;
    tree->inorder = &binary_search_tree_inorder;
    tree->exists = &binary_search_tree_exists;
    tree->min = &binary_search_tree_min;
    tree->max = &binary_search_tree_max;
    tree->delete = &binary_sarch_tree_delete;
    tree->delete_node_having_one_child = &binary_sarch_tree_delete_node_having_one_child;
    tree->delete_node_having_two_child = &binary_sarch_tree_delete_node_having_two_child;
    tree->delete_node_having_no_child = &binary_sarch_tree_delete_node_having_no_child;
    tree->search = &binary_sarch_tree_search;
}