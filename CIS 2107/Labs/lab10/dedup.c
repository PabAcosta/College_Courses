#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

char *dedup(char *s){

  int length = 0, read = 0, write = 0;
  int found;

  while(s[length] != '\0'){
    length++;
  }

  char *result = malloc(length + 1);
    
  if (result == NULL){
    return NULL;
  }

  while (s[read] != '\0') {
    char current = s[read];
    found = 0;

    for (int i = 0; i < write; i++) {
      if (result[i] == current){
        found = 1;
        break;
      }
    }

    if (!found) {
      result[write] = current;
      write++;
    }

    read++;
  }

  result[write] = '\0';
  return result;
}