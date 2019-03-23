#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "produto.h"

#define MAX_PRODUTO_ESTOQUE 100

typedef struct Estoque
{
	Produto produtos[MAX_PRODUTO_ESTOQUE];
	int num_produtos;
} Estoque;

/*
 * Cria um estoque vazio.
 */
Estoque criaEstoqueVazio();

/*
 * Adiciona um produto no estoque e
 * cria um novo estoque com o novo
 * produto e todos os produtos que
 * já estavam no estoque anteriormente.
 */
Estoque adicionaProduto(Estoque estoque, Produto prod);

/*
 * Procura um produto no estoque pelo nome e devolve esse produto.
 */
Produto procuraProduto(Estoque estoque, char nome[]);

#endif
