/* ===========================================================================
 * MC202-E 1S2019 lab03 - Controle de estoque
 * Vitor Nagata - RA 178499
 *
 * DESCRIPTION: dado a quantidade de estoque e a quantiade de produtos desejados
 * ter em estoque, imprime o preco dos produtos necessarios a serem comprados
 *
 * RETURN VALUE: 0 - se bem sucedido
 *
 * ===========================================================================*/

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

  // Le quantidade de produtos em estoque
  scanf("%d", &numProdEstoque);

  // Le produtos em estoque
  for (i = 0; i < numProdEstoque; i++)
    estoque = adicionaProduto(estoque, leProduto());

  // Le quantidade de estoque desejado
  scanf("%d", &quantEstoqueDesejada);

  // Le produtos desejados e imprime valores
  for (i = 0; i < quantEstoqueDesejada; i++){

    // Le qual produto e quantidade desejada
    scanf("%s %d", nomeProdutoCompra, &quantProdDesejada);

    produtoEmEstoque = procuraProduto(estoque, nomeProdutoCompra);

    quantProdComprar = calculaQuantidadeCompras(produtoEmEstoque, quantProdDesejada, hoje);

    imprimeCompraProduto(produtoEmEstoque, quantProdComprar);
  }

  return (0);
}

/* ===========================================================================
 * FUNCTION: calculaquantidadecompras
 *
 * DESCRIPTION: calcula quantidade de produtos a serem comprados
 *
 * PARAMETERS:
 * prodEmEstoque - produtos em estoque
 * quantidadeDesejada - quantidade de produtos desejado em estoque
 * hoje - data atual
 *
 * DEPENDENDECIES: produtoEstaVencido
 *
 * RETURN VALUE: quantidade a ser comprada
 *
 * ===========================================================================*/

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

/* ===========================================================================
 * FUNCTION: imprimecompraproduto
 *
 * DESCRIPTION: imprime nome do produto e valor necessario
 *
 * PARAMETERS:
 * prod - produto a ser comprado
 * quantidade - quantidade a ser comprada
 *
 * DEPENDENDECIES: nenhuma
 *
 * RETURN VALUE: nenhum
 *
 * ===========================================================================*/

void imprimeCompraProduto(Produto prod, int quantidade){
  printf("%s %.2f\n", prod.nome, quantidade*prod.preco);
}

