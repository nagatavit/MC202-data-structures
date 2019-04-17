#include <stdio.h>
#include <string.h>
#include "imagem.h"

#define MAX_FRACTAL_NAME 20
#define NUMBER_OF_FRACTAL_TYPES 7
#define RECURSIVE_SUB_F 0
#define RECURSIVE_SUB_G 1
#define NOT_INITIAL 0
#define IS_INITIAL 1
#define FRACTAL_TYPE_INITIAL -1
#define FRACTAL_TYPE_CONVEX_CORNER 0
#define FRACTAL_TYPE_CONCAVE_CORNER 1
#define FRACTAL_TYPE_LINE 2

void fractal_simples(imagem_p img, int l, int angle, int depth);
void fractal_koch(imagem_p img, int l, int angle, int depth);
void fractal_sierpinski(imagem_p img, int l, int angle, int depth, int f_or_g);
void fractal_dragao(imagem_p img, int l, int angle, int depth, int f_or_g);
void fractal_arvore(imagem_p img, int l, int angle, int depth);
void fractal_gelo(imagem_p img, int l, int angle, int depth, int is_initial);
void fractal_diamante(imagem_p img, int l, int angle, int depth, int fractal_type);

int main(){
  char fractal[MAX_FRACTAL_NAME];
  char funcoes[NUMBER_OF_FRACTAL_TYPES][MAX_FRACTAL_NAME] = {"simples", "koch", "sierpinski", "dragao", "arvore", "gelo", "diamante"};
  int length, angle, depth, i;
  imagem_p  img;

  img  = criar_imagem();

  scanf("%s", fractal);
  scanf("%d", &length);
  scanf("%d", &angle);
  scanf("%d", &depth);

  for (i = 0; i < NUMBER_OF_FRACTAL_TYPES; i++)
    if(!strcmp(fractal,  funcoes[i]))
      break;

  switch (i) {
  case 0:
    fractal_simples(img, length, angle, depth);
    break;
  case 1:
    fractal_koch(img, length, angle, depth);
    break;
  case 2:
    fractal_sierpinski(img, length, angle, depth, FRACTAL_TYPE_INITIAL);
    break;
  case 3:
    fractal_dragao(img, length, angle, depth, FRACTAL_TYPE_INITIAL);
    break;
  case 4:
    fractal_arvore(img, length, angle, depth);
    break;
  case 5:
    fractal_gelo(img, length, angle, depth, IS_INITIAL);
    break;
  case 6:
    fractal_diamante(img, length, angle, depth, FRACTAL_TYPE_INITIAL);
    break;
  }

  imprimir_imagem(img);
  liberar_imagem(img);
}

void fractal_simples(imagem_p img, int l, int angle, int depth){
  if (depth == 0){
    /* caso base*/
    andar_cabeca(img, l);
    girar_cabeca(img, angle);
    andar_cabeca(img, l);
    girar_cabeca(img, angle);
    andar_cabeca(img, l);
  } else {
    /* caso geral */
    fractal_simples(img, 2*l-1, angle, depth - 1);
  }
}

void fractal_koch(imagem_p img, int l, int angle, int depth){
  if (depth == 0){
    /* caso base: andar uma linha */
    andar_cabeca(img, l);
  } else {
    /* caso geral: koch + koch -- koch + koch*/
    fractal_koch(img, l, angle, depth - 1);
    girar_cabeca(img, angle);
    fractal_koch(img, l, angle, depth - 1);
    girar_cabeca(img, -2 * angle);
    fractal_koch(img, l, angle, depth - 1);
    girar_cabeca(img, angle);
    fractal_koch(img, l, angle, depth - 1);
  }
}

