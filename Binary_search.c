#include <stdio.h>
#include <conio.h>
// Function prototype
int Binary_search(int vetor[], int left, int right, int value);

int main(void) {
   int array[] = {4, 7, 9, 10, 19, 24, 38, 57, 61, 70, 73, 94};
   int left = 0, right = (sizeof(array)/sizeof(int)) - 1, value;
   int result;

   printf("\n Enter a number to be searched for: ");
   scanf("%d", &value);
  
   result = Binary_search(array, left, right, value);
   if(result != -1)
       printf("\n The number %d is at the position %d of the array!!! \n", value, Binary_search(array, left, right, value));
   else
       printf("\n Number not found!!! \n\n");

    getch();
   return 0;
}
int Binary_search(int array[], int left, int right, int value){
  
   while(left <= right){
       // Middle of the array
       int middle = (left + right) / 2;

       if(array[middle] < value){
            left = middle + 1;
       }else if(array[middle] > value){
            right = middle - 1;
       }else
           return middle;  // if it's found, it returns the position where it is in the array
   }

   return -1;  // in case of the number was not found, it returns -1 
}