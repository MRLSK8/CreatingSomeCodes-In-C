#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipos das funções
int soma(int x, int y);
int sub(int x, int y);
float divi(int x, int y);
int multiplica(int x, int y);

enum{vezes= 1, mais , menos, divisao};

int main(int argc, char *argv[]){
  int op;
  system("cls");
  printf("\n\n");

  if(stricmp(argv[2], "/") == 0){
    op = 4;
  }else if(stricmp(argv[2], "-") == 0){
    op = 3;
  }else if(stricmp(argv[2], "+") == 0){
    op = 2;
  }else if(stricmp(argv[2], "x") == 0){
    op = 1;
  }else{
    printf(" Operacao invalida!\n\n Simbulos aceitos:\n + = soma\n x = Multiplicacao\n - = Subtracao\n / = Divisao\n\n");
  }

  switch(op){
    case mais:
      printf(" Resultado: %d \n",  soma(atoi(argv[1]), atoi(argv[3])));
    break;
    case menos:
      printf(" Resultado: %d \n", sub(atoi(argv[1]), atoi(argv[3])));
    break;
    case divisao:
      printf(" Resultado: %.3f \n", divi(atoi(argv[1]), atoi(argv[3])));
    break;
    case vezes:    
      printf(" Resultado: %d \n", multiplica(atoi(argv[1]), atoi(argv[3])));
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
float divi(int x, int y){
  return (float)x / y;
}