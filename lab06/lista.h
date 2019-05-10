/*
 * Description
 */

#ifndef LISTA_H_
#define LISTA_H_

#define ARRIVE_HEAD -1

/*
 * TAD node de uma lista ligada
 */
typedef struct Node {
	int arrive, priority;
	struct Node *next;
} Node;

/*
 * ponteiro para no
 */
typedef Node *node_p;


/*
 * Cria uma lista vazia
 */
node_p create_list();

/*
 * Deleta lista ligada
 */
void delete_list(node_p list);

/*
 * insere um elemento no comeco da lista
 * e devolve uma nova lista ligada
 */
node_p insert_element(node_p list, int arrive, int priority);

/*
 * insere um elemento ja ordenado pela ordem de chegada
 */
node_p insert_sorted(node_p list, int arrive, int prioritty);

/*
 * imprime a lista do comeco ao fim
 */
void print_list(node_p list);

#endif
