#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
int main(void){ 
  system("cls");
  int op,num1,num2,firstNum,secondNum,result_LCD,result_GCD,number;
  int a,b,c,test = 0;
  float root1,root2; 
  // Declaration of functions
  void Bhaskara(int a, int b, int c,float *x1, float *x2,int *teste);
  void Binary(int number);
  int GCD(int x,int y);
  int LCM(int x,int y);

  do{
    printf("\n\t========== MENU ==========\n");
    printf(" 1- To Calculate Greatest Common Divisor(GCD)\n 2- To Calculate Least Common Multiple(LCM)\n");
    printf(" 3- To Turn From Decimal Into Binary\n 4- To Calculate Bhaskara\n 5- Exit\n ---> ");
    scanf("%i",&op);
   
    switch(op){
      case 1:
        printf("\n --------- Type '0' to exit -----------\n");
        while(true){
          printf("\n --- Calculating GCD between two numbers ---\n");
          printf(" Enter the first number: ");
            scanf("%d",&num1);
          if(num1 == 0){
            system("cls");
           break;
          }
          printf(" Enter the second number: ");
            scanf("%d",&num2);
          if(num2 == 0){
            system("cls");
           break;
          } 
          result_GCD = GCD(num1,num2); 
          printf("\n The 'GCD' between %i and %i is: %i\n",num1,num2,result_GCD);
        }
        break;
      case 2:
        printf("\n --------- Type '0' to exit -----------\n");
        while(true){  
          printf("\n --- Calculating LCM between two numbers ---\n");
          printf(" Enter the first number: ");
            scanf("%d",&firstNum);
          if(firstNum == 0){
            system("cls");
           break;
          }
          printf(" Enter the second number: ");
            scanf("%d",&secondNum);
          if(secondNum == 0){
            system("cls");
           break;
          }
          result_LCD = LCM(firstNum,secondNum);  
          printf("\n The 'LCM' between %i and %i is: %i\n",firstNum,secondNum,result_LCD); 
        }
        break;
      case 3:
        printf("\n --------- Type '0' to exit -----------\n");
        while(true){
          printf("\n Enter a integer number: ");
          scanf("%i",&number);
          if(number == 0){
            system("cls");
            break;
          }
          Binary(number); 
        }
        break;
      case 4:
        printf("\n ===== Bhaskara Calculation =======\n");
        printf("\n ----> ax^2 + bx^2 + c = 0 <----\n");
        printf("\n Enter the term 'a': ");
        scanf("%i",&a);
        printf("\n Enter the term 'b': ");
        scanf("%i",&b);
        printf("\n Enter the term 'c': ");
        scanf("%i",&c);

        Bhaskara(a,b,c,&root1,&root2,&test);

        if(test == 1)
        printf("\n The roots are: x1 = %.1f and x2 = %.1f\n",root1,root2);
        break;
      case 5:
       printf("\n Fishining...\n");
       break;
      default:
       printf("\n ## Error ##\n\a");
       break;
    }
  }while(op != 5);    

  return 0;
}
int LCM(int x,int y){
  int result = 1, i = 2;

  while(true){
    if(x == 1 && y == 1)
    break;
    
    if(x % i == 0 && y % i == 0){
      result *= i;
      x /= i;
      y /= i;
    }else if(x % i == 0 || y % i == 0){
      result *= i;
      if(x%i == 0){
      x /= i;
      }
      if(y%i == 0){
      y /= i;
      }
    }else{
       i++; 
    }      
  } 
  return result;
}
int GCD(int x, int y){
  int result = 1, i = 2;

  while(x != 1 && y != 1){
    if(x % i == 0 && y % i == 0){
      x /= i;
      y /= i;
      result *= i;
    }else{
      if(x % i == 0){
        x /= i;
      }else if(y % i == 0){
        y /= i;
      }
      i++;
    }
  }
  return result;
}
void Binary(int number){     
 int array[50],counter = 0;

  while(number >= 1){
    array[counter] = number%2;
    number /= 2;
    counter++;
  }
  printf("----> ");
  for(int i = counter-1; i >= 0; i--){
    printf(" %i",array[i]);
  }  
}
void Bhaskara(int a, int b, int c,float *x1 ,float *x2,int *test){
  float delta = pow(b,2) - 4 * a * c;

  if(delta < 0){
    printf("\n #There are no real roots!#\a\n");
  }else{
    delta = sqrt(pow(b,2) - 4 * a * c);

    *x1 = (-b + delta) /(2 * a);
    *x2 = (-b - delta) /(2 * a);
    *test = 1;
  }
}