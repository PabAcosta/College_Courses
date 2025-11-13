#include <stdio.h>
#include "lab10.h"

int ends_with_ignore_case(char *s, char *suff){

  int x = string_length(s);
  int y = string_length(suff);

  if (y > x){
    return 0;
  }

  while(y > 0){
    x--;
    y--;

    char a = s[x];
    char b = suff[y];

    if (a >= 'A' && a <= 'Z') {
      a = a + 32;
    }
    if (b >= 'A' && b <= 'Z') {
      b = b + 32;
    }

    if (a != b) {
      return 0;
    }
  }
  
  return 1;
}
