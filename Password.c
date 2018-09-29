#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
int main(void){
   char password[10];
   char letter;
   int i = 0, a;

   printf(" Rules:\n 1- Password must be between 6 to 10 characters in length;\n");
   printf(" 2- Password can not have any space;\n 3- Password must be alphanumeric (only letters and numbers);\n");
 
   printf("\n Password: ");
   while(true){
       letter = getch();        // gets the letter

        if(letter != 13 && letter != '\b' && letter != 32 &&  isalnum(letter) == 0){
             system("cls");
             printf("\n -_-  Your password must be alphanumeric (only letters and numbers); \a -_-\n");
             printf("\n Password: ");
             strcpy(password, " " );
             i = 0;
        }else  if(letter == 13){        // 13 = enter
             if(i < 6 || i > 10){
  	          system("cls");
                  printf("\n -_-  Your password must be between 6 to 10 characters in length \a -_-\n");
                  printf("\n Password: ");
                  strcpy(password," ");
                  i = 0;
	     }else{
	          password[i] = '\0';
                  break;
             }
        }else if(letter == 32){         // 32 = space
             system("cls");
             printf("\n -_-  You can't use space in your password! \a -_-\n");
             printf("\n Password: ");
             strcpy(password," "); 
             i = 0;
          
        }else if(letter != '\b' ){     // \b = backspace
             password[i] = letter;
             i++;
             printf("*");
        }else{
            system("cls");
            printf("\n Password: ");
            for(a = 1; a < i; a++){
                printf("*");
            }
            password[i-1] = ' ';
            i--;
        }
   }

   // printf("\n Your password = %s\n", password);
 
  getch();
  return 0;
}
