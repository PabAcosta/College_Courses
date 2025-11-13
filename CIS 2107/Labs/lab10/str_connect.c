#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

char *str_connect(char **strs, int n, char c){

  int total_length = 0;
  int j, k = 0;

  if (n == 0) {
    char *empty = malloc(1);
    if (empty != NULL) {
      empty[0] = '\0';
    }
    return empty;
  }
 
  for (int i = 0; i < n; i++) {
    total_length += string_length(strs[i]);
  }

  total_length += (n - 1);

  char *result = malloc(total_length + 1);
  if (result == NULL) {
    return NULL;
  }

  for (int i = 0; i < n; i++) {
    j = 0;
    while (strs[i][j] != '\0') {
      result[k++] = strs[i][j];
      j++;
    }

    if (i < n - 1) {
      result[k++] = c;
    }
  }

  result[k] = '\0';
  return result;
}