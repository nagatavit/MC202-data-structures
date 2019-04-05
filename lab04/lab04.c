#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"
#include "vetor.h"

int main(){
  retangulo *tela, **ataque_box, **adversario_box, *interseccao;
  vetor **ataque_vet, **adversario_vet;
  double x0,y0,x1,y1,v_x,v_y;
  double area_atual, area_max = -1;
  int n, m, i, j;

  /* ===============
   * Leitura da tela
   * =============== */
  scanf("%lf %lf %lf %lf", &x0,&y0,&x1,&y1);
  tela = retangulo_criar(x0, y0, x1, y1);

  /* =====================================
   * leitura e alocacao do tamanho e dados
   * dos vetores e retangulos de ataque
   * ===================================== */
  scanf("%d", &n);
  ataque_box = malloc(sizeof *ataque_box * n);
  ataque_vet = malloc(sizeof *ataque_vet * n);

  for (i = 0; i < n; i++){
    scanf("%lf %lf %lf %lf", &x0,&y0,&x1,&y1);
    scanf("%lf %lf", &v_x, &v_y);
    ataque_box[i] = retangulo_criar(x0, y0, x1, y1);
    ataque_vet[i] = vetor_criar(v_x, v_y);
  }

  /* ======================================
   * leitura e alocacao do tamanho e dados
   * dos vetores e retangulos do adversario
   * ====================================== */
  scanf("%d", &m);
  adversario_box = malloc(sizeof *adversario_box * m);
  adversario_vet = malloc(sizeof *adversario_vet * m);

  for (i = 0; i < m; i++){
    scanf("%lf %lf %lf %lf", &x0,&y0,&x1,&y1);
    scanf("%lf %lf", &v_x, &v_y);
    adversario_box[i] = retangulo_criar(x0, y0, x1, y1);
    adversario_vet[i] = vetor_criar(v_x, v_y);
  }

  /* ==================================
   * aplicacao dos vetores de movimento
   * ================================== */
  for (i = 0; i < n; i++)
    retangulo_transladar(ataque_box[i], ataque_vet[i]);
  for (i = 0; i < m; i++)
    retangulo_transladar(ataque_box[i], ataque_vet[i]);

  /* ======================================
   * checa se ha interseccao nos retangulos
   * e se ela eh maior do que a armazenada
   * ====================================== */

  for (i = 0; i < n; i++){
    for (j = 0; j < m; j++){
      interseccao = retangulo_interseccao(ataque_box[i], adversario_box[j]);
      area_atual = retangulo_area(interseccao);
      if ((area_atual > area_max) && retangulo_intersectam(interseccao, tela))
        area_max = area_atual;
      free(interseccao);
    }
  }

  if (area_max < 0)
    printf("null\n");
  else
    printf("%.2f\n", area_max);

  /* ============================
   * liberacao de memoria alocada
   * ============================ */

  for (i = 0; i < n; i++){
    retangulo_destruir(ataque_box[i]);
    vetor_destruir(ataque_vet[i]);
  }

  for (i = 0; i < m; i++){
    retangulo_destruir(ataque_box[i]);
    vetor_destruir(ataque_vet[i]);
  }

  free(ataque_box);
  free(ataque_vet);
  free(adversario_box);
  free(adversario_vet);

  retangulo_destruir(tela);
}
