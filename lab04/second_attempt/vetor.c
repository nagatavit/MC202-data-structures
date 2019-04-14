#include <stdlib.h>
#include "vetor.h"

vetor* vetor_criar(double x, double y){
  vetor* vetor_p = malloc(sizeof *vetor_p);

  vetor_p->x = x;
  vetor_p->y = y;

  return vetor_p;
}

void vetor_destruir(vetor* v){
  free(v);

  return;
}

void vetor_somar(vetor const* a, vetor const* b, vetor* c){
  c->x = a->x + b->x;
  c->y = a->y + b->y;

  return;
}
