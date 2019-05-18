/* ===========================================================================
 * MC202-E 1S2019 lab
 * Vitor Nagata - RA 178499
 * FUNCTION: arvore.h
 *
 * DESCRIPTION: interface of binary search tree
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
 * ship_id: id related to each ship
 * strikes: number of strikes of the ship
 *
 * DEPENDENDECIES: none
 *
 * ===========================================================================*/

typedef struct tree_node {
    int ship_id, strikes;
    struct tree_node *left, *right;
} tree_node;

typedef tree_node *tree_node_p;

/* ===========================================================================
 * FUNCTION: create_node
 *
 * DESCRIPTION: creates a new node with all filds set to 0 / NULL
 *
 * PARAMETERS: none
 *
 * DEPENDENDECIES: none
 *
 * RETURN VALUE:
 * created node - if successfull
 * NULL - if not possible to allocate memory
 *
 * ===========================================================================*/
tree_node_p create_node();

/* ===========================================================================
 * FUNCTION: read_inorder
 *
 * DESCRIPTION: read input and stores them in inorder sequence
 *
 * PARAMETERS: size - number of nodes of the tree
 *
 * DEPENDENDECIES: create_node
 *
 * RETURN VALUE: binary search tree root node
 *
 * ===========================================================================*/
tree_node_p read_inorder(int size);

/* ===========================================================================
 * FUNCTION: print_preorder
 *
 * DESCRIPTION: prints a tree in preorder sequence
 *
 * PARAMETERS: root - root node a binary tree
 *
 * DEPENDENDECIES: printf
 *
 * RETURN VALUE: none
 *
 * ===========================================================================*/
void print_preorder(tree_node_p root);

/* ===========================================================================
 * FUNCTION: find_node
 *
 * DESCRIPTION: giiven the ship_id, find the node corresponding to the ID
 *
 * PARAMETERS:
 * root - root node of the tree
 * x - ship_id (key of the search)
 *
 * DEPENDENDECIES: none
 *
 * RETURN VALUE: node with the respective ship_id
 *
 * ===========================================================================*/

tree_node_p find_node(tree_node_p root, int x);

/* ===========================================================================
 * FUNCTION: strike_ship
 *
 * DESCRIPTION: adds to the counter of damaged ship
 *
 * PARAMETERS:
 * root - root node of the tree
 * x - ship striked by an attack
 *
 * DEPENDENDECIES: find_node
 *
 * RETURN VALUE: none
 *
 * ===========================================================================*/

void strike_ship(tree_node_p root, int x);

/* ===========================================================================
 * FUNCTION: delete_tree
 *
 * DESCRIPTION: deletes a binary search tree
 *
 * PARAMETERS: root node of the tree
 *
 * DEPENDENDECIES: free
 *
 * RETURN VALUE: none
 *
 * ===========================================================================*/

void delete_tree(tree_node_p root);

#endif
