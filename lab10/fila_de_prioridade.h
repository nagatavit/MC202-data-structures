#ifndef FILA_DE_PRIORIDADE_H_
#define FILA_DE_PRIORIDADE_H_

#define PARENT(i) ((i-1)/2)
#define LEFT_CHILD(i) (2*i+1)
#define RIGHT_CHILD(i) (2*i+2)

typedef struct{
    int value;
    int id;
} node;

typedef node *node_p;

typedef struct{
    node_p nodes;
    int total_size;
    int used_size;
} heap;

typedef heap *heap_p;

/*
 * this function switches the values from two nodes
 */

void switch_nodes(node_p a, node_p b);

/*
 * creates a min-heap with a given size
 */

heap_p create_heap(int size);

/*
 * deletes a min-heap
 */

void delete_heap(heap_p min_heap);

/*
 * inserts a new element on a min-heap
 */

void insert_heap(heap_p min_heap, int value, int id);

/*
 * extracts the minimum element of the heap and
 * re-organize it
 */

node extract_min(heap_p min_heap);

/*
 * corrects the position of a node from
 * bottom up
 */

void up_heap(heap_p min_heap, int position);

/*
 * corrects the position of a node from
 * root downwards
 */

void down_heap(heap_p min_heap, int position);

#endif
