#include <stdio.h>
#include "lab10.h"

int all_letters(char *s) {
    
    int capital = 0; 
    int lowercase = 0;
    int result = 0;

    while(*s){

        if(*s >= 'A' && *s <= 'Z'){
            capital = 1;
        
        }
        else if (*s >= 'a' && *s <= 'z'){
            lowercase = 1;
        }
        
        if (capital == 1 && lowercase == 1){
            break;
        }
        
        s++;
    }

    result = capital-lowercase;

    if (result < 0){
        result = -result;
    }

    return result;
}