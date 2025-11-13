#include <stdio.h>
#include "lab10.h"

void rm_empties(char **words){

  int i = 0, j = 0;

  while (words[i] != NULL){
    if (string_length(words[i]) > 0){
      words[j] = words[i];
      j++;
    }
    i++;
  }
  words[j] = NULL;
}
