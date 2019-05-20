/* ===========================================================================
 * MC202-E 1S2019 lab09
 * Vitor Nagata - RA 178499
 * FUNCTION: lab09.c
 *
 * DESCRIPTION: implements a processor scheduller based on a red-black tree
 *
 * RETURN VALUE: 0 if successful
 * ===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    tree_node_p tree;
    int m, p, i, value;

    /* creates the tree */
    tree = create_tree();

    /* read the number of processes */
    scanf("%d", &m);

    /* insert values to the tree */
    for (i = 0; i < m; i++){
        scanf("%d", &value);
        tree = insert(tree, value);
    }

    /* reads the number of processors running */
    scanf("%d", &p);

    /* prints the p processes with most wait time */
    print_inorder_inverse(tree, p);

    /* deletes the tree */
    delete_tree(tree);

    return 0;
}
