#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

char **str_chop_all(char *s, char c){
  if (s == NULL){
    return NULL;
  }
    
  int i = 0;
  int k = 0;
  int count = 0;
  int index = 0;

  while (s[i] != '\0'){
    while (s[i] == c){
      i++;
    }
    if (s[i] != '\0'){
      count++;
      while (s[i] != '\0' && s[i] != c){
        i++;
      }
    }
  }

  char **result = malloc((count + 1) * sizeof(char *));
  if (result == NULL){
    return NULL;
  }

  while (s[k] != '\0'){
    while (s[k] == c){
      k++;
    }

    if (s[k] != '\0'){
      int start = k;
      while (s[k] != '\0' && s[k] != c){
        k++;
      }

      int length = k - start;
      result[index] = malloc(length + 1);

      if (result[index] == NULL) {
        for (int j = 0; j < index; j++){
          free(result[j]);
        }
        free(result);
        return NULL;
      }

      for (int j = 0; j < length; j++){
        result[index][j] = s[start + j];
      }

      result[index][length] = '\0';
      index++;
    }
  }

  result[index] = NULL;
  return result;
}
