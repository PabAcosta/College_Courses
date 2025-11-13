#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

void take_last(char *s, int n){

  int length = 0;

  while(s[length] != '\0'){
    length++;
  }

  if (length <= n){
    return;
  }

  for(int i = 0; i < n; i++){
    s[i] = s[length - n +i];
  }
  
  s[n] = '\0';
}