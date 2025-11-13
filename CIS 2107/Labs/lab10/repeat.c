#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

char *repeat(char *s, int x, char sep){
  int length = 0, total_length = 0, pos = 0;

  if (s == NULL || x <= 0){
    return NULL;
  }

  while (s[length] != '\0'){
    length++;
  }

  total_length = (length * x) + (x - 1);
  char *result = malloc(total_length + 1);
  if (result == NULL){
    return NULL;
  }

  for (int i = 0; i < x; i++){
    for (int j = 0; j < length; j++){
      result[pos] = s[j];
      pos++;
    }

    if (i < x - 1){
      result[pos] = sep;
      pos++;
    }
  }

  result[pos] = '\0';
  return result;
}