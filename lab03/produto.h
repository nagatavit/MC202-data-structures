#ifndef PRODUTO_H
#define PRODUTO_H

#include "data.h"

#define MAX_NOME_PRODUTO 21

typedef struct Produto
{
	char nome[MAX_NOME_PRODUTO];
	float preco;
	int quantidade;
	Data validade;
} Produto;

/*
 * Cria um novo produto.
 */
Produto criaProduto(char nome[], float preco, int quantidade, Data validade);

/*
 * Ler os dados de um produto do teclado no fomato:
 *    <nome> <preco> <quantidade>  <data_validade>
 * Devolve um novo registro de produto correspondente.
 */
Produto leProduto();

/*
 * Verifica se um produto estará vencido na data de hoje e devolve verdadeiro se estiver.
 */
int produtoEstaVencido(Produto prod, Data hoje);

#endif
