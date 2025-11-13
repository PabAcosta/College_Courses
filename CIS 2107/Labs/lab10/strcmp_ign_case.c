#include <stdio.h>
#include "lab10.h"

int strcmp_ign_case(char *s1, char *s2){

  int position = 0;
  char letter1, letter2;

  while (s1[position] != '\0' || s2[position] != '\0') {

    letter1 = s1[position];
    letter2 = s2[position];

    if (letter1 >= 'A' && letter1 <= 'Z') {
      letter1 += 32;
    }
    if (letter2 >= 'A' && letter2 <= 'Z') {
      letter2 += 32;
    }
    // 1 s1 after s2
    if (letter1 > letter2) {
      return 1;
    } 
    // -1 s2 after s1
    else if (letter1 < letter2){
      return -1;
    }
    position++;
  }
  // 0 equal
  return 0;
}