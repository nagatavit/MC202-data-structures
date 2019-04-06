#include <stdlib.h>
#include "retangulo.h"
#include <stdio.h>

retangulo* retangulo_criar(double px, double py, double qx, double qy){
  retangulo *retangulo_p = malloc(sizeof *retangulo_p);

  retangulo_p->sup_esq = malloc(sizeof *(retangulo_p->sup_esq));
  retangulo_p->inf_dir = malloc(sizeof *(retangulo_p->inf_dir));

  retangulo_p->sup_esq->x = px;
  retangulo_p->sup_esq->y = py;
  retangulo_p->inf_dir->x = qx;
  retangulo_p->inf_dir->y = qy;

  return retangulo_p;
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
  double area;

  if (r  == NULL)
    return -1;

  area = retangulo_altura(r) * retangulo_largura(r);

  if (area <= 0)
    return -1;
  else
    return area;
}

void retangulo_transladar(retangulo* r, vetor const* v){
  vetor_somar(r->sup_esq, v, r->sup_esq);
  vetor_somar(r->inf_dir, v, r->inf_dir);

  return;
}

/*
 * calcula se há intersecção entre dois intervalos
 */

int intervalo_interseca(double menor_p1, double maior_p1,
                        double menor_p2, double maior_p2){
  if ((menor_p1  < maior_p2) && (maior_p1  > menor_p2))
    return 1;
  else
    return 0;
}

int retangulo_intersectam(retangulo const* a, retangulo const* b){
  // Verifica intervalo em x
  if (intervalo_interseca(a->sup_esq->x, a->inf_dir->x, b->sup_esq->x, b->inf_dir->x)
      ||
      // Verifica intervalo em y
      intervalo_interseca(a->inf_dir->y, a->sup_esq->y, b->inf_dir->y, b->sup_esq->y))
    return 1;
  else
    return 0;
}

/*
 * retorna maior entre a e b
 */
double retorna_max(double a, double b){
  if (a > b)
    return a;
  else
    return b;
}

/*
 * retorna menor entre a e b
 */

double retorna_min(double a, double b){
  if (a < b)
    return a;
  else
    return b;
}

retangulo* retangulo_interseccao(retangulo const* a, retangulo const* b){
  double sup_esq_x, sup_esq_y, inf_dir_x, inf_dir_y;

  if (retangulo_intersectam(a, b)){

    // intervalo em x
    sup_esq_x = retorna_max(a->sup_esq->x, b->sup_esq->x);
    inf_dir_x = retorna_min(a->inf_dir->x, b->inf_dir->x);

    // intervalor em y
    sup_esq_y = retorna_min(a->sup_esq->y, b->sup_esq->y);
    inf_dir_y = retorna_max(a->inf_dir->y, b->inf_dir->y);

    return retangulo_criar(sup_esq_x, sup_esq_y, inf_dir_x, inf_dir_y);
  }

  return NULL;
}
