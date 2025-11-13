#include <stdio.h>
#include "lab10.h"

int len_diff(char *s1, char *s2){

  int length, length_1, length_2;

  length_1 = string_length(s1);
  length_2 = string_length(s2);

  if(length_1<length_2){
    length = length_2 - length_1; 
  }
  else{
    length = length_1 - length_2;
  }

  return length;
  
}