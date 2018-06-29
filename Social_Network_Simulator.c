#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
struct dates{
 int day;
 int month;
 int year;
};
struct access{
  char name[40], username[20];
  char password[30], confirm_password[30];
  char city[20], state[20], states_abbr[5]; //Abbr = abbreviation
  char gender[10], MarriedWith[40];
  int marital_status, security_code[3];
  struct dates birthday;
};
int main(void){
 system("cls");
 struct access people[100]; // Struct declaration
 void state_abbreviation(char x[],int *z); // Function declaration
 srand(time(NULL)); 
 // All variables used
 char log_username[30],log_password[30];
 char current_password[30];
 int test_state_exist = 0, j = 0;
 int code, i, k, p, option, w = 0;
 int check_security_code[3];
 int Option_changes, code_changes;
 
  do{ 
    printf("\n  ------------- MENU --------------- \n");
    printf("\n 1- Create an account\n 2- I already have an account (enter now) \n 3- Change information \n 4- Clean the screen\n 5- Exit\n --> ");
    scanf("%i",&option);
    switch(option){
      case 1:
        system("cls");
        printf("\n ***** Creating an accont *****\n");
        printf("\n Enter your name and surname: ");
        scanf(" %[^\n]s",people[j].name);
        while(true){
          printf(" Enter your username: ");
          scanf(" %[^\n]s",people[j].username);
          p = 0;
          //Checking if the username already exists
          for(i = 0; i < j; i++){
            if(strcmp(people[j].username,people[i].username) == 0){
              p++;
            }
          }
          if(p != 0){
            printf("\n --> *This username already exist, try a different one...\n\n\a");
          }else{
           break;
          }
        }
        while(true){
          printf(" Creat a password: ");
          scanf(" %[^\n]s",people[j].password);
          printf(" Confirm your password: ");
          scanf(" %[^\n]s",people[j].confirm_password);
          if(strcmp(people[j].password,people[j].confirm_password) == 0){
            break;
          }else{
            printf("\n --> The passwords don't match. Please re-enter a password again <--\n\n\a");
          }
        }
        while(true){
          printf("\n Gender:\n 1- Female\n 2- Male\n --> ");
          scanf(" %[^\n]s",people[j].gender);
          if(strcmp(people[j].gender,"1") == 0 || strcmp(people[j].gender,"2") == 0){
            break;
          }else
            printf("\n --> Invalid option. Please try again... <--\n\a");
        }
        while(true){
          printf("\n Marital status: \n");
          printf(" 1- Single\n 2- Married\n 3- Separated\n 4- Divorced\n 5- Widowed\n --> ");
          scanf("%i",&people[j].marital_status);
          if(people[j].marital_status == 1 || people[j].marital_status == 2 || people[j].marital_status == 3 ||
          people[j].marital_status == 4 || people[j].marital_status == 5)
            break;
          else
            printf("\n --> Invalid option. Please try again... <--\n\n\a");
        }
        if(people[j].marital_status == 2){
          printf(" With: ");
          scanf(" %[^\n]s",people[j].MarriedWith);
        }
        printf("\n Living in:");
        printf("\n City: ");
        scanf(" %[^\n]s",people[j].city);
        while(true){
          test_state_exist = 0;
          printf(" State: ");
          scanf(" %[^\n]s",people[j].state);
          printf(" Abbreviation: ");
          state_abbreviation(people[j].state,&test_state_exist); // Calling the function to get the abbreviation
          if(test_state_exist == 0)
            break;
          else
            printf(" *Not found*");
            printf("\n ---> Brazil has no state with this name, please try gain.... <---\n\a");
        }
        printf("\n\n Birthday: \n");
        while(true){
          fflush(stdin);
          printf(" Day: ");
          scanf(" %i",&people[j].birthday.day);
          if(people[j].birthday.day > 0 && people[j].birthday.day <= 31)
           break;
          else
           printf("\n *The day you entered is incorrect \n\n\a");
        }
        while(true){
          fflush(stdin);
          printf(" Month: ");
          scanf(" %i",&people[j].birthday.month);
          if(people[j].birthday.month > 0 && people[j].birthday.month <= 12)
           break;
          else
           printf("\n *The month you entered is incorrect \n\n\a"); 
        }
        while(true){
          fflush(stdin);
          printf(" year: ");
          scanf(" %i",&people[j].birthday.year);
          if(people[j].birthday.year > 1900 && people[j].birthday.year <= 2018)
           break;
          else
           printf("\n *There's no way you were born this year\n\n\a");   
        }
        printf("\n ---------------------------------------------------------------------------------------------------------------- ");
        printf("\n #Your account has been successfully created!\n");
        printf(" #This is your code: --> %i <--\n",j + 1);
        printf(" \"With this code, you'll be able not only to enter your account, but also to change any of its information later\"\n");
        printf(" #Your security code: --> ");
        for(i = 0; i < 3; i++){
         people[j].security_code[i] = rand() % 10;
        }
        for(i = 0; i < 3; i++){
          printf("%i",people[j].security_code[i]);
        }
        printf(" <-- \n \"In case you forget your password, you'll need this code in order to change it\"\n");
        printf(" ---------------------------------------------------------------------------------------------------------------- \n\n\n\n\n");
  
        j++;
        break;
      case 2:
        system("cls");
        printf("\n\t ________logging in________ \n");
        printf("\n >> Enter '0' to go back to Menu <<\n");
        while(true){
          printf("\n Enter your code: ");
          scanf("%i",&code);
          if(code > 0 && code <= j || code == 0)
           break;
          else 
           printf("\n *This code doesn't exist!!!\n\a");
        }
        if(code == 0){
         system("cls");
         break;
        }
        printf("\n >> Enter \"return\" to go back to Menu <<\n\n");
        while(true){
          fflush(stdin);
          printf(" Enter your username: ");
          scanf(" %[^\n]s",log_username);
          k = 0;
          for(i = 0; i <= j; i++){
            if(strcmp(log_username,people[i].username) == 0 || stricmp(log_username,"return") == 0 ){
              k++;
            }
          }
          if(k == 0){
           printf("\n *This username doesn't exist!!!\n\n\a");
          }else
           break;
        }
        if(stricmp(log_username,"return") == 0){
          system("cls");
          break;
        }
        while(true){
          printf(" Enter your password: ");
          scanf(" %[^\n]s",log_password);
          // Showing user information (logged in)
          if(strcmp(people[code - 1].username,log_username) == 0 && strcmp(people[code-1].password,log_password) == 0){
            system("cls");
            printf("\n -------------------------------------\n");
            printf("\n| User name: %s (%s) \n",people[code-1].name,people[code-1].username);
            printf("| Age: %i", 2018-people[code-1].birthday.year);
            if(people[code-1].birthday.day < 10 && people[code-1].birthday.month < 10){
              printf(" (0%i/0%i/%i) \n",people[code-1].birthday.day,people[code-1].birthday.month,people[code-1].birthday.year);
            }else if (people[code-1].birthday.day < 10 && people[code-1].birthday.month > 10){
              printf(" (0%i/%i/%i) \n",people[code-1].birthday.day,people[code-1].birthday.month,people[code-1].birthday.year);
            }else if(people[code-1].birthday.day > 10 && people[code-1].birthday.month < 10){
              printf(" (%i/0%i/%i) \n",people[code-1].birthday.day,people[code-1].birthday.month,people[code-1].birthday.year);
            }else{
              printf(" (%i/%i/%i) \n",people[code-1].birthday.day,people[code-1].birthday.month,people[code-1].birthday.year);
            }

            printf("| Marital status: ");
            if(people[code - 1].marital_status == 1)
              printf("Single\n");
            else if(people[code - 1].marital_status == 2)
              printf("Married with %s\n",people[code - 1].MarriedWith);
            else if(people[code - 1].marital_status == 3)
              printf("Separated\n");
            else if(people[code - 1].marital_status == 4)
              printf("Divorced\n");
            else
              printf("Widowed\n");
              
            printf("| City: %s - ",people[code-1].city);
            state_abbreviation(people[code-1].state,&test_state_exist); // Calling the function to get the abbreviation

            if(strcmp(people[code-1].gender,"1") == 0){
             printf("\n| Gender: Female \n");
             printf("\n -------------------------------------\n\n\n\n");
            }else{
             printf("\n| Gender: Male \n");
             printf("\n -------------------------------------\n\n\n\n");
            }
            break;
          }else if(stricmp(log_password,"return") == 0){
            system("cls"); 
            break;
          }else if(stricmp(log_password,"forgot") == 0){
            // Changing password due to forgetfulness
            while(true){
              w=0;
              printf("\n Enter your security code:\n");
              for(i = 0; i < 3; i++){
               printf(" Number %i: ", i+1);
               scanf("%i",&check_security_code[i]);
              }
              for(i = 0; i < 3; i++){
                if(people[code-1].security_code[i] != check_security_code[i]){
                  w++;
                }
              }
              if(w == 0)
               break;
              else 
               printf("\n --> Wrong security code... <--\n\a"); 
            }
            while(true){
              printf("\n Enter your new password: ");
              scanf(" %[^\n]s",people[code - 1].password);
              printf(" Confirm your new password: ");
              scanf(" %[^\n]s",people[code - 1].confirm_password);
              if(strcmp(people[code - 1].password,people[code - 1].confirm_password) == 0){
               printf("\n  ||Your password has been successfully changed||\n\n");
               break;
              }else
               printf("\n --> Passwords don't match. Please re-enter a new password again <--\a");
              printf("\n");
            }

          }else{
            printf("\n * The password you entered is incorrect!!!");
            printf("\n * Forgot your password? Enter \"forgot\" and change it right way!\n\n\a");
          }
        }

        break;
      // Case that changes information
      case 3:
        while(true){
          printf("\n Enter your code, so that you can change your information: ");
          scanf("%i",&code_changes);
          if(code_changes > 0 && code_changes <= j)
           break;
          else
            printf("\n *This code doesn't exist!!!\n\a");   
        }
        system("cls");
        do{
          printf("\n ============= Changing information =================\n");
          printf("\n What do you want to change? \n");
          printf(" 1- Name\n 2- Password\n 3- City/State\n 4- Marital status\n 5- Birthday\n 6- Username\n 7- Exit\n --> ");
          scanf("%i",&Option_changes);
          
          switch(Option_changes){
            case 1:
              printf("\n Enter your new name and surname: ");
              scanf(" %[^\n]s",people[code_changes - 1].name);
              printf(" ### Your name has been successfully changed ###\n");
              break;
            case 2:
              while(true){
                printf(" Enter your current password: ");
                scanf(" %[^\n]s",current_password);
                if(strcmp(current_password,people[code_changes - 1].password) == 0)
                 break;
                else
                 printf("\n *This is not your password, please enter your correct password!\n\n\a");
              }
              printf("\n Enter your new password: ");
              scanf(" %[^\n]s",people[code_changes - 1].password);
              printf(" ### Your password has been successfully changed ###\n");
              break;
            case 3:
              printf("\n Enter your new:\n");
              printf(" City: ");
              scanf(" %[^\n]s",people[code_changes -1].city);
              while(true){
                test_state_exist = 0;
                printf(" State: ");
                scanf(" %[^\n]s",people[code_changes - 1].state);
                printf(" Abbreviation: ");
                state_abbreviation(people[code_changes - 1].state,&test_state_exist); // Calling the function to get the abbreviation
                if(test_state_exist == 0)
                  break;
                else
                  printf(" *Not found*");
                  printf("\n ---> Brazil has no state with this name, please try gain.... <---\n\a");
              }
              printf("\n ### Your city/state has been successfully changed ###\n\n");
              break;
            case 4:
              while(true){
                printf("\n Enter your new marital status: \n");
                printf(" 1- Single\n 2- Married\n 3- Separated\n 4- Divorced\n 5- Widowed\n --> ");
                scanf("%i", &people[code_changes - 1].marital_status);
                if(people[code_changes - 1].marital_status == 1 || people[code_changes - 1].marital_status == 2 ||
                people[code_changes - 1].marital_status == 3 || people[code_changes - 1].marital_status == 4 || people[code_changes - 1].marital_status == 5)
                 break;
                else
                 printf("\n --> Invalid option. Please try again... <--\n\n\a");
              }
              if(people[code_changes - 1].marital_status == 2){
                printf(" With: ");
                scanf(" %[^\n]s",people[code_changes - 1].MarriedWith);
              }
              printf("\n ### Your marital status has been successfully changed ###\n\n");
              break;
            case 5:
              printf("\n Enter your new birthday: \n");
              while(true){
                fflush(stdin);
                printf(" Day: ");
                scanf(" %i",&people[code_changes - 1].birthday.day);
                if(people[code_changes - 1].birthday.day > 0 && people[code_changes - 1].birthday.day <= 31)
                break;
                else
                printf("\n *The day you entered is incorrect \n\n\a");
              }
              while(true){
                fflush(stdin);
                printf(" Month: ");
                scanf(" %i",&people[code_changes - 1].birthday.month);
                if(people[code_changes - 1].birthday.month > 0 && people[code_changes - 1].birthday.month <= 12)
                break;
                else
                printf("\n *The month you entered is incorrect \n\n\a"); 
              }
              while(true){
                fflush(stdin);
                printf(" year: ");
                scanf(" %i",&people[code_changes - 1].birthday.year);
                if(people[code_changes - 1].birthday.year > 1900 && people[code_changes - 1].birthday.year <= 2018)
                break;
                else
                printf("\n *There's no way you were born this year\n\n\a");   
              }
              printf("\n ### Your birthday has been successfully changed ###\n\n");
              break;
            case 6:
              printf("\n Enter your new username: ");
              scanf(" %[^\n]s",people[code_changes - 1].username);
              printf("\n ### Your username has been successfully changed ###\n\n");
              break;
            case 7:
              system("cls");
              break;
            default:
              printf("\n --> Invalid option. Please try again... <--\n\a");
              break;
          }
        }while(Option_changes != 7);

        break;
      case 4:
        system("cls");

        break;
      case 5:
        printf("\n Finishing...\n");

        break;
      default:
        printf("\n --> Invalid option. Please try again... <--\n\a");
    }

  }while(option != 5);

  return 0;
}
void state_abbreviation(char x[],int *z){
 char abbreviation[5];

  if(stricmp(x,"Acre") == 0){
    strcpy(abbreviation,"AC");
  }else if(stricmp(x,"Alagoas") == 0){
    strcpy(abbreviation,"AL");
  }else if(stricmp(x,"Amapa") == 0){
    strcpy(abbreviation,"AP");
  }else if(stricmp(x,"Amazonas") == 0){
    strcpy(abbreviation,"AM");
  }else if(stricmp(x,"Bahia") == 0){
    strcpy(abbreviation,"BA");
  }else if(stricmp(x,"Ceara") == 0){
    strcpy(abbreviation,"CE");
  }else if(stricmp(x,"Distrito Federal") == 0){
    strcpy(abbreviation,"DF");
  }else if(stricmp(x,"Espirito Santo") == 0){
    strcpy(abbreviation,"ES");
  }else if(stricmp(x,"Goias") == 0){
    strcpy(abbreviation,"GO");
  }else if(stricmp(x,"Maranhao") == 0){
    strcpy(abbreviation,"MA");
  }else if(stricmp(x,"Mato Grosso") == 0){
    strcpy(abbreviation,"MT");
  }else if(stricmp(x,"Mato Grosso do Sul") == 0){
    strcpy(abbreviation,"MS");
  }else if(stricmp(x,"Minas Gerais") == 0){
    strcpy(abbreviation,"MG");
  }else if(stricmp(x,"Para") == 0){
    strcpy(abbreviation,"PA");
  }else if(stricmp(x,"Paraiba") == 0){
    strcpy(abbreviation,"PB");
  }else if(stricmp(x,"Parana") == 0){
    strcpy(abbreviation,"PR");
  }else if(stricmp(x,"Pernambuco") == 0){
    strcpy(abbreviation,"PE");
  }else if(stricmp(x,"Piaui") == 0){
    strcpy(abbreviation,"PI");
  }else if(stricmp(x,"Rio de Janeiro") == 0){
    strcpy(abbreviation,"RJ");
  }else if(stricmp(x,"Rio Grande do Norte") == 0){
    strcpy(abbreviation,"RN");
  }else if(stricmp(x,"Rio Grande do Sul") == 0){
    strcpy(abbreviation,"RS");
  }else if(stricmp(x,"Rondonia") == 0){
    strcpy(abbreviation,"RO");
  }else if(stricmp(x,"Roraima") == 0){
    strcpy(abbreviation,"RR");
  }else if(stricmp(x,"Santa Catarina") == 0){
    strcpy(abbreviation,"SC");
  }else if(stricmp(x,"Sao Paulo") == 0){
    strcpy(abbreviation,"SP");
  }else if(stricmp(x,"Sergipe") == 0){
    strcpy(abbreviation,"SE");
  }else if(stricmp(x,"Tocantins") == 0){
   strcpy(abbreviation,"TO");
  }else
    *z = 1;
    
  if(*z == 0){
   printf("%s",abbreviation);
  }
}