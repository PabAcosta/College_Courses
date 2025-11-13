#include <stdio.h>  
#include "lab10.h"

int string_length(char *s) {
  int length = 0;
  while (s[length] != '\0') {
    length++;
  }
  return length;
}