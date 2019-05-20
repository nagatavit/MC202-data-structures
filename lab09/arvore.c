#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

tree_node_p create_tree(){
    return NULL;
}

int is_red(tree_node_p root){
    if (root == NULL)
        return 0;
    return root->color == RED;
}

int is_black(tree_node_p root){
    if (root == NULL)
        return 1;
    return root->color == BLACK;
}

tree_node_p rotate_left(tree_node_p root){
    tree_node_p x = root->right;

    root->right = x->left;
    x->left = root;
    x->color = root->color;
    root->color = RED;
    return x;
}

tree_node_p rotate_right(tree_node_p root){
    tree_node_p x = root->left;

    root->left = x->right;
    x->right = root;
    x->color = root->color;
    root->color = RED;
    return x;
}

void rise_red(tree_node_p root){
    root->color = RED;
    root->left->color = BLACK;
    root->right->color = BLACK;
}

tree_node_p insert_node(tree_node_p root, int value){
    tree_node_p new_node;

    /* tree is null, insert new node here */
    if (root == NULL){
        new_node = malloc(sizeof * new_node);
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->value = value;
        new_node->color = RED;
        return new_node;
    } else if (root->value > value) {
    /* root is bigger than value, insert to the left */
        root->left = insert_node(root->left, value);
    } else {
    /* root is less than value, insert to the right */
        root->right = insert_node(root->right, value);
    }

    /* Correct the colors, except for the root */

    /* only rightchild is red */
    if (is_red(root->right) && is_black(root->left))
        root = rotate_left(root);

    /* left child is red and his left child is also red*/
    if (is_red(root->left) && is_red(root->left->left))
        root = rotate_right(root);

    /* both childs are red */
    if (is_red(root->left) && is_red(root->right))
        rise_red(root);

    return root;

}

tree_node_p insert(tree_node_p root, int value){
    root = insert_node(root, value);
    root->color = BLACK;
    return root;
}

void print_inorder_inverse(tree_node_p root, int processors){
    static int times_printed = 0;
    /* base case: NULL - do nothing*/

    /* general case: prints preorder*/
    if (root != NULL){
        print_inorder_inverse(root->right, processors);

        /* prints only the amount of processors running */
        if (times_printed < processors){
            printf("%d\n", root->value);
            times_printed++;
        }

        print_inorder_inverse(root->left, processors);
    }
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
