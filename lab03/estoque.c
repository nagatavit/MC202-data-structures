#include <string.h>
#include "estoque.h"

Estoque criaEstoqueVazio(){
  Estoque novoEstoque;

  novoEstoque.num_produtos = 0;

  return (novoEstoque);
}

Estoque adicionaProduto(Estoque estoque, Produto prod){

  // Caso numero de produtos seja maximo, retorna
  // estoque sem adicionar produto
  if (estoque.num_produtos == MAX_PRODUTO_ESTOQUE)
    return (estoque);

  // Adiciona produto
  estoque.produtos[estoque.num_produtos] = prod;
  estoque.num_produtos++;

  return (estoque);
}

Produto procuraProduto(Estoque estoque, char nome[]){
  int i;

  // Busca linear pelo produto
  for (i = 0; i < estoque.num_produtos; i++)
    if (strcmp(estoque.produtos[i].nome, nome) == 0)
      return (estoque.produtos[i]);

  // Caso produto nao exista, devolve produto vazio
  return (criaProduto("0", 0.00, 0, criaData(0, 0, 0)));
}
