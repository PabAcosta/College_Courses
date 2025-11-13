#include <stdio.h>
#include "lab10.h"

void shorten(char *s, int new_len){

  int length = 0;

  while(s[length] != '\0'){
    length++;
  }
  
  if (length <= new_len){
    return;
  }

  s[new_len] = '\0';
}