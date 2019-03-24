#include <stdio.h>
#include "data.h"
#include "produto.h"
#include "estoque.h"

int calculaQuantidadeCompras(Produto prodEmEstoque, int quantidadeDesejada, Data hoje);
void imprimeCompraProduto(Produto prod, int quantidade);

int main(){
  int numProdEstoque, quantEstoqueDesejada, quantProdComprar, quantProdDesejada, i;
  char nomeProdutoCompra[MAX_NOME_PRODUTO];
  Estoque estoque = criaEstoqueVazio();
  Produto produtoEmEstoque;
  Data hoje;

  hoje = leData();

  scanf("%d", &numProdEstoque);

  for (i = 0; i < numProdEstoque; i++)
    estoque = adicionaProduto(estoque, leProduto());

  scanf("%d", &quantEstoqueDesejada);

  for (i = 0; i < quantEstoqueDesejada; i++){

    // Le qual produto e quantidade desejada
    scanf("%s %d", nomeProdutoCompra, &quantProdDesejada);

    produtoEmEstoque = procuraProduto(estoque, nomeProdutoCompra);

    quantProdComprar = calculaQuantidadeCompras(produtoEmEstoque, quantProdDesejada, hoje);

    imprimeCompraProduto(produtoEmEstoque, quantProdComprar);
  }

  return (0);
}

int calculaQuantidadeCompras(Produto prodEmEstoque, int quantidadeDesejada, Data hoje){

  // Caso produto em estoque vencido, comprar toda quantidade desejada
  if (produtoEstaVencido(prodEmEstoque, hoje)){
    return (quantidadeDesejada);

  } else {

    // Caso nao esteja vencido mas ja ha mais do que o desejado em estoque, retorna 0
    if (prodEmEstoque.quantidade >= quantidadeDesejada)
      return (0);

    // Caso contrario, comprar restante necessario apenas
    else
      return (quantidadeDesejada - prodEmEstoque.quantidade);
  }
}

void imprimeCompraProduto(Produto prod, int quantidade){
  printf("%s %.2f\n", prod.nome, quantidade*prod.preco);
}

