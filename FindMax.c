#include <stdio.h>
#include <stdlib.h>

// Encontra o maior valor em um vetor

int findMax(int vetor[], int tamanho);

int main(void){
    const int tamanho = 5;  // Tamanho do vetor -1
    int vetor[] = {5, 74, 9, 100, 8};
    int maiorValor;

    maiorValor = findMax(vetor, tamanho-1);
    
    printf("\n O maior valor do vetor e: %d \n\n", maiorValor);

    system("pause");

    return 0;
}
int findMax(int vetor[], int tamanho){
    int maior;

    if(!tamanho){        // tamanho == 0
        return vetor[0];
    }else{
        maior = findMax(vetor, tamanho-1);
        if(maior > vetor[tamanho]){
            return maior;
        }else{
            return vetor[tamanho];
        }
    }
}