#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    tree_node_p tree;
    int m, p, i, value;

    tree = create_tree();

    scanf("%d", &m);
    for (i = 0; i < m; i++){
        scanf("%d", &value);
        tree = insert(tree, value);
    }
    scanf("%d", &p);

    print_inorder_inverse(tree, p);
    delete_tree(tree);
}
