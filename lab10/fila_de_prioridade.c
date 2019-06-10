#include <stdlib.h>
#include "fila_de_prioridade.h"

void switch_nodes(node_p a, node_p b){
    node aux = *a;
    *a = *b;
    *b = aux;
}

heap_p create_heap(int size){
    /* allocates the heap */
    heap_p new_heap = malloc(sizeof *new_heap);

    /* allocates the nodes of the heap */
    new_heap->nodes = malloc(sizeof *(new_heap->nodes) * size);
    new_heap->total_size = size;
    new_heap->used_size = 0;

    return new_heap;
}

void delete_heap(heap_p min_heap){
    free(min_heap->nodes);
    free(min_heap);
}

void insert_heap(heap_p min_heap, int value, int id){
    /* if the heap is full, don't insert element */
    if (min_heap->total_size == min_heap->used_size)
        return;

    /* insert new value and array of origin for this value */
    min_heap->nodes[min_heap->used_size].value = value;
    min_heap->nodes[min_heap->used_size].id = id;
    min_heap->used_size++;

    /* corrects the position of new node */
    up_heap(min_heap, min_heap->used_size - 1);
}

void up_heap(heap_p min_heap, int position){
    /* if it is not the root and the parent is bigger than new node */
    if (position > 0 &&
        min_heap->nodes[position].value < min_heap->nodes[PARENT(position)].value){

        /* changes node position with its parent */
        switch_nodes(&min_heap->nodes[position], &min_heap->nodes[PARENT(position)]);

        /* recursivly corrects it's parent */
        up_heap(min_heap, PARENT(position));
    }
}

node extract_min(heap_p min_heap){
    /* min element is at the root */
    node min_element = min_heap->nodes[0];

    /* puts last element on the root */
    min_heap->nodes[0] = min_heap->nodes[min_heap->used_size - 1];
    min_heap->used_size--;

    /* corrects the position of root element */
    down_heap(min_heap, 0);

    return min_element;
}

void down_heap(heap_p min_heap, int position){
    int smallest_child_idx;

    /* checks if left child exists in the heap */
    if (LEFT_CHILD(position) < min_heap->used_size){
        smallest_child_idx = LEFT_CHILD(position);

        /* checks if right child exists and if it is smaller than left one */
        if (RIGHT_CHILD(position) < min_heap->used_size &&
            min_heap->nodes[RIGHT_CHILD(position)].value < min_heap->nodes[LEFT_CHILD(position)].value)
            smallest_child_idx = RIGHT_CHILD(position);

        /* checks if the current node is smaller than smallest child*/
        if (min_heap->nodes[position].value > min_heap->nodes[smallest_child_idx].value){
            switch_nodes(&min_heap->nodes[position], &min_heap->nodes[smallest_child_idx]);

            /* repeat for the smallest child */
            down_heap(min_heap, smallest_child_idx);
        }
    }

}

