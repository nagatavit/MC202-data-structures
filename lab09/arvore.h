/* ===========================================================================
 * MC202-E 1S2019 lab09
 * Vitor Nagata - RA 178499
 * FILE: arvore.h
 *
 * DESCRIPTION: interface of red-black tree
 *
 * DEPENDENDECIES: none
 *
 * RETURN VALUE: N/A
 *
 * ===========================================================================*/

#ifndef ARVORE_H_
#define ARVORE_H_

/* ===========================================================================
 * DATA TYPE: tree_node
 *
 * DESCRIPTION: node of a binary search tree
 *
 * PARAMETERS:
 * value = wait time of given process
 *
 * DEPENDENDECIES: none
 *
 * ===========================================================================*/

enum color {RED, BLACK};

typedef struct tree_node {
    int value;
    enum color color;
    struct tree_node *left, *right;
} tree_node;

typedef tree_node *tree_node_p;

tree_node_p create_tree();
tree_node_p insert_node(tree_node_p root, int value);
tree_node_p insert(tree_node_p root, int value);
int is_red(tree_node_p root);
int is_black(tree_node_p root);
tree_node_p rotate_right(tree_node_p root);
tree_node_p rotate_left(tree_node_p root);
void rise_red(tree_node_p root);
void print_inorder_inverse (tree_node_p root, int times);
void delete_tree(tree_node_p root);

#endif
