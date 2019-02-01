#include <stdio.h>

int findNumber(int arrays[], int numberToBeFind);

int main(void){
    int array[] = {2, 5, 8, 10, 15, 25, 1, 9, 17, 36, 55, 0, 42, 81, 77, 59, 11, 24, 69};
    int position, number = 36;

    position = findNumber(array, number);

    printf("\n The number %d is at position %d in the array\n\n", number, position);
    
    return 0;
}
int findNumber(int arrays[], int numberToBeFind){
    int a = 0, b = 9, c = 10, d = 18;

    while (a != b || c != d){
        if (arrays[a] == numberToBeFind)return a;
        if (arrays[b] == numberToBeFind)return b;
        if (arrays[c] == numberToBeFind)return c;
        if (arrays[d] == numberToBeFind)return d;
        a++;
        b--;
        c++;
        d--;
    }
    return -1;
}