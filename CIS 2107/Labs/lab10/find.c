#include <stdio.h>
#include "lab10.h"

int find(char *h, char *n){

  int length = 0;
  int size = 0;
  int result = -1;

  while (h[length] != '\0') {

    while (n[size] != '\0') {

      if(h[length + size] != n[size]){
        break;
      }
      size++;
    }

    if (n[size] == '\0') {
      result = length;
      break;
    }
  
    size = 0;
    length++;
  }

  return result;
}