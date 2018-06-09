#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(void){
  system("cls");
  int a = 0,b = 0,c = 0,d = 0,e = 0,f = 0;
  char character; // This will store the "/"
  int op;
  // Functions declaration 
  void Sum(int a,int b,int c,int d,int *e,int *f);
  void Subtract(int a,int b,int c,int d,int *e,int *f);
  void Multiply(int a,int b,int c,int d,int *e,int *f);
  void Divide(int a,int b,int c,int d,int *e,int *f);
  
  while(op != 7){
    printf("\n ======== MENU ========\n");
    printf(" 1- Enter fractions\n 2- To sum fractions\n 3- To subtract fractions\n 4- To multiply fractions\n");
    printf(" 5- To divide fractions\n 6- To clean the screen\n 7- Exit\n ---> ");
    scanf("%i",&op);
    switch(op){
      case 1:
        while(true){
          printf("\n Enter fraction 1 (Example: '2/8'):\n ");
          scanf("%i%c%i",&a,&character,&b); 
          if(b != 0){
            fflush(stdin);
            printf("\n Enter fraction 2 (Example: '2/8'):\n ");
            scanf("%i%c%i",&c,&character,&d);
            if(d != 0)
            break;
            else{
              printf("\n-----\n ** it can not have a zero('0') in the denominator,Try again! **\a\n-----\n");
            }
          }else
          printf("\n-----\n ** it can not have a zero('0') in the denominator,Try again! **\a\n-----\n");
        }
       break;
      case 2:
        if(a == 0 && b == 0 && c == 0 && d == 0){
         printf("\n Error! There are no fractions to calculate!\a\n");
         break;
        }
        Sum(a,b,c,d,&e,&f);
        if(f == 1)
        printf("\n (%i/%i) + (%i/%i) = %i\n",a,b,c,d,e);
        else
        printf("\n (%i/%i) + (%i/%i) = %i/%i\n",a,b,c,d,e,f);
        break;
      case 3:
        if(a == 0 && b == 0 && c == 0 && d == 0){
         printf("\n Error! There are no fractions to calculate!\a\n");
         break;
        }
        Subtract(a,b,c,d,&e,&f);
        if(f == 1)
        printf("\n (%i/%i) - (%i/%i) = %i\n",a,b,c,d,e);
        else
        printf("\n (%i/%i) - (%i/%i) = %i/%i\n",a,b,c,d,e,f);     
        break;
      case 4:
        if(a == 0 && b == 0 && c == 0 && d == 0){
         printf("\n Error! There are no fractions to calculate!\a\n");
         break;
        }
        Multiply(a,b,c,d,&e,&f);
        if(f == 1)
        printf("\n (%i/%i) x (%i/%i) = %i\n",a,b,c,d,e);
        else
        printf("\n (%i/%i) x (%i/%i) = %i/%i\n",a,b,c,d,e,f);
        break;
      case 5:
        if(a == 0 && b == 0 && c == 0 && d == 0){
         printf("\n Error! There are no fractions to calculate!\a\n");
         break;
        }
        Divide(a,b,c,d,&e,&f);
        if(f == 1)
        printf("\n (%i/%i) / (%i/%i) = %i\n",a,b,c,d,e);
        else
        printf("\n (%i/%i) / (%i/%i) = %i/%i\n",a,b,c,d,e,f);
        break;
      case 6:
        system("cls");
        break;
      case 7:
        printf("\n Finishing...\n");
        break;
      default:
        printf("\n **ERROR**\n Invalid option!\n\a");
        break;
    }
  }  
  return 0;
}
void Sum(int a,int b,int c,int d,int *e,int *f){
  *e = (b * c) + (d * a); //numerator (result)
  *f = b * d;             //denominator (result)
  void Simplify(int *e,int *f);
  Simplify(e,f); //Simplifying
}
void Subtract(int a,int b,int c,int d,int *e,int *f){
  *e =  (d * a) - (b * c); //numerator (result)
  *f = b * d;              //denominator (result)
  void Simplify(int *e,int *f);
  Simplify(e,f); //Simplifying
}
void Multiply(int a,int b,int c,int d,int *e,int *f){
  *e = a * c; //numerator (result)
  *f = b * d; //denominator (result)
  void Simplify(int *e,int *f);
  Simplify(e,f); //Simplifying
}
void Divide(int a,int b,int c,int d,int *e,int *f){
  *e = a * d; //numerator (result)
  *f = b * c; //denominator (result)
  void Simplify(int *e,int *f);
  Simplify(e,f); //Simplifying
}
void Simplify(int *e,int *f){
  for(int i = 10; i >= 1; i--){
    if(*f % i == 0 && *e % i == 0){
      *f /= i;
      *e /= i;
    }
  }
}