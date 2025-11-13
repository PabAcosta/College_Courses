#include <stdio.h>
#include "lab10.h"

void rm_left_space(char *s){

  int spaces = 0;
  int characters = 0;

  while (s[spaces] == ' ') {
      spaces++;
  }

  //Replaces spaces with other characters 
  while (s[characters]) {
      s[characters++] = s[spaces++];
  }

  s[characters] = '\0';
}