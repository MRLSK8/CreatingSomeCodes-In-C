#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

#define COLOR_RED  "\033[31m"
#define COLOR_NONE "\033[0m"

struct dates{
 int month;
 int year;
 int day;
};
struct access{
  char city[20], state[20], states_abbr[5]; // abbr = abbreviation
  char password[30], confirm_password[30];
  char gender[10], marital_status[30];
  char name[40], username[30];
  int security_code[3], Age;
  struct dates birthday;
};

// Function prototypes
int compareByName(const void *compare1, const void *compare2);
int compareByAge(const void *compare1, const void *compare2);
void Change_info(struct access people[], int *total_on);
void Logging_in(struct access people[], int *total_on);
void save_user(struct access people[], int *num_cod);
void deletes(struct access people[], int *total_on);
void saveALL(struct access people[], int *total_on);
void showALL(struct access people[], int *total_on);
void Creat_account(struct access people[], int *j);
void state_abbreviation(char x[],int *z);
void gets_password(char password[]);
void gotoxy(int x, int y);
void Loading(void);
int Menu(void);

// Enumeration
enum{Creat = 1, LogInto, Change_Info, Delete_Account, Show_all_Accounts, Exit, Enter = 13, ESC = 27};

int main(void){
  system("cls");
  srand(time(NULL));  // Used to generate the security code

  // All variables used in main function
  char log_username[30], log_password[30];
  int i, test_state_exist = 0, option, aux,  total_on = 0;

  // Initial memory allocation
  struct access *people = (struct access *)calloc(1, sizeof(struct access));

  // Read all user's info
   FILE *arq1 = NULL;
   arq1 = fopen("UsersData.txt", "rb");
   size_t count;
   
  if(arq1 != NULL){
    while(fread(&people[total_on], sizeof(struct access), 1, arq1)){
      people = (struct access *)realloc(people, (total_on+2) * sizeof(struct access)); // Reallocating memory
      total_on++;
    }
  }
  fclose(arq1);  // Close the file

  do{
    option = Menu();

    switch(option){
       // Case to creat an account
       case Creat:
          people = (struct access *)realloc(people, (total_on+2) * sizeof(struct access)); // Reallocating memory
          Creat_account(people, &total_on);       
          break;
       // Case to log into your account
       case LogInto:
          Logging_in(people, &total_on);
          break;
       // Case which changes information
       case Change_Info:
          Change_info(people, &total_on);
          saveALL(people, &total_on);
          break;
       // Case to clean the screen
       case Delete_Account:
          deletes(people, &total_on);
          saveALL(people, &total_on);
          people = (struct access *)realloc(people, (total_on+1) * sizeof(struct access)); // Deallocating memory
          break;
       // Case to show user's information already registered
       case Show_all_Accounts:
          showALL(people, &total_on);
          break;
       // Case to exit the program
       case Exit:
          printf("\n\n  Finishing...\n");
          break;
    }
  }while(option != Exit);

  free(people); // deallocating
  Sleep(3000);
  return 0;
}
int compareByName(const void *compare1, const void *compare2){
  struct access *x = (struct access *)compare1;
  struct access *y = (struct access *)compare2;

  return (stricmp(x->name, y-> name));
}
int compareByAge(const void *compare1, const void *compare2){
  struct access *x = (struct access *)compare1;
  struct access *y = (struct access *)compare2;

  return ((x->Age > y->Age) ? 1 : -1);
}
void Change_info(struct access people[], int *total_on){
  int code_changes, Option_changes = 1, test_state_exist = 0;
  char current_password[20], change_username[30], change_password[30];;
  int auxMarital_status = 1, auxGender, i, auxCount;
  char auxMarriedWith[20], KeyGoBackToMenu;
  char key = ' ';
  bool exist = false;

  system("cls");
  
  while(true){
    fflush(stdin);
    printf(COLOR_RED"\n >> Enter \"return\" to go back to Menu <<\n\n"COLOR_NONE);
    printf(" Enter your username: ");
    scanf(" %[^\n]s", change_username);
    
    // Get out of the function
    if(stricmp(change_username,"return") == 0){
      system("cls");
      return;
    }
    exist = false;
    for(i = 0; i < *total_on; i++){
      if(stricmp(change_username, people[i].username) == 0){
        exist = true;
        code_changes = i;
        break;
      }
    }
    if(exist){
      break;
    }else{
      printf("\n -_- This username doesn't exist!!! -_-\n\n\a");
    }
  }

  exist = false;
  printf(COLOR_RED"\n\n >> Enter \"return\" to go back to Menu <<\n\n"COLOR_NONE);
  while(true){
    printf("\n Enter your password: \n");
    gets_password(change_password);
    if(stricmp(change_password, "return") == 0)break;

    if(stricmp(people[code_changes].password, change_password) == 0){
      system("cls");
      break;
    }else{
      printf(COLOR_RED"\n\n -_- The password you entered is incorrect!\n\n\a"COLOR_NONE);
    }
  }

  do{
    key = ' ';
    Option_changes = 1;
    system("cls");

    printf("\n ============= Changing information =================\n");
    printf("\n What do you want to change? \n");

    gotoxy(2, 5);
    printf(COLOR_RED" Name"COLOR_NONE);
    gotoxy(2, 7);
    printf(" Password");
    gotoxy(2, 9);
    printf(" City/State");
    gotoxy(2, 11);
    printf(" Marital status");
    gotoxy(2, 13);
    printf(" Birthday");
    gotoxy(2, 15);
    printf(" Username");
    gotoxy(2, 17);
    printf(" Exit");
    gotoxy(2, 5);

  while(key != Enter){
        key = getch();
        key = toupper(key);

        if(key != Enter)key = getch();
        key = toupper(key);

        // If "up arrow" pressed (option minus one)
        if(key == 'H'){
            if(Option_changes > 1){
                Option_changes--;
            }
        }
        // If "down arrow" pressed (option plus one)
        if (key == 'P'){
            if(Option_changes < 7){
                Option_changes++;
            }
        }

        if(Option_changes == 1){
            gotoxy(2, 5);
            printf(COLOR_RED" Name"COLOR_NONE);
            gotoxy(2, 7);
            printf(" Password");
            gotoxy(2, 9);
            printf(" City/State");
            gotoxy(2, 11);
            printf(" Marital status");
            gotoxy(2, 13);
            printf(" Birthday");
            gotoxy(2, 15);
            printf(" Username");
            gotoxy(2, 17);
            printf(" Exit");
            gotoxy(2, 5);
        }else if(Option_changes == 2){
            gotoxy(2, 5);
            printf(" Name");
            gotoxy(2, 7);
            printf(COLOR_RED" Password"COLOR_NONE);
            gotoxy(2, 9);
            printf(" City/State");
            gotoxy(2, 11);
            printf(" Marital status");
            gotoxy(2, 13);
            printf(" Birthday");
            gotoxy(2, 15);
            printf(" Username");
            gotoxy(2, 17);
            printf(" Exit");
            gotoxy(2, 7);
        }else if(Option_changes == 3){
            gotoxy(2, 5);
            printf(" Name");
            gotoxy(2, 7);
            printf(" Password");
            gotoxy(2, 9);
            printf(COLOR_RED" City/State"COLOR_NONE);
            gotoxy(2, 11);
            printf(" Marital status");
            gotoxy(2, 13);
            printf(" Birthday");
            gotoxy(2, 15);
            printf(" Username");
            gotoxy(2, 17);
            printf(" Exit");
            gotoxy(2, 9);
        }else if(Option_changes == 4){
            gotoxy(2, 5);
            printf(" Name");
            gotoxy(2, 7);
            printf(" Password");
            gotoxy(2, 9);
            printf(" City/State");
            gotoxy(2, 11);
            printf(COLOR_RED" Marital status"COLOR_NONE);
            gotoxy(2, 13);
            printf(" Birthday");
            gotoxy(2, 15);
            printf(" Username");
            gotoxy(2, 17);
            printf(" Exit");
            gotoxy(2, 11);
        }else if(Option_changes == 5){
            gotoxy(2, 5);
            printf(" Name");
            gotoxy(2, 7);
            printf(" Password");
            gotoxy(2, 9);
            printf(" City/State");
            gotoxy(2, 11);
            printf(" Marital status");
            gotoxy(2, 13);
            printf(COLOR_RED" Birthday"COLOR_NONE);
            gotoxy(2, 15);
            printf(" Username");
            gotoxy(2, 17);
            printf(" Exit");
            gotoxy(2, 13);
        }else if(Option_changes == 6){
            gotoxy(2, 5);
            printf(" Name");
            gotoxy(2, 7);
            printf(" Password");
            gotoxy(2, 9);
            printf(" City/State");
            gotoxy(2, 11);
            printf(" Marital status");
            gotoxy(2, 13);
            printf(" Birthday");
            gotoxy(2, 15);
            printf(COLOR_RED" Username"COLOR_NONE);
            gotoxy(2, 17);
            printf(" Exit");
            gotoxy(2, 15);
        }else{
            gotoxy(2, 5);
            printf(" Name");
            gotoxy(2, 7);
            printf(" Password");
            gotoxy(2, 9);
            printf(" City/State");
            gotoxy(2, 11);
            printf(" Marital status");
            gotoxy(2, 13);
            printf(" Birthday");
            gotoxy(2, 15);
            printf(" Username");
            gotoxy(2, 17);
            printf(COLOR_RED" Exit"COLOR_NONE);
            gotoxy(2, 17);
        }
    }

    system("cls");
    switch(Option_changes){
       case 1:
           printf(" Enter your new name and surname: ");
           scanf(" %[^\n]s",people[code_changes].name);
           
           printf(COLOR_RED"\n ### Your name has been successfully changed ###\n\n"COLOR_NONE);

           while(true){
              printf("\n Press \"Esc\" to go back to Menu\n");
              KeyGoBackToMenu = getch();
              if(KeyGoBackToMenu == ESC){
                  system("cls");
                  break;
              }else{
                  printf("\n -_- Wrong key pressed, try again -_- \n\n");
              }
           }
           system("cls");
           break;
       case 2:
           while(true){
           printf("\n Enter your current password: \n\n");
           gets_password(current_password);
           if(strcmp(current_password,people[code_changes].password) == 0)
              break;
           else
              printf("\n\n -_- This is not your password, please enter your correct password! -_-\n\n\a");
           }
           printf("\n\n Enter your new password: \n\n");
           gets_password(people[code_changes].password);
           system("cls");
           printf(COLOR_RED"\n\n\n ##### Your password has been successfully changed #####\n\n"COLOR_NONE);

           while(true){
              printf("\n Press \"Esc\" to go back to Menu\n");
              KeyGoBackToMenu = getch();
              if(KeyGoBackToMenu == ESC){
                  system("cls");
                  break;
              }else{
                  printf("\n -_- Wrong key pressed, try again -_- \n\n");
              }
           }
           system("cls");
           break;
       case 3:
           printf("\n Enter your new:\n");
           printf(" City: ");
           scanf(" %[^\n]s",people[code_changes].city);
           while(true){
               test_state_exist = 0;
               printf(" State: ");
               scanf(" %[^\n]s",people[code_changes].state);
               state_abbreviation(people[code_changes].state, &test_state_exist);
               if(test_state_exist == 0){
                  system("cls");
                  break;
               }else{
                  printf(" *Not found*");
                  printf("\n -_- Brazil has no state with this name, please try gain.... -_-\n\a");
               }
           }
           
           printf(COLOR_RED"\n ### Your city/state has been successfully changed ###\n\n"COLOR_NONE);

           while(true){
              printf("\n Press \"Esc\" to go back to Menu\n");
              KeyGoBackToMenu = getch();
              if(KeyGoBackToMenu == ESC){
                  system("cls");
                  break;
              }else{
                  printf("\n -_- Wrong key pressed, try again -_- \n\n");
              }
           }
           system("cls");
           break;
        case 4:
            printf("\n Enter your new marital status: \n");

            gotoxy(2, 3);
            printf(COLOR_RED" Single "COLOR_NONE);
            gotoxy(2, 5);
            printf(" Married");
            gotoxy(2, 7);
            printf(" Separated");
            gotoxy(2, 9);
            printf(" Divorced");
            gotoxy(2, 11);
            printf(" Widowed");
            gotoxy(2, 13);
            printf(" Dating");
            gotoxy(2, 3);

            while(key != Enter){
                  key = getch();
                  key = toupper(key);

                  if(key != Enter)key = getch();
                  key = toupper(key);

                  // If "up arrow" pressed (option minus one)
                  if(key == 'H'){
                      if(auxMarital_status > 1){
                          auxMarital_status--;
                      }
                  }
                  // If "down arrow" pressed (option plus one)
                  if (key == 'P'){
                      if(auxMarital_status < 6){
                          auxMarital_status++;
                      }
                  }

                  if(auxMarital_status == 1){
                      gotoxy(2, 3);
                      printf(COLOR_RED" Single "COLOR_NONE);
                      gotoxy(2, 5);
                      printf(" Married");
                      gotoxy(2, 7);
                      printf(" Separated");
                      gotoxy(2, 9);
                      printf(" Divorced");
                      gotoxy(2, 11);
                      printf(" Widowed");
                      gotoxy(2, 13);
                      printf(" Dating");
                      gotoxy(2, 3);
                  }else if(auxMarital_status == 2){
                      gotoxy(2, 3);
                      printf(" Single ");
                      gotoxy(2, 5);
                      printf(COLOR_RED" Married"COLOR_NONE);
                      gotoxy(2, 7);
                      printf(" Separated");
                      gotoxy(2, 9);
                      printf(" Divorced");
                      gotoxy(2, 11);
                      printf(" Widowed");
                      gotoxy(2, 13);
                      printf(" Dating");
                      gotoxy(2, 5);
                  }else if(auxMarital_status == 3){
                      gotoxy(2, 3);
                      printf(" Single ");
                      gotoxy(2, 5);
                      printf(" Married");
                      gotoxy(2, 7);
                      printf(COLOR_RED" Separated"COLOR_NONE);
                      gotoxy(2, 9);
                      printf(" Divorced");
                      gotoxy(2, 11);
                      printf(" Widowed");
                      gotoxy(2, 13);
                      printf(" Dating");
                      gotoxy(2, 7);
                  }else if(auxMarital_status == 4){
                      gotoxy(2, 3);
                      printf(" Single ");
                      gotoxy(2, 5);
                      printf(" Married");
                      gotoxy(2, 7);
                      printf(" Separated");
                      gotoxy(2, 9);
                      printf(COLOR_RED" Divorced"COLOR_NONE);
                      gotoxy(2, 11);
                      printf(" Widowed");
                      gotoxy(2, 13);
                      printf(" Dating");
                      gotoxy(2, 9);
                  }else if(auxMarital_status == 5){
                      gotoxy(2, 3);
                      printf(" Single ");
                      gotoxy(2, 5);
                      printf(" Married");
                      gotoxy(2, 7);
                      printf(" Separated");
                      gotoxy(2, 9);
                      printf(" Divorced");
                      gotoxy(2, 11);
                      printf(COLOR_RED" Widowed"COLOR_NONE);
                      gotoxy(2, 13);
                      printf(" Dating");
                      gotoxy(2, 11);
                  }else{
                      gotoxy(2, 3);
                      printf(" Single ");
                      gotoxy(2, 5);
                      printf(" Married");
                      gotoxy(2, 7);
                      printf(" Separated");
                      gotoxy(2, 9);
                      printf(" Divorced");
                      gotoxy(2, 11);
                      printf(" Widowed");
                      gotoxy(2, 13);
                      printf(COLOR_RED" Dating"COLOR_NONE);
                      gotoxy(2, 13);
                  }
              }
              system("cls");
              if(auxMarital_status == 1){
                  strcpy(people[code_changes].marital_status, "Single");
              }else if(auxMarital_status == 2){
                  printf(" Married to: ");
                  scanf(" %[^\n]s",auxMarriedWith);
                  strcpy(people[code_changes].marital_status, "Married to ");
                  strcat(people[code_changes].marital_status, auxMarriedWith);
              }else if(auxMarital_status == 3){
                  strcpy(people[code_changes].marital_status, "Separated");
              }else if(auxMarital_status == 4){
                  strcpy(people[code_changes].marital_status, "Divorced");
              }else if(auxMarital_status == 5){
                  strcpy(people[code_changes].marital_status, "Widowed");
              }else if(auxMarital_status == 6){
                  strcpy(people[code_changes].marital_status, "Dating");
              }
           
           printf(COLOR_RED"\n\n ### Your marital status has been successfully changed ###\n\n"COLOR_NONE);
           while(true){
              printf("\n Press \"Esc\" to go back to Menu\n");
              KeyGoBackToMenu = getch();
              if(KeyGoBackToMenu == ESC){
                  system("cls");
                  break;
              }else{
                  printf("\n -_- Wrong key pressed, try again -_- \n\n");
              }
           }
           system("cls");
           break;
        case 5:
           printf("\n Enter your new birthday: \n");
           while(true){
              fflush(stdin);
              printf(" Day: ");
              scanf(" %d",&people[code_changes].birthday.day);
              if(people[code_changes].birthday.day > 0 && people[code_changes].birthday.day <= 31)
                 break;
              else
                 printf("\n -_- The day you entered is incorrect -_-\n\n\a");
           }
           while(true){
              fflush(stdin);
              printf(" Month: ");
              scanf(" %d",&people[code_changes].birthday.month);
              if(people[code_changes].birthday.month > 0 && people[code_changes].birthday.month <= 12)
                 break;
              else
                 printf("\n -_- The month you entered is incorrect -_-\n\n\a");
           }
           while(true){
              fflush(stdin);
              printf(" year: ");
              scanf(" %d",&people[code_changes].birthday.year);
              if(people[code_changes].birthday.year > 1900 && people[code_changes].birthday.year <= 2018){
                people[code_changes].Age = 2018 - people[code_changes].birthday.year;
                 break;
              }else
                 printf("\n -_- There's no way you were born this year -_-\n\n\a");
           }
           printf(COLOR_RED"\n\n ### Your birthday has been successfully changed ###\n\n"COLOR_NONE);
           while(true){
              printf("\n Press \"Esc\" to go back to Menu\n");
              KeyGoBackToMenu = getch();
              if(KeyGoBackToMenu == ESC){
                  system("cls");
                  break;
              }else{
                  printf("\n -_- Wrong key pressed, try again -_- \n\n");
              }
           }
           system("cls");
           break;
        case 6:
          while(true){
            printf("\n Enter your new username: ");
            scanf(" %[^\n]s",people[code_changes].username);

            auxCount = 0;
            //Checking if the username already exists
            for(i = 0; i < *total_on, i != code_changes; i++){
              if(stricmp(people[code_changes].username, people[i].username) == 0){
                auxCount++;
                break;
              }
            }
            if(auxCount != 0){
                printf("\n -_- This username already exist, try a different one... -_-\n\n\a");
            }else
                break;
          }

           printf(COLOR_RED"\n\n ### Your username has been successfully changed ###\n\n"COLOR_NONE);
           while(true){
              printf("\n Press \"Esc\" to go back to Menu\n");
              KeyGoBackToMenu = getch();
              if(KeyGoBackToMenu == ESC){
                  system("cls");
                  break;
              }else{
                  printf("\n -_- Wrong key pressed, try again -_- \n\n");
              }
           }
           system("cls");
           break;
        case 7:
           system("cls");
           break;
        default:
           printf("\n -_- Invalid option. Please try again... -_-\n\a");
           break;
      }
    }while(Option_changes != 7);
}
void Logging_in(struct access people[], int *total_on){
   system("cls");
   char log_username[30], log_password[30], KeyGoBackToMenu;
   int code, w, i, test_state_exist = 0, check_security_code[3];
   bool exist = false;

    printf("\n\t________________________logging in___________________________ \n");
  
    printf(COLOR_RED"\n >> Enter \"return\" to go back to Menu <<\n\n"COLOR_NONE);
    while(true){
      fflush(stdin);
      printf(" Enter your username: ");
      scanf(" %[^\n]s",log_username);
      
      // Get out of the function
      if(stricmp(log_username,"return") == 0){
        system("cls");
        return;
      }
      exist = false;
      for(i = 0; i < *total_on; i++){
        if(stricmp(log_username, people[i].username) == 0){
          exist = true;
          code = i;
          break;
        }
      }
      if(exist){
        break;
      }else{
        printf("\n -_- This username doesn't exist!!! -_-\n\n\a");
      }
    }
    
    while(true){
      printf(COLOR_RED"\n Enter your password:" COLOR_NONE "\n (Enter \"forgot\" if you've forgotten your password!)\n\n");
      gets_password(log_password);
      // Showing user information (logged in)
      if(stricmp(people[code].password,log_password) == 0){
        Loading();
        system("cls");
        printf("\n -------------------------------------\n");
        printf("\n| Username: %s (%s) \n",people[code].name,people[code].username);
        printf("| Age: %i", 2018-people[code].birthday.year);
        printf(" (%0.2d/%0.2d/%d) \n",people[code].birthday.day,people[code].birthday.month,people[code].birthday.year);
        printf("| Marital status: %s\n", people[code].marital_status);
        printf("| City: %s - ",people[code].city);
        state_abbreviation(people[code].state,&test_state_exist); // Calling the function to get the abbreviation
        printf("\n| Gender: %s\n", people[code].gender);
        printf("\n -------------------------------------\n\n\n");

        while(true){
            printf(" Press \"Esc\" to go back to Menu\n");
            KeyGoBackToMenu = getch();
            if(KeyGoBackToMenu == ESC){
                system("cls");
                break;
            }else{
                printf("\n -_- Wrong key pressed, try again -_- \n\n");
            }
        }

        break;
      }else if(stricmp(log_password,"return") == 0){
        system("cls");
        break;
      }else if(stricmp(log_password,"forgot") == 0){
         // Changing password due to forgetfulness
         while(true){
           w = 0;
           printf("\n\n Enter your security code:\n");
           for(i = 0; i < 3; i++){
             printf(" Number %i: ", i+1);
             scanf("%d",&check_security_code[i]);
           }
           for(i = 0; i < 3; i++){
             if(people[code].security_code[i] != check_security_code[i]){
               w++;
               break;
             }
           }
           if(w == 0)
             break;
           else
             printf("\n -_- Wrong security code... -_-\n\a");
         }
         system("cls");
         while(true){
           printf(COLOR_RED"\n Enter your new password: \n\n"COLOR_NONE);
           gets_password(people[code].password);
           printf(COLOR_RED"\n Confirm your new password: \n\n"COLOR_NONE);
           gets_password(people[code].confirm_password);
           if(strcmp(people[code].password,people[code].confirm_password) == 0){
             system("cls");
             printf("\n\n #### Your password has been successfully changed ####\n\n\n\n");
             break;
           }else
             printf("\n -_- Passwords don't match. Please re-enter a new password again -_-\n\a");
          }

      }else{
        printf(COLOR_RED"\n\n\n -_- The password you entered is incorrect!\n");
        printf("-_- Forgot your password? Enter \"forgot\" and change it right way!\n\n\n\a"COLOR_NONE);
      }
    }
}
void save_user(struct access people[], int *num_cod){
  FILE *arq;
  arq = fopen("UsersData.txt", "ab");

  if(arq == NULL){
    printf("\n -_- Error opening file! -_-\n");
    system("pause");
    exit(true);
  }
  fwrite(&people[*num_cod], sizeof(struct access), 1, arq);

  fclose(arq);
}
void deletes(struct access people[], int *total_on){
    char KeyGoBackToMenu, delete_username[30], delete_password[30];
    bool exist = false;
    int auxCod, i;
    system("cls");

    printf(COLOR_RED"\n >> Enter \"return\" to go back to Menu <<\n\n"COLOR_NONE);
    while(true){
      fflush(stdin);
      printf(" Enter your username: ");
      scanf(" %[^\n]s", delete_username);
      
      // Get out of the function
      if(stricmp(delete_username,"return") == 0){
        system("cls");
        return;
      }
      exist = false;
      for(i = 0; i < *total_on; i++){
        if(stricmp(delete_username, people[i].username) == 0){
          exist = true;
          auxCod = i;
          break;
        }
      }
      if(exist){
        break;
      }else{
        printf("\n -_- This username doesn't exist!!! -_-\n\n\a");
      }
    }

    exist = false;
    printf(COLOR_RED"\n\n >> Enter \"return\" to go back to Menu <<\n\n"COLOR_NONE);
    while(true){
      printf("\n Enter your password: \n");
      gets_password(delete_password);
      if(stricmp(people[auxCod].password, delete_password) == 0){
        people[auxCod] = people[(*total_on) - 1];
        (*total_on)--;
        system("cls");
        printf("\n\n >> This account has been succefully deleted! <<\n\n");
        break;
      }else{
        printf(COLOR_RED"\n\n -_- The password you entered is incorrect!\n\n\a"COLOR_NONE);
      }
    }

    while(true){
        printf(" Press \"Esc\" to go back to Menu\n");
        KeyGoBackToMenu = getch();
        if(KeyGoBackToMenu == ESC){
            system("cls");
            break;
        }else{
            printf("\n -_- Wrong key pressed, try again -_- \n\n");
        }
    }

   
    system("cls");
}
void saveALL(struct access people[], int *total_on){
  FILE *arq;
  arq = fopen("UsersData.txt", "wb");

  if(arq == NULL){
    printf("\n -_- Error opening file! -_-\n");
    system("pause");
    exit(true);
  }
  fwrite(people, sizeof(struct access), *total_on, arq);

  fclose(arq);
}
void showALL(struct access people[], int *total_on){
  int test_state_exist = 0, auxSortby = 1;
  char KeyGoBackToMenu, key = ' ';
  size_t i;
  system("cls");
  
  // if there's no one registered, it shows a message
  if(*total_on == 0){
    printf(COLOR_RED"\n -_- There's nobody registered -_-\n\n"COLOR_NONE);
  }else{
    printf("\n Sort by: \n");

    gotoxy(2, 3);
    printf(COLOR_RED" Name"COLOR_NONE);
    gotoxy(2, 4);
    printf(" Age");
    gotoxy(2, 3);

    while(key != Enter){
        key = getch();
        key = toupper(key);
        
        if(key != Enter)key = getch();
        key = toupper(key);

        // If "up arrow" pressed (option minus one)
        if(key == 'H'){
            if(auxSortby > 1){
                auxSortby--;
            }
        }
        // If "down arrow" pressed (option plus one)
        if (key == 'P'){
            if(auxSortby < 2){
                auxSortby++;
            }
        }
        if(auxSortby == 1){
          gotoxy(2, 3);
          printf(COLOR_RED" Name"COLOR_NONE);
          gotoxy(2, 4);
          printf(" Age");
          gotoxy(2, 3);
        }else{
          gotoxy(2, 3);
          printf(" Name");
          gotoxy(2, 4);
          printf(COLOR_RED" Age"COLOR_NONE);
          gotoxy(2, 4);
        }
    }
 
    system("cls");
    if(auxSortby == 1){
      qsort(people, *total_on, sizeof(struct access), compareByName);
    }else{
      qsort(people, *total_on, sizeof(struct access), compareByAge);
    }
  }

  for(i = 0; i < *total_on; i++){
    printf("\n| Username: %s (%s) \n",people[i].name,people[i].username);
    printf("| Age: %i", 2018-people[i].birthday.year);
    printf(" (%0.2d/%0.2d/%d) \n",people[i].birthday.day,people[i].birthday.month,people[i].birthday.year);
    printf("| Marital status: %s\n", people[i].marital_status);
    printf("| City: %s - ",people[i].city);
    state_abbreviation(people[i].state,&test_state_exist); // Calling the function to get the abbreviation
    printf("\n| Gender: %s\n\n", people[i].gender);
  }
  
  while(true){
       printf(" Press \"Esc\" to go back to Menu\n");
       KeyGoBackToMenu = getch();
       if(KeyGoBackToMenu == ESC){
         system("cls");
         break;
       }else{
         printf("\n -_- Wrong key pressed, try again -_- \n\n");
       }
  }
}
void Creat_account(struct access people[], int *j){
   int auxGender = 1, auxMaritual_status = 1;
   int i, p, test_state_exist = 0;
   char KeyGoBackToMenu = ' ';
   char auxMarriedWith[30];
   char key = ' ';

    system("cls");
    printf("\n ***** Creating an account *****\n\n");
    printf("\n Enter your name and surname: ");
    scanf(" %[^\n]s",people[*j].name);

    // Getting the username
    while(true){
       printf(" Enter your username: ");
       scanf(" %[^\n]s",people[*j].username);
       p = 0;
       //Checking if the username already exists
       for(i = 0; i < *j; i++){
         if(strcmp(people[*j].username,people[i].username) == 0){
           p++;
           break;
         }
       }
       if(p != 0){
          printf("\n -_- This username already exist, try a different one... -_-\n\n\a");
       }else
          break;
     }
     system("cls");
     printf("\n ***** Creating an account *****\n\n");
     while(true){
        printf(COLOR_RED" #Creat a password: \n\n"COLOR_NONE);
        gets_password(people[*j].password); // Function to get the password.
        printf(COLOR_RED"\n\n #Confirm your password: \n\n"COLOR_NONE);
        gets_password(people[*j].confirm_password); // Function to get the password(confirmation).
        if(strcmp(people[*j].password,people[*j].confirm_password) == 0){
          break;
        }else{
          system("cls");
          printf(COLOR_RED"\n\n -_- The passwords don't match. Please re-enter a password again -_-\n\n\a"COLOR_NONE);
        }
     }
     system("cls");
     printf("\n ***** Creating an account *****\n\n");
     printf("  Gender: \n");

     gotoxy(2, 5);
     printf(COLOR_RED" Female "COLOR_NONE);
     gotoxy(2, 6);
     printf(" Male ");
     gotoxy(2, 5);

     while(key != Enter){
        key = getch();
        key = toupper(key);
        
        if(key != Enter)key = getch();
        key = toupper(key);

        // If "up arrow" pressed (option minus one)
        if(key == 'H'){
            if(auxGender > 1){
                auxGender--;
            }
        }
        // If "down arrow" pressed (option plus one)
        if (key == 'P'){
            if(auxGender < 2){
                auxGender++;
            }
        }
        if(auxGender == 1){
          gotoxy(2, 5);
          printf(COLOR_RED" Female "COLOR_NONE);
          gotoxy(2, 6);
          printf(" Male ");
          gotoxy(2, 5);
        }else{
          gotoxy(2, 5);
          printf(" Female ");
          gotoxy(2, 6);
          printf(COLOR_RED" Male "COLOR_NONE);
          gotoxy(2, 6);
        }
     }

     // Saving the gender in the variable as string
     if(auxGender == 1){
        strcpy(people[*j].gender, "Female");
     }else{
        strcpy(people[*j].gender, "Male");
     }

    system("cls");
    key = ' ';
    printf("\n ***** Creating an account *****\n\n");
    printf(" Marital status: \n");
    
  gotoxy(2, 5);
  printf(COLOR_RED" Single "COLOR_NONE);
  gotoxy(2, 7);
  printf(" Married");
  gotoxy(2, 9);
  printf(" Separated");
  gotoxy(2, 11);
  printf(" Divorced");
  gotoxy(2, 13);
  printf(" Widowed");
  gotoxy(2, 15);
  printf(" Dating");
  gotoxy(2, 5);

  while(key != Enter){
      key = getch();
      key = toupper(key);

      if(key != Enter)key = getch();
      key = toupper(key);

      // If "up arrow" pressed (option minus one)
      if(key == 'H'){
          if(auxMaritual_status > 1){
              auxMaritual_status--;
          }
      }
      // If "down arrow" pressed (option plus one)
      if (key == 'P'){
          if(auxMaritual_status < 6){
              auxMaritual_status++;
          }
      }

      if(auxMaritual_status == 1){
          gotoxy(2, 5);
          printf(COLOR_RED" Single "COLOR_NONE);
          gotoxy(2, 7);
          printf(" Married");
          gotoxy(2, 9);
          printf(" Separated");
          gotoxy(2, 11);
          printf(" Divorced");
          gotoxy(2, 13);
          printf(" Widowed");
          gotoxy(2, 15);
          printf(" Dating");
          gotoxy(2, 5);
      }else if(auxMaritual_status == 2){
          gotoxy(2, 5);
          printf(" Single ");
          gotoxy(2, 7);
          printf(COLOR_RED" Married"COLOR_NONE);
          gotoxy(2, 9);
          printf(" Separated");
          gotoxy(2, 11);
          printf(" Divorced");
          gotoxy(2, 13);
          printf(" Widowed");
          gotoxy(2, 15);
          printf(" Dating");
          gotoxy(2, 7);
      }else if(auxMaritual_status == 3){
          gotoxy(2, 5);
          printf(" Single ");
          gotoxy(2, 7);
          printf(" Married");
          gotoxy(2, 9);
          printf(COLOR_RED" Separated"COLOR_NONE);
          gotoxy(2, 11);
          printf(" Divorced");
          gotoxy(2, 13);
          printf(" Widowed");
          gotoxy(2, 15);
          printf(" Dating");
          gotoxy(2, 9);
      }else if(auxMaritual_status == 4){
          gotoxy(2, 5);
          printf(" Single ");
          gotoxy(2, 7);
          printf(" Married");
          gotoxy(2, 9);
          printf(" Separated");
          gotoxy(2, 11);
          printf(COLOR_RED" Divorced"COLOR_NONE);
          gotoxy(2, 13);
          printf(" Widowed");
          gotoxy(2, 15);
          printf(" Dating");
          gotoxy(2, 11);
      }else if(auxMaritual_status == 5){
          gotoxy(2, 5);
          printf(" Single ");
          gotoxy(2, 7);
          printf(" Married");
          gotoxy(2, 9);
          printf(" Separated");
          gotoxy(2, 11);
          printf(" Divorced");
          gotoxy(2, 13);
          printf(COLOR_RED" Widowed"COLOR_NONE);
          gotoxy(2, 15);
          printf(" Dating");
          gotoxy(2, 13);
      }else{
          gotoxy(2, 5);
          printf(" Single ");
          gotoxy(2, 7);
          printf(" Married");
          gotoxy(2, 9);
          printf(" Separated");
          gotoxy(2, 11);
          printf(" Divorced");
          gotoxy(2, 13);
          printf(" Widowed");
          gotoxy(2, 15);
          printf(COLOR_RED" Dating"COLOR_NONE);
          gotoxy(2, 15);
      }
    }
    
    system("cls");
    // Saving the relationship status in the variable as string
    if(auxMaritual_status == 1){
        strcpy(people[*j].marital_status, "Single");
    }else if(auxMaritual_status == 2){
        printf("\n Married to: ");
        scanf(" %[^\n]s",auxMarriedWith);
        strcpy(people[*j].marital_status, "Married to ");
        strcat(people[*j].marital_status, auxMarriedWith);
    }else if(auxMaritual_status == 3){
        strcpy(people[*j].marital_status, "Separated");
    }else if(auxMaritual_status == 4){
        strcpy(people[*j].marital_status, "Divorced");
    }else if(auxMaritual_status == 5){
        strcpy(people[*j].marital_status, "Widowed");
    }else if(auxMaritual_status == 6){
        strcpy(people[*j].marital_status, "Dating");
    }

    system("cls");
    printf("\n ***** Creating an account *****\n\n");
    printf("\n Living in:");
    printf("\n City: ");
    scanf(" %[^\n]s",people[*j].city);
    while(true){
      test_state_exist = 0;
      printf(" State: ");
      scanf(" %[^\n]s",people[*j].state);
      state_abbreviation(people[*j].state, &test_state_exist);
      if(test_state_exist == 0)
        break;
      else{
        printf(" *Not found*");
        printf("\n -_- Brazil has no state with this name, please try gain.... -_-\n\a");
      }
    }
    system("cls");
    printf("\n ***** Creating an account *****\n\n");
    printf("\n\n Birthday: \n");
    while(true){
      fflush(stdin);
      printf(" Day: ");
      scanf(" %d",&people[*j].birthday.day);
      if(people[*j].birthday.day > 0 && people[*j].birthday.day <= 31)
       break;
      else
       printf("\n -_- The day you entered is incorrect. -_-\n\n\a");
    }
    while(true){
      fflush(stdin);
      printf(" Month: ");
      scanf(" %d",&people[*j].birthday.month);
      if(people[*j].birthday.month > 0 && people[*j].birthday.month <= 12)
        break;
      else
        printf("\n -_- The month you entered is incorrect. -_-\n\n\a");
    }
    while(true){
      fflush(stdin);
      printf(" year: ");
      scanf(" %d",&people[*j].birthday.year);
      if(people[*j].birthday.year > 1900 && people[*j].birthday.year <= 2018)
        break;
      else
        printf("\n -_- There's no way you were born this year. -_-\n\n\a");
    }
    // Gets the user's age
    people[*j].Age = 2018 - (people[*j].birthday.year);

    system("cls");
    printf("\n -------------------------------------------------------------------------------------------- ");
    printf("\n #Your account has been successfully created!\n\n");
    printf(" #Your security code: ---> ");
    for(i = 0; i < 3; i++){
     people[*j].security_code[i] = rand() % 10;
    }
    printf(COLOR_RED);
    for(i = 0; i < 3; i++){
      if(i != 2){
        printf("%d, ",people[*j].security_code[i]);
      }else
        printf("%d",people[*j].security_code[i]);
    }
    printf(COLOR_NONE);
    printf(" <--- \n \"In case you forget your password, you'll need this code in order to change it\"\n");
    printf("\n --------------------------------------------------------------------------------------------\n\n\n");

    // Saving user's info
    save_user(people, j);  // Here "j" is equal to "&j"

    (*j)++; 

    while(true){
       printf(" Press \"Esc\" to go back to Menu\n");
       KeyGoBackToMenu = getch();
       if(KeyGoBackToMenu == ESC){
         system("cls");
         break;
       }else{
         printf("\n -_- Wrong key pressed, try again -_- \n\n");
       }
    }
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
    printf("%s", abbreviation);
  }
}
void gets_password(char password[]){
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
}
void gotoxy(int x, int y){
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x,y});
}
void Loading(void){
  int i;
  printf("\n\n Loading, please wait...\n ");
  for(i = 0; i < 20; i++){
     printf("\xDB");
     Sleep(500);
  }
  system("cls");
}
int Menu(void){
  int option = 1;
  char key = ' ';
  printf("\n  *=*=*=*=*= MENU =*=*=*=*=*=\t\n");

  gotoxy(2, 3);
  printf(COLOR_RED" Create an new account "COLOR_NONE);
  gotoxy(2, 5);
  printf(" Log into your account");
  gotoxy(2, 7);
  printf(" Change information");
  gotoxy(2, 9);
  printf(" Delete account");
  gotoxy(2, 11);
  printf(" Show all users");
  gotoxy(2, 13);
  printf(" Exit");
  gotoxy(2, 3);

  while(key != Enter){
        key = getch();
        key = toupper(key);

        if(key != Enter)key = getch();
        key = toupper(key);

        // If "up arrow" pressed (option minus one)
        if(key == 'H'){
            if(option > 1){
                option--;
            }
        }
        // If "down arrow" pressed (option plus one)
        if (key == 'P'){
            if(option < 6){
                option++;
            }
        }

        if(option == 1){
            gotoxy(2, 3);
            printf(COLOR_RED" Create an new account "COLOR_NONE);
            gotoxy(2, 5);
            printf(" Log into your account");
            gotoxy(2, 7);
            printf(" Change information");
            gotoxy(2, 9);
            printf(" Delete account");
            gotoxy(2, 11);
            printf(" Show all users");
            gotoxy(2, 13);
            printf(" Exit");
            gotoxy(2, 3);
        }else if(option == 2){
            gotoxy(2, 3);
            printf(" Create an new account ");
            gotoxy(2, 5);
            printf(COLOR_RED" Log into your account"COLOR_NONE);
            gotoxy(2, 7);
            printf(" Change information");
            gotoxy(2, 9);
            printf(" Delete account");
            gotoxy(2, 11);
            printf(" Show all users");
            gotoxy(2, 13);
            printf(" Exit");
            gotoxy(2, 5);
        }else if(option == 3){
            gotoxy(2, 3);
            printf(" Create an new account ");
            gotoxy(2, 5);
            printf(" Log into your account");
            gotoxy(2, 7);
            printf(COLOR_RED" Change information"COLOR_NONE);
            gotoxy(2, 9);
            printf(" Delete account");
            gotoxy(2, 11);
            printf(" Show all users");
            gotoxy(2, 13);
            printf(" Exit");
            gotoxy(2, 7);
        }else if(option == 4){
            gotoxy(2, 3);
            printf(" Create an new account ");
            gotoxy(2, 5);
            printf(" Log into your account");
            gotoxy(2, 7);
            printf(" Change information");
            gotoxy(2, 9);
            printf(COLOR_RED" Delete account"COLOR_NONE);
            gotoxy(2, 11);
            printf(" Show all users");
            gotoxy(2, 13);
            printf(" Exit");
            gotoxy(2, 9);
        }else if(option == 5){
            gotoxy(2, 3);
            printf(" Create an new account ");
            gotoxy(2, 5);
            printf(" Log into your account");
            gotoxy(2, 7);
            printf(" Change information");
            gotoxy(2, 9);
            printf(" Delete account");
            gotoxy(2, 11);
            printf(COLOR_RED" Show all users"COLOR_NONE);
            gotoxy(2, 13);
            printf(" Exit");
            gotoxy(2, 11);
        }else{
            gotoxy(2, 3);
            printf(" Create an new account ");
            gotoxy(2, 5);
            printf(" Log into your account");
            gotoxy(2, 7);
            printf(" Change information");
            gotoxy(2, 9);
            printf(" Delete account");
            gotoxy(2, 11);
            printf(" Show all users");
            gotoxy(2, 13);
            printf(COLOR_RED" Exit"COLOR_NONE);
            gotoxy(2, 13);
        }
    }

  return option;
}





