/* ===========================================================================
 * MC202-E 1S2019 lab10 - merge k sorted arrays
 * Vitor Nagata - RA 178499
 *
 * DESCRIPTION: given k sorted arrays with m elements in total, this function
 * merge them with time complexity O(mlg(k))
 *
 * DEPENDENDECIES: fila_de_prioridade
 *
 * RETURN VALUE: 0 if successful
 *
 * ===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "fila_de_prioridade.h"

int main(){
    int number_of_arrays, *array_sizes, *array_index, **ordered_arrays;
    int i, j;
    int result_size = 0, *result_array;
    node min_node;
    heap_p min_heap;

    /* reading of the number of arrays */
    scanf("%d", &number_of_arrays);

    /* allocation of the input arrays and the auxiliary arrays*/
    /* stores the max size of each array of the input */
    array_sizes = malloc(sizeof *array_sizes * number_of_arrays);

    /* stores the position of the next node in each array to be
     * processed.
     */
    array_index = malloc(sizeof *array_index * number_of_arrays);

    /* ordered_arrays is an array of the input arrays (the first position
     * is the input array id, and the second one, its values
     */
    ordered_arrays = malloc(sizeof *ordered_arrays * number_of_arrays);

    /* reads the size of each input array and sums the end size of the
     * resulting (merged) array
     */
    for (i = 0; i < number_of_arrays; i++){
        scanf("%d", &array_sizes[i]);
        result_size += array_sizes[i];
    }

    /* allocates the resulting array */
    result_array = malloc(sizeof *result_array * result_size);

    /* for each array,
     * initializes the processing index at zero
     * allocates it correspondent sizes
     * read the input values
     */
    for (i = 0; i < number_of_arrays; i++){
        /* initialize with zero */
        array_index[i] = 0;

        /* allocates the size of each array */
        ordered_arrays[i] = malloc(sizeof **ordered_arrays * array_sizes[i]);

        /* reads the input */
        for (j = 0; j < array_sizes[i]; j++)
            scanf("%d", &ordered_arrays[i][j]);
    }

    /* creates a minimum heap */
    min_heap = create_heap(number_of_arrays);

    /* insert the first element of each array into the heap*/
    for (i = 0; i < number_of_arrays; i++){
        insert_heap(min_heap, ordered_arrays[i][0], i);
        array_index[i]++;
    }

    /* this part is responsible for the merging of the sorted arrays:
     * at this point, the first element of each array is stored at the
     * min-heap. For each element on the resulting array, we extract
     * the minimum element on the heap and insert a new one from the
     * corresponding origin array.
     */
    for (i = 0; i < result_size; i++){
        /* extracts the minimum element on the heap */
        min_node = extract_min(min_heap);
        /* stores it in the final array*/
        result_array[i] = min_node.value;

        /* verify if there is still elements in the origin array */
        if (array_index[min_node.id] < array_sizes[min_node.id]){
            /* inserts in the heap the next element of the corresponding array of the element removed
             * min_node.id = origin array of the last minimum element
             * array_index[min_node.id] = position of the next node in the origin array
             * after inserting the next element of the origin array, its index is incremented by 1
             * for the next node interaction
             */
            insert_heap(min_heap, ordered_arrays[min_node.id][array_index[min_node.id]++], min_node.id);
        }
    }


    /* printing of the resulting array */
    for (i = 0; i < result_size; i++){
        printf("%d", result_array[i]);
        if (i < result_size - 1)
            printf(" ");
        else
            printf("\n");
    }

    /* free the memory allocated */
    delete_heap(min_heap);
    for (i = 0; i < number_of_arrays; i++)
        free(ordered_arrays[i]);
    free(ordered_arrays);
    free(result_array);
    free(array_index);
    free(array_sizes);

    return 0;
}
