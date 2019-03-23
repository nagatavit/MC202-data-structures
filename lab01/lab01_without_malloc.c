#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM_VECT 1000
#define TAM_DIFF 500

int main(){
  int sizeVectData, sizeVectDiff, diff;
  int vectData[TAM_VECT], vectDiff[TAM_DIFF], vectDiffCount[TAM_DIFF];
  int i, j, k;

  scanf("%d ", &sizeVectData);

  for(i = 0; i < sizeVectData; i++)
    scanf("%d", &vectData[i]);

  scanf("%d", &sizeVectDiff);

  for(i = 0; i < sizeVectDiff; i++){
    scanf("%d", &vectDiff[i]);
    vectDiffCount[i] = 0;
  }

  for(i = 0; i < sizeVectData; i++){
    for(j = i + 1; j < sizeVectData; j++){
      diff = abs(vectData[i] - vectData[j]);

      for(k = 0; k < sizeVectDiff; k++)
        if(diff == vectDiff[k])
          vectDiffCount[k]++;
    }
  }

  for(i = 0; i < sizeVectDiff - 1; i++)
    printf("%d ",vectDiffCount[i]);

  printf("%d",vectDiffCount[sizeVectDiff - 1]);
  putchar('\n');

  return 0;
}
