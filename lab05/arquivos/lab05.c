#include <stdio.h>
#include <string.h>
#include "imagem.h"

#define MAX_FRACTAL_NAME 20
#define NUMBER_OF_FRACTAL_TYPES 7

int main(){
  char fractal[MAX_FRACTAL_NAME];
  char funcoes[NUMBER_OF_FRACTAL_TYPES][MAX_FRACTAL_NAME] = {"simples", "koch", "sierpinski", "dragao", "arvore", "gelo", "diamante"};
  int length, angle, subs, i;

  scanf("%s", fractal);
  scanf("%d", &length);
  scanf("%d", &angle);
  scanf("%d", &subs);

  for (i = 0; i < NUMBER_OF_FRACTAL_TYPES; i++)
    if(!strcmp(fractal,  funcoes[i]))
      break;

  
}
