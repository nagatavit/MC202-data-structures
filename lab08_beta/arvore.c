#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

tree_node_p read_inorder(int size){
    tree_node_p new_node;

    if (size <= 0){
        return NULL;
    } else {
        new_node = malloc(sizeof * new_node);

        new_node->left = read_inorder(size/2);
        scanf("%d", &new_node->value);
        new_node->right = read_inorder(size/2);

        return new_node;
    }

}

void print_inorder(tree_node_p root){
    if (root != NULL){
        print_inorder(root->left);
        printf("%d", root->value);
        print_inorder(root->right);
    }
}

tree_node_p find_node(tree_node_p root, int x){
    if (root == NULL || root->value == x)
        return root;
    else if (root->value > x)
        return find_node(root->left, x);
    else
        return find_node(root->right, x);
}

tree_node_p minimum(tree_node_p root){
    if (root == NULL || root->left == NULL){
        return root;
    } else {
        return minimum(root->left);
    }
}

tree_node_p maximum(tree_node_p root){
    if (root == NULL || root->right == NULL){
        return root;
    } else {
        return minimum(root->right);
    }
}



void delete_tree(tree_node_p root){
    if (root != NULL){
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}
