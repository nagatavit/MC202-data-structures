#ifndef ARVORE_H_
#define ARVORE_H_

typedef struct tree_node {
    int value;
    struct tree_node *left, *right;
} tree_node;

typedef tree_node *tree_node_p;


tree_node_p create_tree();
tree_node_p create_node(int x);
tree_node_p insert_inorder(int value, tree_node_p left, tree_node_p right);
tree_node_p delete_node(tree_node_p root, int x);



#endif
