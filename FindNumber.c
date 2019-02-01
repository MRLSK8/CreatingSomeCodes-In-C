#include <stdio.h>

int findNumber(int arrays[], int numberToBeFind);

int main(void){
    int array[] = { 2, 5, 8, 10, 15, 25, 1, 9, 17, 36, 55, 0, 42, 81, 77, 59, 11, 24, 69, 
                    54951, 6521, 454, 1043, 122345, 25234, 1255, 9444, 46317, 31246, 55, 0243, 434522, 8321, 71247, 56559, 145341, 22344, 675789,
                    288, 7795, 8574, 107686, 134325, 22345, 57991, 9685, 118947, 32346, 054155, 0222, 486432, 84561, 7867, 5369, 2411, 23544, 645669,
                    8519518, 7575, 7578, 10234, 17685, 0025, 1324, 97967, 1765156, 30056, 5005, 07574, 4672, 7781, 75857, 58749, 14641, 33224, 62549,
                    27458, 735, 8743, 134630, 18547455, 2523625, 13453, 95684, 173567, 337536, 523785, 655155, 42, 817575, 73577, 523579, 186851, 27544, 695645};
    int position, number = 3;

    position = findNumber(array, number);

    printf("\n The number %d is at position %d in the array\n\n", number, position);
    scanf("%d", position);
    return 0;
}
int findNumber(int arrays[], int numberToBeFind){
    int a = 0, b = 37, c = 38, d = 75;

    while (a < b || c < d){
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