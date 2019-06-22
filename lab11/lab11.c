/* ===========================================================================
 * MC202-E 1S2019 lab11 - leaks in a pipe system (graphs)
 * Vitor Nagata - RA 178499
 *
 * DESCRIPTION: to verify if a pipe tubulation system is leaking at any point
 * we describe the system as a graph, being the vertices, the connections and,
 * the edges, the pipes of the system. if there is any leak in the system, this
 * program checks the resulting balance between the sources and the targets of
 * the system and also, points out which vertices are being leaked and by how much
 *
 * RETURN VALUE: 0 - if successful
 *
 * ===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "digrafo.h"

#define VERTEX_COMMON 0
#define VERTEX_SOURCE 1
#define VERTEX_TARGET 2

int main(){
    int *vertex_type, aux_reading, *vertex_balance, total_balance = 0;
    int vertex_number, edge_number, source_number, target_number;
    int i, v1, v2, throughput;
    graph_p pipe_sys;

    /* ===============================================================
     * Reading and Initialization of the variables
     * =============================================================== */

    /*
     * reads the number of vertex in the graph, and:
     * - creates a graph "pipe_sys"
     * - creates an array vertex_balance, which will store the result
     * between the input and output of each vertex
     * - creates an array vertex_type to mark with vertex is a source,
     * target or an internal vertex of the graph
     */
    scanf("%d", &vertex_number);
    pipe_sys = create_graph(vertex_number);
    vertex_balance = malloc(sizeof *vertex_balance * vertex_number);
    vertex_type = calloc(vertex_number, sizeof *vertex_type);

    /*
     * reading of the number of edges and the values of each edge
     */
    scanf("%d", &edge_number);
    for (i = 0; i < edge_number; i++){
        scanf("%d %d %d", &v1, &v2, &throughput);
        insert_value(pipe_sys, v1, v2, throughput);
    }

    /* reading of which vertex is a source */
    scanf("%d", &source_number);
    for (i = 0; i < source_number; i++){
        scanf("%d", &aux_reading);
        vertex_type[aux_reading] = VERTEX_SOURCE;
    }

    /* reading of which vertex is a target */
    scanf("%d", &target_number);
    for (i = 0; i < target_number; i++){
        scanf("%d", &aux_reading);
        vertex_type[aux_reading] = VERTEX_TARGET;
    }

    /* ===============================================================
     * Computation of the flow balance of each vertex
     * =============================================================== */

    /*
     * for each vertex in the system, if it is an internal vertex of
     * the graph, get it's balance between input and output and stores
     * at the vertex_balance.
     * if it is an source or target, subtracts the balance to the total
     * balance (starts at 0). The subtraction is because, if there is
     * an leak inside the system, the input would be greater than the
     * output, leading to a negative balance. To give an positive
     * balance, we need to subtract instead of adding them to the
     * final value.
     */
    for (i = 0; i < pipe_sys->n; i++){
        if (vertex_type[i] == VERTEX_COMMON)
            vertex_balance[i] = get_flow_rate(pipe_sys, i);
        else
            total_balance -= get_flow_rate(pipe_sys, i);
    }

    /* prints the final balance between the sources and the targets */
    printf("%d\n", total_balance);

    /* if the balance is not zero, prints with vertex are getting leaked */
    if (total_balance != 0)
        /* searches for all the vertex in the system */
        for (i = 0; i < pipe_sys->n; i++)
            /* if the vertex is not a source or target and it's balance is not 0 */
            if (vertex_type[i] == VERTEX_COMMON && vertex_balance[i] != 0)
                printf("%d %d\n", i, vertex_balance[i]);

    /* ===============================================================
     * Freeing the memory allocations
     * =============================================================== */
    free(vertex_type);
    free(vertex_balance);
    delete_graph(pipe_sys);

    return 0;
}
