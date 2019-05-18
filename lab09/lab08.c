/* ===========================================================================
 * MC202-E 1S2019 lab08 - Arvores Binarias de Busca
 * Vitor Nagata - RA 178499
 * FUNCTION: lab08.c
 *
 * DESCRIPTION: Given a sorted input of ships ID, and the ships that have
 * been striked, prints the score of all pilots in preorder formation
 *
 * RETURN VALUE: 0 if successful
 *
 * ===========================================================================*/

#include <stdio.h>
#include "arvore.h"

int main(){
    tree_node_p ship_squad;
    int squad_size, strikes_count, striked_ship;
    int i;

    /* reads the number of ships in the squad */
    scanf("%d", &squad_size);

    /* reads the ships ID and stores in
     * a bst in inorder sequence
     */
    ship_squad = read_inorder(squad_size);

    /* reads the number of striked ships */
    scanf("%d", &strikes_count);

    /*
     * adds to the counter of each striked ship
     */
    for (i = 0; i < strikes_count; i++){
        scanf("%d", &striked_ship);
        strike_ship(ship_squad, striked_ship);
    }

    /* prints the score of all the
     * ships in preorder sequence
     */
    print_preorder(ship_squad);

    /* frees the memory of tree*/
    delete_tree(ship_squad);

    return 0;
}
