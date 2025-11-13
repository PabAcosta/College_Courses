#include <stdio.h>
#include "lab10.h"

int num_in_range(char *s1, char b, char t){

  int result = 0;

  while(*s1){
    if(*s1 >= b && *s1 <= t){
      result++;
    } 
    s1++;
  }
  return result;
}