void fractal_sierpinski(imagem_p img, int l, int angle, int depth, int f_or_g){
  if (depth < 0){
    /* caso base = F*/
    andar_cabeca(img, l);
    return;
  } else if (f_or_g == RECURSIVE_SUB_F) {
    /* caso recursivo para F */
    fractal_sierpinski(img, l, angle, depth - 1, RECURSIVE_SUB_F);
    girar_cabeca(img, angle);
    fractal_sierpinski(img, l, angle, depth - 1, RECURSIVE_SUB_G);
    girar_cabeca(img, -angle);
    fractal_sierpinski(img, l, angle, depth - 1, RECURSIVE_SUB_F);
    girar_cabeca(img, -angle);
    fractal_sierpinski(img, l, angle, depth - 1, RECURSIVE_SUB_G);
    girar_cabeca(img, angle);
    fractal_sierpinski(img, l, angle, depth - 1, RECURSIVE_SUB_F);
    return;
  } else if (f_or_g == RECURSIVE_SUB_G) {
    /* caso recursivo para G */
    fractal_sierpinski(img, l, angle, depth - 1, RECURSIVE_SUB_G);
    fractal_sierpinski(img, l, angle, depth - 1, RECURSIVE_SUB_G);
    return;
  }

  /* caso inicial*/
  fractal_sierpinski(img, l, angle, depth - 1, RECURSIVE_SUB_F);
  girar_cabeca(img, angle);
  fractal_sierpinski(img, l, angle, depth - 1, RECURSIVE_SUB_G);
  girar_cabeca(img, angle);
  fractal_sierpinski(img, l, angle, depth - 1, RECURSIVE_SUB_G);
  girar_cabeca(img, angle);
}

void fractal_dragao(imagem_p img, int l, int angle, int depth, int f_or_g){
  if (depth < 0){
    /* caso base */
    andar_cabeca(img, l);
    return;
  } else if (f_or_g == RECURSIVE_SUB_F) {
    /* caso recursivo para f */
    fractal_dragao(img, l, angle, depth - 1, RECURSIVE_SUB_F);
    girar_cabeca(img, -angle);
    fractal_dragao(img, l, angle, depth - 1, RECURSIVE_SUB_G);
    return;
  } else if (f_or_g == RECURSIVE_SUB_G) {
    /* caso recursivo para g (a no enunciado) */
    fractal_dragao(img, l, angle, depth - 1, RECURSIVE_SUB_F);
    girar_cabeca(img, angle);
    fractal_dragao(img, l, angle, depth - 1, RECURSIVE_SUB_G);
    return;
  }

  /* caso inicial */
  fractal_dragao(img, l, angle, depth - 1, RECURSIVE_SUB_F);
  fractal_dragao(img, l, angle, depth - 1, RECURSIVE_SUB_G);
}

void fractal_arvore(imagem_p img, int l, int angle, int depth){
  tartaruga cabeca;

  if (depth == 0){
    /* caso base = F*/
    andar_cabeca(img, l);
  } else {
    /* F */
    fractal_arvore(img, l, angle, depth -1);
    /* colchetes 1 = [+FF] */
    cabeca = obter_tartaruga(img);
    girar_cabeca(img, angle);
    fractal_arvore(img, l, angle, depth -1);
    fractal_arvore(img, l, angle, depth -1);
    posicionar_tartaruga(img, cabeca);
    /* colchetes 2 = [-FF] */
    cabeca = obter_tartaruga(img);
    girar_cabeca(img, -angle);
    fractal_arvore(img, l, angle, depth -1);
    fractal_arvore(img, l, angle, depth -1);
    posicionar_tartaruga(img, cabeca);
    /* F */
    fractal_arvore(img, l, angle, depth -1);
    /* colchetes 3 = [-F]*/
    cabeca = obter_tartaruga(img);
    girar_cabeca(img, -angle);
    fractal_arvore(img, l, angle, depth -1);
    posicionar_tartaruga(img, cabeca);
    /* colchetes 4 = [+F]*/
    cabeca = obter_tartaruga(img);
    girar_cabeca(img, angle);
    fractal_arvore(img, l, angle, depth -1);
    posicionar_tartaruga(img, cabeca);
    /* F */
    fractal_arvore(img, l, angle, depth -1);
  }
}

