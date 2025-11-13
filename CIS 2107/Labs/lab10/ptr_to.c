#include <stdio.h>
#include "lab10.h"

char *ptr_to(char *h, char *n){

  int length = 0;
  int size = 0;

  if (n[0] == '\0') {
    return h;
  }

  while (h[length] != '\0'){
    size = 0;
    while (n[size] != '\0'){
      if(h[length + size] != n[size]){
        break;
      }
      size++;
    }
    if (n[size] == '\0'){
      return &h[length];
    }
    length++;
  }

  return NULL;
}