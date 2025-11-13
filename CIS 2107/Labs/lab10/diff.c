#include <stdio.h>
#include "lab10.h"

int diff(char *s1, char *s2){

  int length, length_1, length_2;
  int result = 0;

  length_1 = string_length(s1);
  length_2 = string_length(s2);

  if(length_1<length_2){
    length = length_2;
  }
  else{
    length = length_1;
  }

  for(int i = 0; i < length ;i++){
    if (s1[i] != s2[i]){
      result++;
    }
  }

  return result;
}
