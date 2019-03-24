#include <string.h>
#include <stdio.h>
#include "produto.h"

#define PRODUTO_VENCIDO 1
#define PRODUTO_BOM 0

Produto criaProduto(char nome[], float preco, int quantidade, Data validade){
  Produto novoProduto;

  strcpy(novoProduto.nome,nome);
  novoProduto.preco = preco;
  novoProduto.quantidade = quantidade;
  novoProduto.validade = validade;

  return (novoProduto);
}

Produto leProduto(){
  char nome[MAX_NOME_PRODUTO];
  float preco;
  int quantidade;
  Data validade;

  scanf("%s %f %d ", nome, &preco, &quantidade);

  validade = leData();

  return (criaProduto(nome, preco, quantidade, validade));
}

int produtoEstaVencido(Produto prod, Data hoje){
  if (comparaData(prod.validade, hoje) < 0)
    return (PRODUTO_VENCIDO);
  else
    return (PRODUTO_BOM);
}
