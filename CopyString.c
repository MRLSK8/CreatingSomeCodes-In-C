#include <stdio.h>

void copyString(char *string1, char *string2);

int main(void){

    char string1[20];
    char *string2 = "String de teste";
   
    copyString(string1, string2);

    printf("\n String1 = %s \n", string1);
    printf("\n String2 = %s \n", string2);

    return 0;
}
void copyString(char *string1, char *string2){

    // Option 1
    for(;*string1 = *string2; string1++, string2++);

    // Or
    
    // Option 2
    while(*string1++ = *string2++);

}