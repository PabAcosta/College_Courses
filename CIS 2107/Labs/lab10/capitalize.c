#include <stdio.h>
#include "lab10.h"

void capitalize(char *s){

  int position = 0;
  
  while(s[position] != '\0'){
    if ((position == 0  && s[position] != ' ')||(s[position-1] == ' ' && s[position] != ' ')){
      if (s[position] >= 'a' && s[position] <= 'z'){
        s[position] = s[position] - 32;
      }
    }
    position++;
  }
}
