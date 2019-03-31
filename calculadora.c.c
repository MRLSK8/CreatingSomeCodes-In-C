#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipos das funções
int soma(int x, int y);
int sub(int x, int y);
int divi(int x, int y);
int multiplica(int x, int y);

// Ponteiro pra função
int *pointer(int x, int y);

enum{vezes= 1, mais , menos, divisao};
int main(int argc, char *argv[]){
 int op;

  if(stricmp(argv[3], "/") == 0){
     op = 4;
  }else if(stricmp(argv[3], "-") == 0){
     op = 3;
  }else if(stricmp(argv[3], "+") == 0){
     op = 2;
  }else
      op = 1;

  switch(op){
    case mais:
           printf("\n %d \n",  soma(atoi(argv[1]), atoi(argv[3])));
    break;
    case menos:
           printf("\n %d \n", sub(atoi(argv[1]), atoi(argv[3])));
    break;
    case divisao:
           printf("\n %d \n", divi(atoi(argv[1]), atoi(argv[3])));
    break;
    case vezes:
          printf("\n TESTE2 \n");
           printf("%d\n", atoi(argv[2]));
           printf("%d\n", atoi(argv[1]));
          
          printf("\n %d \n", multiplica(atoi(argv[1]), atoi(argv[3])));
    break;
    default:
        printf("\n Operação invalida\n\n");
    break;
  }
  
   return 0;
}
int soma(int x, int y){
  return x + y;
}
int sub(int x, int y){
  return x - y;
}
int multiplica(int x, int y){
  return (x * y);
}
int divi(int x, int y){
  return x/y;
}