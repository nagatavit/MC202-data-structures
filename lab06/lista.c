#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

node_p create_list (){
    return NULL;
}

void delete_list (node_p list){
    /* caso base nao faz nada */

    /* caso geral
     * deleta resto da lista e
     * deleta no atual
     */
    if (list != NULL){
        delete_list(list->next);
        free(list);
    }
}


node_p insert_element(node_p list, int arrive, int priority){
    node_p new_node = malloc(sizeof *new_node);

    /* inicializa novo no */
    new_node->arrive = arrive;
    new_node->priority = priority;
    new_node->next = list;

    return new_node;
}

node_p insert_sorted(node_p list, int arrive, int priority){
    node_p new_list;

    /* caso base: lista vazia ou novo no com chegada
     * menor que a lista atual
     */
    if (list == NULL || list->arrive > arrive){
        new_list = insert_element(list, arrive, priority);
        return new_list;
    } else {
        /* caso geral: insere ordenado no resto da lista */
        list->next = insert_sorted(list->next, arrive, priority);
        return list;
    }


}

void print_list(node_p list){
    /* caso base nao faz nada*/

    /* caso geral: imprime atual e imprime resto da lista */
    if (list != NULL){
        printf("%d %d\n", list->arrive, list->priority);
        print_list(list->next);
    }
}