/* ========================================
 * Fractal de gelo
 * caso inicial: F+F+F+F
 * Regra: F = FF+F++F+F
 * ======================================== */

void fractal_gelo(imagem_p img, int l, int angle, int depth, int is_initial){
  if (depth < 0){
    /* caso base: andar para frente */
    andar_cabeca(img, l);
    return;
  } else if (is_initial == NOT_INITIAL) {
    /* caso geral: F = FF+F++F+F */
    fractal_gelo(img, l, angle, depth - 1, NOT_INITIAL);
    fractal_gelo(img, l, angle, depth - 1, NOT_INITIAL);
    girar_cabeca(img, angle);
    fractal_gelo(img, l, angle, depth - 1, NOT_INITIAL);
    girar_cabeca(img, angle);
    girar_cabeca(img, angle);
    fractal_gelo(img, l, angle, depth - 1, NOT_INITIAL);
    girar_cabeca(img, angle);
    fractal_gelo(img, l, angle, depth - 1, NOT_INITIAL);
    return;
  }

  /* caso inicial (F+F+F+F) */
  fractal_gelo(img, l, angle, depth - 1, NOT_INITIAL);
  girar_cabeca(img, angle);
  fractal_gelo(img, l, angle, depth - 1, NOT_INITIAL);
  girar_cabeca(img, angle);
  fractal_gelo(img, l, angle, depth - 1, NOT_INITIAL);
  girar_cabeca(img, angle);
  fractal_gelo(img, l, angle, depth - 1, NOT_INITIAL);
}

/* ========================================
 * Fractal diamante:
 * Caso inicial: F+F+F+F+F+F+
 * Regras:
 * "+" = "+F-F+"
 * "-" = "+F+++F+"
 * "+++" = "+F+F+"
 * ======================================== */

void fractal_diamante(imagem_p img, int l, int angle, int depth, int fractal_type){
  if(depth < 0){
    /*
     * ha tres tipos de caso base:
     * 1 - a quina do poligono eh para fora: gira um angulo "angle"
     * 2 - a quina do poligono eh para dentro: gira um angulo "-angle"
     * 3 - a quina eh um fim de uma reta: gira um angulo "3*angle"
     */
    if (fractal_type == FRACTAL_TYPE_CONCAVE_CORNER)
      angle = -angle;
    if (fractal_type == FRACTAL_TYPE_LINE)
      angle = 3*angle;
    girar_cabeca(img, angle);
    return;
  } else if (fractal_type == FRACTAL_TYPE_CONVEX_CORNER) {
    /* caso geral 1: caso a quina seja para fora, fazer uma concavidade
     * para dentro; (F + F) -> (F (+F-F+) F)
     */
    fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
    andar_cabeca(img, l);
    fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONCAVE_CORNER);
    andar_cabeca(img, l);
    fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
    return;
  } else if (fractal_type == FRACTAL_TYPE_CONCAVE_CORNER){
    /* caso geral 2: caso a quina seja para dentro, fazer uma linha
     * e voltar para quina. (F - F) -> (F (+F+++F+) F)
     */
    fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
    andar_cabeca(img, l);
    fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_LINE);
    andar_cabeca(img, l);
    fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
    return;
  } else if (fractal_type == FRACTAL_TYPE_LINE){
    /* caso geral 3: caso a quina seja uma reta, fazer um hexagono (volta
     * para o caso inicial). (+++) -> (+F+F+)
     */
    fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
    andar_cabeca(img, l);
    fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
    andar_cabeca(img, l);
    fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
    return;
  }

  /* caso inicial (F+F+F+F+F+F+) */
  andar_cabeca(img, l);
  fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
  andar_cabeca(img, l);
  fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
  andar_cabeca(img, l);
  fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
  andar_cabeca(img, l);
  fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
  andar_cabeca(img, l);
  fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
  andar_cabeca(img, l);
  fractal_diamante(img, l, angle, depth - 1, FRACTAL_TYPE_CONVEX_CORNER);
}
