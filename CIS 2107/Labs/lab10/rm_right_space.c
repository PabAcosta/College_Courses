#include <stdio.h>
#include "lab10.h"

void rm_right_space(char *s){

  int spaces = 0;
  
  while (s[spaces] != '\0') {
      spaces++;
  }

  spaces = spaces - 1;

  while (s[spaces] == ' ') {
    spaces--;
  }
  s[spaces+1] = '\0';
}