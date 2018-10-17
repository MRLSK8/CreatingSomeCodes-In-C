#include <stdio.h>
#include <string.h>

// Protótipos das funções
void my_strcpy(char *s1, char *s2);
void my_strcat(char *s1, char *s2);

int main(void){
    char string1[40];
    char string2[40];

    // Input
    printf("\n Digite a primeira string: ");
    scanf("%s", string1);

    printf("\n Digite a segunda string: ");
    scanf("%s", string2);

    // Output

    my_strcpy(string1, string2);
    //my_strcat(string1, string2);

    printf("\n Copiada : %s\n", string1);
    //printf("\n Concatenada : %s\n", string1);

 return 0;
}
void my_strcpy(char *s1, char *s2){
   int i = 0;

   for(;*(s2 + i) != '\0'; i++){
       *(s1 + i) = *(s2 + i);
    }
   *(s1 + i) = '\0';
}
void my_strcat(char *s1, char *s2){
   int i = strlen(s1);
   int aux = 0;

   for(;*(s2 + aux) != '\0'; i++, aux++){
       *(s1 + i) = *(s2 + aux);
    }
   *(s1 + i) = '\0';
}






