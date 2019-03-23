/* ===========================================================================
 * MC202-E 1S2019 lab02: Bilhetes secretos
 * Vitor Nagata - RA 178499
 *
 * FUNCTION: Bilhetes secretos
 *
 * DESCRIPTION:
 * given a message and a list of indexes, reconstruct a secret message using
 * the words on the first message and the positions on the index
 *
 * RETURN VALUE:
 * 0 - if successful
 * ===========================================================================*/

#include <stdio.h>

#define MAX_LINE_SIZE 50000
#define MAX_WORD_SIZE 46
#define MAX_WORD_NUMBER 1000

void readLine(char lineString[]);
int splitString(char lineString[], char stringArray[][MAX_WORD_SIZE+1]);
int copyString(char lineString[], int position, char stringArray[][MAX_WORD_SIZE + 1], int wordIndex);
unsigned char isALetter(char c);
int readDecryptKey ();
int printDecryptMsg(char stringArray[][MAX_WORD_SIZE+1], int index, int numberOfWords);

int main(){
  char lineString[MAX_LINE_SIZE + 1];
  char stringArray[MAX_WORD_NUMBER][MAX_WORD_SIZE + 1];
  int numberOfWords, secretMessageSize, i;

  readLine(lineString);

  numberOfWords = splitString(lineString, stringArray);

  scanf ("%d", &secretMessageSize);

  // Prints each word of the secret message
  for (i = 0; i < secretMessageSize; i++){
    printDecryptMsg(stringArray, readDecryptKey(), numberOfWords);

    // Condition to print space or newline if it is the last character or not
    if (i == secretMessageSize - 1)
      putchar ('\n');
    else
      putchar (' ');
  }

  return(0);
}

/* ===========================================================================
 * FUNCTION: readLine
 *
 * DESCRIPTION:
 * read the full line from stdin and stores on a string
 *
 * PARAMETERS:
 * string "lineString" to store the line read
 *
 * DEPENDENDECIES:
 * char *fgets(char *str, int n, FILE *stream)
 *
 * RETURN VALUE:
 * none
 * ===========================================================================*/

void readLine(char lineString[]){
  fgets(lineString, MAX_LINE_SIZE, stdin);
  return;
}

/* ===========================================================================
 * FUNCTION: isALetter
 *
 * DESCRIPTION:
 * verifies if the given character is a letter on ASCII (between A-Z and a-z)
 *
 * PARAMETERS:
 * c - character to verify if it is a letter
 *
 * DEPENDENDECIES:
 * none
 *
 * RETURN VALUE:
 * 0 - if it is not a letter
 * 1 - if it is a letter
 * ===========================================================================*/

unsigned char isALetter(char c){
  if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    return 1;
  else
    return 0;
}

/* ===========================================================================
 * FUNCTION: copyString
 *
 * DESCRIPTION:
 * given a string, initial position on string, an array of strings and an
 * index of the word in array, copy the current word from the string to the
 * array of strings.
 *
 * PARAMETERS:
 * lineString - initial string from where the word is going to be copied
 * position - initial position on the string where the word starts
 * stringArray - array of strings to where the word is going to be copied
 * wordIndex - position of the word in the array of strings
 *
 * DEPENDENDECIES:
 * unsigned char isALetter(char c);
 *
 * RETURN VALUE:
 * returns the size of the word copied
 * ===========================================================================*/

int copyString(char lineString[], int position, char stringArray[][MAX_WORD_SIZE + 1], int wordIndex){
  int i = 0, sizeOfWord = 0;

  // copy until it find a non letter character
  while(isALetter(lineString[position + i])){
    stringArray[wordIndex][i] = lineString[position + i];
    sizeOfWord++;
    i++;
  }

  // put the '\0' at the end of each word to make it a string
  stringArray[wordIndex][i] = '\0';

  return(sizeOfWord);
}

/* ===========================================================================
 * FUNCTION: splitString
 *
 * DESCRIPTION:
 * given a string of a line and an array of strings, splits each word from the
 * string line into an array of words.
 *
 * PARAMETERS:
 * lineString - string of a phrase
 * stringArray - array of string to split the words
 *
 * DEPENDENDECIES:
 * unsigned char isALetter(char c);
 * int copyString(char lineString[], int position,
 *                char stringArray[][MAX_WORD_SIZE + 1], int wordIndex);
 *
 * RETURN VALUE:
 * returns the number of words stored in the array of strings
 *
 * ===========================================================================*/

int splitString(char lineString[], char stringArray[][MAX_WORD_SIZE+1]){
  int i = 0, j = 0;
  int wordSize;

  // Split strings until it reaches the end of the string or the array
  while ((lineString[i] != '\0') && (i < MAX_LINE_SIZE)){

    // while it is a letter, copy the word to the array
    if(isALetter(lineString[i])){
      wordSize = copyString(lineString, i, stringArray, j);
      i += wordSize;
    }
    j++;

    // if it isn't a letter and it is not the end of the string, go avance
    // the index
    while(!isALetter(lineString[i]) && lineString[i] != '\0') i++;

  }

  return (j);
}

/* ===========================================================================
 * FUNCTION: printDecryptMsg
 *
 * DESCRIPTION:
 * from an array of words and an index, print the word on the position of the
 * index
 *
 * PARAMETERS:
 * stringArray - array of words to be printed
 * index - index of the position of the word to be printed
 * numberOfWords - max number of words that are stored in the array
 *
 * DEPENDENDECIES:
 * int printf(const char *format, ...)
 *
 * RETURN VALUE:
 * -1 - if the word desired doesn't exists
 * 0 - if it is successful
 * ===========================================================================*/

int printDecryptMsg(char stringArray[][MAX_WORD_SIZE+1], int index, int numberOfWords){

  // if the index is bigger than the number of the words, return as inexistent
  if (index >= numberOfWords)
    return -1;
  else
    printf("%s", stringArray[index]);

  return 0;
}

/* ===========================================================================
 * FUNCTION: readDecryptKey
 *
 * DESCRIPTION:
 * reads the current key to decode the character in the secret nessage
 *
 * PARAMETERS:
 * none
 *
 * DEPENDENDECIES:
 * int scanf(const char *format, ...)
 *
 * RETURN VALUE:
 * returns the key value
 * ===========================================================================*/

int readDecryptKey (){
  int key;
  scanf ("%d", &key);

  return (key);
}
