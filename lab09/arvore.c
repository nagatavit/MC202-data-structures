#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

tree_node_p create_node(){
    tree_node_p new_node = malloc(sizeof * new_node);

    /* not possible to allocate memory */
    if (new_node == NULL)
        return NULL;

    /* initialize all parameters as zero */
    new_node->ship_id = 0;
    new_node->strikes = 0;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

tree_node_p read_inorder(int size){
    tree_node_p new_node;

    if (size <= 0){
        /* base case: NULL leaf */
        return NULL;
    } else {
        /* general case:
         * read left subtree
         * read current node
         * read right subtree
         */
        new_node = create_node();

        new_node->left = read_inorder(size/2);
        scanf("%d", &new_node->ship_id);
        new_node->right = read_inorder(size/2);

        return new_node;
    }

}


void print_preorder(tree_node_p root){
    /* base case: NULL - do nothing*/

    /* general case: prints preorder*/
    if (root != NULL){
        printf("%d %d\n", root->ship_id, root->strikes);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

tree_node_p find_node(tree_node_p root, int x){
    /* base case: node found*/
    if (root == NULL || root->ship_id == x)
        return root;
    /*general cases: search in the subtrees*/
    else if (root->ship_id > x)
        return find_node(root->left, x);
    else
        return find_node(root->right, x);
}

void strike_ship(tree_node_p root, int x){
    tree_node_p striked_node;
    /* find the damaged nodes*/
    striked_node = find_node(root, x);
    /* adds to the counter of damages*/
    striked_node->strikes++;
}

void delete_tree(tree_node_p root){
    /* base case: do nothing*/

    /* general case: deletes subtrees and delete root*/
    if (root != NULL){
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}
