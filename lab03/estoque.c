#include "estoque.h"

Estoque criaEstoqueVazio(){
	Estoque novoEstoque;

	novoEstoque.num_produtos = 0;

	return (novoEstoque);
}

Estoque adicionaProduto(Estoque estoque, Produto prod){
	if (estoque.num_produtos == MAX_PRODUTO_ESTOQUE)
		return (estoque);
	
	estoque.produtos[estoque.num_produtos] = prod;
	estoque.num_produtos++;

	return (estoque);
}

Estoque procuraProduto(Estoque estoque, char nome[]){
	int i;

	for (i = 0; i < estoque.num_produtos; i++){
		if (

	}
}
