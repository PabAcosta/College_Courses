#include <stdio.h>
#include "lab10.h"

int is_empty(char *s){

  int length = 0;
  int result = 1;

  while(s[length] != '\0'){

    if(s[length] != ' '){
      result = 0;
      break;
    }
    length++;
  }

  return result;
}