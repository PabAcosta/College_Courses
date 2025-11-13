#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

int starts_with(char *s, char *pat);

char *replace(char *s, char *pat, char *rep){

  int pat_count = 0, i = 0, k = 0, x = 0;
  int length;

  int s_length = string_length(s);
  int pat_length = string_length(pat);
  int rep_length = string_length(rep);

  if(pat_length == 0){
    return NULL;
  }

  while (s[i] != '\0') {
    if (starts_with(&s[i], pat)) {
      pat_count++;
      i += pat_length;
    } else {
      i++;
    }
  }

  length = s_length + pat_count * (rep_length - pat_length);
  char *result = malloc(length + 1);
  
  if (result == NULL) {
    return NULL;
  }

  while (s[k] != '\0') {
    if (starts_with(&s[k], pat)) {
      for (int j = 0; j < rep_length; j++) {
        result[x++] = rep[j];
      }
      k += pat_length;
    } else {
      result[x++] = s[k++];
    }
  }

  result[x] = '\0';
  return result;
}

int starts_with(char *s, char *pat){

  int i = 0;

  while (pat[i] != '\0') {
    if (s[i] != pat[i]) {
      return 0;
    }
    i++;
  }
  return 1;
}