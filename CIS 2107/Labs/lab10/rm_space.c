#include <stdio.h>
#include "lab10.h"

 void rm_space(char *s){

  int spaces = 0;
  int characters = 0;
  int i = 0;

  //left side
  while (s[spaces] == ' ') {
      spaces++;
  }

  while (s[characters]) {
      s[characters++] = s[spaces++];
  }

  s[characters] = '\0';

  //right side
  
  while (s[i] != '\0') {
      i++;
  }

  i = i - 1;

  while (s[i] == ' ') {
    i--;
  }
  s[i+1] = '\0';
 }