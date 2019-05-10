#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main (){
    int n_clients, n_priorities, i;
    int arrive, priority;

    node_p *client_list;

    /* leitura da quantidade de clientes e prioridades */
    scanf("%d", &n_priorities);
    scanf("%d", &n_clients);

    /* Allocacao de um vetor de clientes por prioridades */
    client_list = malloc(sizeof *client_list * n_priorities);

    /* Criacao das listas ligadas dos clientes */
    for (i = 0; i < n_priorities; i++){
        client_list[i] = create_list();
    }

    /* leitura dos clientes e insercao na lista da prioridade correspondente */
    for (i = 0; i < n_clients; i++){
        scanf("%d %d", &arrive, &priority);
        client_list[priority] = insert_sorted(client_list[priority], arrive, priority);
    }

    /* impressao das listas ligadas */
    for (i = n_priorities - 1; i >= 0; i--)
        print_list(client_list[i]);

    /* libera memoria das listas ligadas */
    for (i = 0; i < n_priorities; i++)
        delete_list(client_list[i]);

    /* libera vetor de clientes */
    free(client_list);
}
