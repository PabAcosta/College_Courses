#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

char *str_zip(char *s1, char *s2){

  int x = 0, y = 0, z = 0;
  int length = string_length(s1) + string_length(s2);
  char *new_str =malloc(length + 1);

  if (new_str == NULL) {
    return NULL;
  }

  while (s1[x] != '\0' || s2[y] != '\0'){
    if (s1[x] != '\0'){
      new_str[z++] = s1[x++];
    }
    if (s2[y] != '\0'){
      new_str[z++] = s2[y++];
    }
  }

  new_str[z] = '\0';
  return new_str;
}
