#include <stdlib.h>
#include "digrafo.h"

graph_p create_graph(int size){
    int i;
    graph_p new_graph = malloc(sizeof *new_graph);

    new_graph->n = size;
    new_graph->throughput = malloc(sizeof *(new_graph->throughput) * size);

    /*
     * allocates all each line of the matrix and inittialize it with zeros
     * the use of calloc is just to eliminate the use of a "for" to inittialize
     * the matrix
     */
    for (i = 0; i < size; i++)
        new_graph->throughput[i] = calloc(size, sizeof **(new_graph->throughput));

    return new_graph;
}

void delete_graph(graph_p pipe_sys){
    int i;

    /* free the adjacency matrix lines*/
    for (i = 0; i < pipe_sys->n; i++)
        free(pipe_sys->throughput[i]);

    /* free the matrix */
    free(pipe_sys->throughput);
    /* free the graph */
    free(pipe_sys);
}

void insert_value(graph_p pipe_sys, int s, int t, int throughput){
    /* inserts the throughput of the pipe from "s" to "t" */
    pipe_sys->throughput[s][t] = throughput;
}

int get_input_throughput(graph_p pipe_sys, int vertex){
    int i, total_input = 0;

    /*
     * searches for all the neighbors of the vertex
     * such that vertex is in the image of the relation
     * and sums the values of the edges
     */
    for (i = 0; i < pipe_sys->n; i++)
        total_input += pipe_sys->throughput[i][vertex];

    return total_input;
}

int get_output_throughput(graph_p pipe_sys, int vertex){
    int i, total_output = 0;

    /*
     * searches for all the neighbors of the vertex
     * such that vertex is in the domain of the relation
     * and sums the values of the edges
     */
    for (i = 0; i < pipe_sys->n; i++)
        total_output += pipe_sys->throughput[vertex][i];

    return total_output;
}

int get_flow_rate(graph_p pipe_sys, int vertex){
    /*
     * returns the difference between the input and
     * the output of a vertex
     */
    return (get_input_throughput(pipe_sys, vertex) -
            get_output_throughput(pipe_sys, vertex));
}
