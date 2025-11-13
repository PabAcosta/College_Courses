#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

char *pad(char *s, int d){

  int length = 0;
  int pad_spaces = 0;
  int total_length = 0;
  int i;

  if (s == NULL || d <= 0) {
    return NULL;
  }

  while (s[length] != '\0') {
    length++;
  }

  if (length % d != 0) {
    pad_spaces = d - (length % d);
  }

  total_length = length + pad_spaces;

  char *result = malloc(total_length + 1);
  if (result == NULL) {
    return NULL;
  }

  for (i = 0; i < length; i++) {
    result[i] = s[i];
  }

  while (i < total_length) {
    result[i] = ' ';
    i++;
  }

  result[i] = '\0';
  return result;

}
