#include <stdlib.h>
#include "retangulo.h"

retangulo* retangulo_criar(double px, double py, double qx, double qy){
  retangulo *novo = malloc(sizeof *novo);

  novo->sup_esq = vetor_criar(px, py);
  novo->inf_dir = vetor_criar(qx, qy);

  return novo;
}

void retangulo_destruir(retangulo* r){
  vetor_destruir(r->sup_esq);
  vetor_destruir(r->inf_dir);

  free(r);

  return;
}

double retangulo_largura(retangulo const* r){
  return r->inf_dir->x - r->sup_esq->x;
}

double retangulo_altura(retangulo const* r){
  return r->sup_esq->y - r->inf_dir->y;
}

double retangulo_area(retangulo const* r){
  return retangulo_altura(r) * retangulo_largura(r);
}

void retangulo_transladar(retangulo* r, vetor const* v){
  vetor_somar(r->sup_esq, v, r->sup_esq);
  vetor_somar(r->inf_dir, v, r->inf_dir);

  return;
}

/*
 * verifica se ha interseccao entre os intervalos
 * (l0,l1) and (m0,m1)
 */

int intervalo_intersecta(double l0, double l1, double m0, double m1){
  if ((l0 < m1) && (l1 > m0))
    return 1;
  else
    return 0;
}

int retangulo_intersectam(retangulo const* a, retangulo const* b){

  /* verifica se ha interseccao nos intervalos de y e de x */
  if ((intervalo_intersecta(a->sup_esq->x, a->inf_dir->x, b->sup_esq->x, b->inf_dir->x))
      &&
      (intervalo_intersecta(a->inf_dir->y, a->sup_esq->y, b->inf_dir->y, b->sup_esq->y)))
    return 1;
  else
    return 0;
}

/*
 * retorna o maximo ou minimo entre a e b dependendo
 * de max_not_min: 1 para max e 0 para min
 */

double max_min(double a, double b, int max_not_min){
  if (max_not_min){
    if (a > b)
      return a;
    else
      return b;
  } else {
    if (a < b)
      return a;
    else
      return b;
  }
}

retangulo* retangulo_interseccao(retangulo const* a, retangulo const* b){
  double sup_esq_x, sup_esq_y, inf_dir_x, inf_dir_y;

  if (retangulo_intersectam(a, b)){
    // intervalo em x
    sup_esq_x = max_min(a->sup_esq->x, b->sup_esq->x, 1);
    inf_dir_x = max_min(a->inf_dir->x, b->inf_dir->x, 0);

    // intervalo em y
    sup_esq_y = max_min(a->sup_esq->y, b->sup_esq->y, 0);
    inf_dir_y = max_min(a->inf_dir->y, b->inf_dir->y, 1);

    return retangulo_criar(sup_esq_x, sup_esq_y, inf_dir_x, inf_dir_y);
  } else {
    return NULL;
  }
}
