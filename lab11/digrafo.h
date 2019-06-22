#ifndef DIGRAFO_H_

typedef struct {
    int **throughput;
    int n;
} graph;

typedef graph *graph_p;

/*
 * creates a graph with given size
 */
graph_p create_graph(int size);

/*
 * deletes a given graph
 */
void delete_graph(graph_p pipe_sys);

/*
 * insert an edge (throughput of the pipe) value between two vertices from "s" to "t"
 */
void insert_value(graph_p pipe_sys, int s, int t, int throughput);

/*
 * get the sum of all the inputs on a given vertex
 */
int get_input_throughput(graph_p pipe_sys, int vertex);

/*
 * get the sum of all the outputs on a given vertex
 */
int get_output_throughput(graph_p pipe_sys, int vertex);

/*
 * get the final balance between the input and the
 * output on a given vertex:
 * returns:
 * > 0: the output is greater than the input
 * = 0: the output is equal the input
 * < 0: the output is less than the input
 */
int get_flow_rate(graph_p pipe_sys, int vertex);

#define DIGRAFO_H_

#endif
