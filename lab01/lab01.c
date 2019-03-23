/* MC202-E lab01: K diferenca
 * Vitor Nagata - RA 178499
 *
 * Function: This code takes one array of integers
 * and by combining each possible pair, counts the
 * number of times the k'th difference between the
 * pair occurs.
 *
 * Input:
 * sizeVectData - Size of data array
 * vectData - Array of data integers
 * sizeVectdiff - Size of k difference array
 * vectDiffvalue - Array of k difference to check
 *
 * Return:
 * 0 - successful
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int sizeVectData, sizeVectDiff, diff;
  int *vectData, *vectDiffValue, *vectDiffCount;
  int i, j, k;

  // Reading of the size and data of the first array
  scanf("%d", &sizeVectData);

  vectData = (int *)malloc(sizeVectData*sizeof(int));

  for(i = 0; i < sizeVectData; i++)
    scanf("%d", &vectData[i]);

  // Reading of the size and data of the k'th difference
  // of the array
  scanf("%d", &sizeVectDiff);

  vectDiffValue = (int *)malloc(sizeVectDiff * sizeof(int));

  // Alloc k difference count array and initialize with zeros
  vectDiffCount = (int *)calloc(sizeVectDiff , sizeof(int));

  for(i = 0; i < sizeVectDiff; i++)
    scanf("%d", &vectDiffValue[i]);

  // Combination of each pair of the data array
  for(i = 0; i < sizeVectData; i++){
    for(j = i+1; j < sizeVectData; j++){
      // calculates the difference between the pair
      diff = abs(vectData[i] - vectData[j]);

      // Check to see if there is this difference on the k
      // difference array to add the counter
      for(k = 0; k < sizeVectDiff; k++)
        if(diff == vectDiffValue[k])
          vectDiffCount[k]++;
    }
  }

  // prints the stored count of differences
  for(i = 0; i < sizeVectDiff; i++){
    printf("%d", vectDiffCount[i]);

    // if it isn't the last character to print
    // put a space after the number, if it is
    // the last number, put a newline
    if(i < sizeVectDiff - 1)
      putchar(' ');
    else
      putchar('\n');
  }

  // Dealloc the arrays
  free(vectData);
  free(vectDiffValue);
  free(vectDiffCount);

  return 0;
}
