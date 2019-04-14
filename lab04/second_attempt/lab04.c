/* ===========================================================================
 * MC202-E 1S2019 lab04 - caixas de colisao
 * Vitor Nagata - RA 178499
 *
 * DESCRIPTION: dado n caixas de ataque e m caixas de defesa, e seus respecti-
 * vos vetores de movimento, o programa acha a maior area de interseccao entre
 * ataque e defesa
 *
 * RETURN VALUE: 0 - sem nenhum erro
 *
 * ===========================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include "retangulo.h"

/* PROTOTIPOS DAS FUNCOES */

retangulo* le_retangulo();
vetor* le_vetor();
void le_numero_caixas(int *n);
void le_hitboxes_e_vetores(retangulo ***box, vetor ***v, int n);
void deleta_hitboxes_e_vetores(retangulo ***box, vetor ***v, int n);
void calcula_movimentos(retangulo ***box, vetor ***v, int n);

/* MAIN */

int main(){
  retangulo *tela, **ataque_box, **defesa_box, *interseccao;
  vetor **ataque_vetor, **defesa_vetor;
  int i, j, n, m;
  double max_area = 0, atual_area;

  tela =  le_retangulo();

  le_numero_caixas(&n);
  le_hitboxes_e_vetores(&ataque_box, &ataque_vetor, n);

  le_numero_caixas(&m);
  le_hitboxes_e_vetores(&defesa_box, &defesa_vetor, m);

  calcula_movimentos(&ataque_box, &ataque_vetor, n);
  calcula_movimentos(&defesa_box, &defesa_vetor, m);

  /* verifica interseccao entre cada caixa de ataque e defesa */
  for (i = 0; i < n; i ++){
    for (j = 0; j < m; j++){
      interseccao = retangulo_interseccao(ataque_box[i], defesa_box[j]);
      if (interseccao != NULL){
        atual_area = retangulo_area(interseccao);

        /* verifica se a area eh maior e a interseccao esta dentro da tela*/
        if ((atual_area > max_area) && (retangulo_intersectam(interseccao, tela)))
          max_area = atual_area;
        retangulo_destruir(interseccao);
      }
    }
  }

  /* impressao da maior area de colisao */
  if (max_area == 0)
    printf("null\n");
  else
    printf("%.2f\n", max_area);

  /* desalocacao de memoria */
  deleta_hitboxes_e_vetores(&ataque_box, &ataque_vetor, n);
  deleta_hitboxes_e_vetores(&defesa_box, &defesa_vetor, m);

  retangulo_destruir(tela);
  return 0;
}

/* FUNCOES */

/*
 * le do 4 numeros em ponto flutuante
 * do teclado e devolve um retangulo
 */

retangulo* le_retangulo(){
  double x0,y0,x1,y1;
  scanf("%lf%lf%lf%lf", &x0,&y0,&x1,&y1);

  return retangulo_criar(x0, y0, x1, y1);
}

/*
 * le do 2 numeros em ponto flutuante
 * do teclado e devolve um vetor
 */

vetor* le_vetor(){
  double x,y;
  scanf("%lf%lf", &x, &y);

  return vetor_criar(x, y);
}

/*
 * le numero de hitboxes do teclado
 */

void le_numero_caixas(int *n){
  scanf("%d", n);
}

/*
 * le a uma sequencia de n hitboxes e vetores
 */

void le_hitboxes_e_vetores(retangulo ***box, vetor ***v, int n){
  int i;

  *box = malloc(sizeof **box * n);
  *v = malloc(sizeof **v * n);

  for (i = 0; i < n;  i++){
    (*box)[i] = le_retangulo();
    (*v)[i] = le_vetor();
  }
}

/*
 * deleta n hitboxes e vetores
 */

void deleta_hitboxes_e_vetores(retangulo ***box, vetor ***v, int n){
  int i;

  for (i = 0; i < n;  i++){
    retangulo_destruir((*box)[i]);
    vetor_destruir((*v)[i]);
  }

  free((*box));
  free((*v));
}

/*
 * calcula movimento das hitboxes
 */

void calcula_movimentos(retangulo ***box, vetor ***v, int n){
  int i;

  for (i = 0; i < n; i++)
    retangulo_transladar((*box)[i], (*v)[i]);
}
