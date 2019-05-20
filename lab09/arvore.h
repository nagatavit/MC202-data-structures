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
 * ===========================================================================*/

enum color {RED, BLACK};

typedef struct tree_node {
    int value;
    enum color color;
    struct tree_node *left, *right;
} tree_node;

typedef tree_node *tree_node_p;

/* ===========================================================================
 * FUNCTION: create_tree
 *
 * DESCRIPTION: creates a NULL tree
 *
 * PARAMETERS: none
 *
 * DEPENDENDECIES: none
 *
 * RETURN VALUE: tree root node
 * ===========================================================================*/


tree_node_p create_tree();

/* ===========================================================================
 * FUNCTION: is_red
 *
 * DESCRIPTION: checks if given node is red
 *
 * PARAMETERS: tree node
 *
 * DEPENDENDECIES: none
 *
 * RETURN VALUE: none
 *
 * ===========================================================================*/

int is_red(tree_node_p root);

/* ===========================================================================
 * FUNCTION: is_black
 *
 * DESCRIPTION: checks if given node is black
 *
 * PARAMETERS: tree node
 *
 * DEPENDENDECIES: none
 *
 * RETURN VALUE: none
 *
 * ===========================================================================*/

int is_black(tree_node_p root);

/* ===========================================================================
 * FUNCTION: rotate_right
 *
 * DESCRIPTION: rotate node to the right and correct colors
 *
 * PARAMETERS: root = node to be rotate
 *
 * DEPENDENDECIES: none
 *
 * RETURN VALUE: new tree after rotation
 *
 * ===========================================================================*/
tree_node_p rotate_right(tree_node_p root);

/* ===========================================================================
 * FUNCTION: rotate_left
 *
 * DESCRIPTION: rotate node to the left and correct colors
 *
 * PARAMETERS: root = node to be rotate
 *
 * DEPENDENDECIES: none
 *
 * RETURN VALUE: new tree after rotation
 *
 * ===========================================================================*/

tree_node_p rotate_left(tree_node_p root);

/* ===========================================================================
 * FUNCTION: rise_red
 *
 * DESCRIPTION: if both childs are red, make them black and make parent
 * red
 *
 * PARAMETERS:
 * root = parent node
 *
 * DEPENDENDECIES: none
 *
 * RETURN VALUE: none
 *
 * ===========================================================================*/

void rise_red(tree_node_p root);

/* ===========================================================================
 * FUNCTION: insert_node
 *
 * DESCRIPTION: function to be called by insert. Inserts recursivly
 * mantaining the properties of red-black tree, except the root
 * being black.
 *
 * PARAMETERS:
 * root = root node of the tree
 * value = value to be inserted
 *
 * DEPENDENDECIES: none
 *
 * RETURN VALUE: new tree with new node inserted
 *
 * ===========================================================================*/

tree_node_p insert_node(tree_node_p root, int value);

/* ===========================================================================
 * FUNCTION: insert
 *
 * DESCRIPTION: inserts a new node on the tree calling insert_node.
 * By the end of insert_node, corrects the root being a black node.
 *
 * PARAMETERS:
 * root = root node of the tree
 * value = value to be inserted
 *
 * DEPENDENDECIES: insert_node
 *
 * RETURN VALUE: new tree with new node inserted
 *
 * ===========================================================================*/

tree_node_p insert(tree_node_p root, int value);

/* ===========================================================================
 * FUNCTION: print_inorder_inverse
 *
 * DESCRIPTION: prints in an inverse of inorder order. But print only
 * the number of processes that are running
 *
 * PARAMETERS:
 * root = root node of the tree
 * times = number of processes that are going to be printed
 *
 * DEPENDENDECIES: none
 *
 * RETURN VALUE: none
 *
 * ===========================================================================*/

void print_inorder_inverse(tree_node_p root, int times);

/* ===========================================================================
 * FUNCTION: delete_tree
 *
 * DESCRIPTION: deletes a tree
 *
 * PARAMETERS: root = root node of the tree to be deleted
 *
 * DEPENDENDECIES: none
 *
 * RETURN VALUE: none
 *
 * ===========================================================================*/

void delete_tree(tree_node_p root);

#endif
