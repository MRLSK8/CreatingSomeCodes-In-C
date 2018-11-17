#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

struct dates{
 int day;
 int month;
 int year;
};
struct access{
  char name[40], username[20];
  char password[30], confirm_password[30];
  char city[20], state[20], states_abbr[5]; // abbr = abbreviation
  char gender[10],marital_status[15];
  int security_code[3], cod;
  struct dates birthday;
};
// Function prototypes
void Creat_account(struct access people[], int *j);
void Change_info(struct access people[], int *j);
void Logging_in(struct access people[], int *j);
void save_user(struct access people[], int *j);
void readInfo(struct access people[], int *j);
void state_abbreviation(char x[],int *z);
void gets_password(char password[]);
void Loading(void);
int Menu(int option);

// Enumeration
enum{Creat = 1, Enter, Change, Clean, Exit};

int main(void){
 system("cls");
 srand(time(NULL));

 // Struct declaration
 struct access *people = (struct access *)calloc(1, sizeof(struct access));

 // All variables used in main function
 char log_username[30],log_password[30];
 int i, j = 0, test_state_exist = 0, option;

  readInfo(people, &j);
  printf("\n *j = %d\n", j);
  do{
    option = Menu(option);
    switch(option){
       // Case to creat an account
       case Creat:
          people = (struct access *)realloc(people, (j+2) * sizeof(struct access)); // Memory allocation
          Creat_account(people, &j);       // j is the amount of people who have created an account
          break;
       // Case to log in your account
       case Enter:
          Logging_in(people, &j);
          break;
       // Case which changes information
       case Change:
          Change_info(people, &j);
          break;
       case Clean:
          system("cls");
          break;
       case Exit:
          printf("\n Finishing...\n");
          break;
       default:
          printf("\n -_- Invalid option. Please try again... -_-\n\a");
          break;
    }
  }while(option != 5);
  getch();
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
    printf("%s", abbreviation);
  }
}
void save_user(struct access people[], int *j){
  FILE *arq;
  arq = fopen("UsersData.txt", "ab");

  if(arq == NULL){
    printf("\n -_- Error opening file! -_-\n");
    system("pause");
    exit(true);
  }
  fwrite(&people[*j], sizeof(struct access), 1, arq);

  fclose(arq);
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
void Loading(void){
  int i;
  printf("\n\n Loading, please wait...\n ");
  for(i = 0; i < 20; i++){
     printf("\xDB");
     Sleep(600);
  }
  system("cls");
}
void Creat_account(struct access people[], int *j){
   int i, p, test_state_exist = 0;
   int auxGender, auxMaritual_status;
   char auxMarriedWith[20];

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
          printf("\n -_- *This username already exist, try a different one... -_-\n\n\a");
       }else
          break;
     }
     system("cls");
     printf("\n ***** Creating an account *****\n\n");
     while(true){
        printf(" Creat a password: \n\n");
        gets_password(people[*j].password); // Function to get the password.
        printf("\n\n #Confirm your password: \n\n");
        gets_password(people[*j].confirm_password); // Function to get the password(confirmation).
        if(strcmp(people[*j].password,people[*j].confirm_password) == 0){
          break;
        }else{
          printf("\n\n -_- The passwords don't match. Please re-enter a password again -_-\n\n\a");
        }
     }
     system("cls");
     printf("\n ***** Creating an account *****\n\n");
     while(true){
        printf("\n Gender:\n 1- Female\n 2- Male\n --> ");
        scanf("%d",&auxGender);
        if(auxGender == 1 || auxGender == 2){
           break;
        }else
           printf("\n -_- Invalid option. Please try again... -_-\n\a");
     }
     // Saving the gender in the variable as string
     if(auxGender == 1){
        strcpy(people[*j].gender, "Female");
     }else{
        strcpy(people[*j].gender, "Male");
     }

    system("cls");
    printf("\n ***** Creating an account *****\n\n");
    while(true){
      printf("\n Marital status: \n");
      printf(" 1- Single\n 2- Married\n 3- Separated\n 4- Divorced\n 5- Widowed\n 6- Dating\n --> ");
      scanf("%d",&auxMaritual_status);
      if(auxMaritual_status == 1 || auxMaritual_status == 2 || auxMaritual_status == 3 ||
      auxMaritual_status == 4 || auxMaritual_status == 5 || auxMaritual_status == 6)
        break;
      else
        printf("\n -_- Invalid option. Please try again... -_-\n\n\a");
    }
    // Saving the relationship status in the variable as string
    if(auxMaritual_status == 1){
        strcpy(people[*j].marital_status, "Single");
    }else if(auxMaritual_status == 2){
        printf(" Married to: ");
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
       printf("\n -_- *The day you entered is incorrect. -_-\n\n\a");
    }
    while(true){
      fflush(stdin);
      printf(" Month: ");
      scanf(" %d",&people[*j].birthday.month);
      if(people[*j].birthday.month > 0 && people[*j].birthday.month <= 12)
        break;
      else
        printf("\n -_- *The month you entered is incorrect. -_-\n\n\a");
    }
    while(true){
      fflush(stdin);
      printf(" year: ");
      scanf(" %d",&people[*j].birthday.year);
      if(people[*j].birthday.year > 1900 && people[*j].birthday.year <= 2018)
        break;
      else
        printf("\n -_- *There's no way you were born this year. -_-\n\n\a");
    }
    system("cls");
    printf("\n ---------------------------------------------------------------------------------------------------------------- ");
    printf("\n #Your account has been successfully created!\n\n");
    printf(" #This is your code: ---> %i <---\n",*j + 1);
    printf(" \"With this code, you'll be able not only to enter your account, but also to change any of its information later\"\n\n");
    printf(" #Your security code: ---> ");
    for(i = 0; i < 3; i++){
     people[*j].security_code[i] = rand() % 10;
    }
    for(i = 0; i < 3; i++){
      if(i != 2){
        printf("%d, ",people[*j].security_code[i]);
      }else
        printf("%d",people[*j].security_code[i]);
    }
    printf(" <--- \n \"In case you forget your password, you'll need this code in order to change it\"\n");
    printf(" ---------------------------------------------------------------------------------------------------------------- \n\n\n");

    people[*j].cod = *j; // Saving user's cod

    // Saving user's data
    save_user(people, j);  // Here "j" is equal to "&j"

    *j = *j + 1;
}
void Logging_in(struct access people[], int *j){
   system("cls");
   char log_username[30], log_password[30];
   int code, k, w,i, test_state_exist = 0, check_security_code[3];

    printf("\n\t _____________logging in_____________ \n");
    printf("\n >> Enter '0' to go back to Menu <<\n");
    while(true){
      printf("\n Enter your code: ");
      scanf("%i",&code);
      if(code >= 0 && code <= *j)
        break;
      else
        printf("\n -_- *This code doesn't exist!!! -_-\n\a");
    }
    // Get out of the function
    if(code == 0){
      system("cls");
      return;
    }
    printf("\n >> Enter \"return\" to go back to Menu <<\n\n");
    while(true){
      fflush(stdin);
      printf(" Enter your username: ");
      scanf(" %[^\n]s",log_username);
      k = 0;
      for(i = 0; i <= *j; i++){
        if(strcmp(log_username,people[i].username) == 0 || stricmp(log_username,"return") == 0 ){
          k++;
          break;
        }
      }
      if(k == 0){
       printf("\n -_- *This username doesn't exist!!! -_-\n\n\a");
      }else
       break;
    }
    if(stricmp(log_username,"return") == 0){
      system("cls");
      return;
    }
    while(true){
      printf(" Enter your password:\n (Enter \"forgot\" if you've forgotten your password!)\n\n");
      gets_password(log_password);
      // Showing user information (logged in)
      if(strcmp(people[code - 1].username,log_username) == 0 && strcmp(people[code-1].password,log_password) == 0){
        Loading();
        system("cls");
        printf("\n -------------------------------------\n");
        printf("\n| User name: %s (%s) \n",people[code-1].name,people[code-1].username);
        printf("| Age: %i", 2018-people[code-1].birthday.year);
        printf(" (%0.2d/%0.2d/%d) \n",people[code-1].birthday.day,people[code-1].birthday.month,people[code-1].birthday.year);
        printf("| Marital status: %s\n", people[code-1].marital_status);
        printf("| City: %s - ",people[code-1].city);
        state_abbreviation(people[code-1].state,&test_state_exist); // Calling the function to get the abbreviation
        printf("\n| Gender: %s\n", people[code-1].gender);
        printf("\n -------------------------------------\n\n\n");

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
             scanf("%i",&check_security_code[i]);
           }
           for(i = 0; i < 3; i++){
             if(people[code-1].security_code[i] != check_security_code[i]){
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
           printf("\n Enter your new password: \n\n");
           gets_password(people[code - 1].password);
           printf("\n Confirm your new password: \n\n");
           gets_password(people[code - 1].confirm_password);
           if(strcmp(people[code - 1].password,people[code - 1].confirm_password) == 0){
             printf("\n\n #### Your password has been successfully changed ####\n\n\n\n");
             break;
           }else
             printf("\n -_- Passwords don't match. Please re-enter a new password again -_-\a");
          }

      }else{
        printf("\n\n\n -_- The password you entered is incorrect!\n -_- Forgot your password? Enter \"forgot\" and change it right way!\n\n\n\a");
      }
    }
}
int Menu(int option){
  int i;

  for(i = 0; i < 15; i++){
    printf("%c ",220);
  }
  printf("\n%c\t    MENU \t    %c\n%c\t\t\t    %c", 220, 220, 220,220);
  printf("\n%c 1- Create an new account  %c\n%c 2- Login to your account  %c\n", 220,220,220,220);
  printf("%c 3- Change information\t    %c\n%c 4- Clean the screen\t    %c\n%c 5- Exit\t\t    %c ",220,220,220,220,220,220,220);

  printf("\n");
  for(i = 0; i < 15; i++){
    printf("%c ",220);
  }
  printf("\nOption: ");
  scanf("%i",&option);
  return option;
}
void Change_info(struct access people[], int *j){
  int code_changes, Option_changes, test_state_exist = 0;
  int auxMarital_status, auxGender;
  char auxMarriedWith[20];
  char current_password[20];

  printf("\n >> Enter '0' to go back to Menu <<\n");
  while(true){
      printf("\n Enter your code, so that you can change your information: ");
      scanf("%d",&code_changes);
      if(code_changes >= 0 && code_changes <= *j)
       break;
      else
        printf("\n -_-  This code doesn't exist!!! -_-\n\a");
  }
  // Get out of the function
  if(code_changes == 0){
    system("cls");
    return;
  }
  do{
    printf("\n ============= Changing information =================\n");
    printf("\n What do you want to change? \n");
    printf(" 1- Name\n 2- Password\n 3- City/State\n 4- Marital status\n 5- Birthday\n 6- Username\n 7- Exit\n --> ");
    scanf("%d",&Option_changes);
    system("cls");
    switch(Option_changes){
       case 1:
           printf("\n Enter your new name and surname: ");
           scanf(" %[^\n]s",people[code_changes - 1].name);
           printf(" ### Your name has been successfully changed ###\n");
           break;
       case 2:
           while(true){
           printf("\n Enter your current password: \n\n");
           gets_password(current_password);
           if(strcmp(current_password,people[code_changes - 1].password) == 0)
              break;
           else
              printf("\n\n -_- *This is not your password, please enter your correct password! -_-\n\n\a");
           }
           printf("\n\n Enter your new password: \n\n");
           gets_password(people[code_changes - 1].password);
           printf("\n\n\n ##### Your password has been successfully changed #####\n\n");
           break;
       case 3:
           printf("\n Enter your new:\n");
           printf(" City: ");
           scanf(" %[^\n]s",people[code_changes -1].city);
           while(true){
               test_state_exist = 0;
               printf(" State: ");
               scanf(" %[^\n]s",people[code_changes - 1].state);
               state_abbreviation(people[code_changes - 1].state, &test_state_exist);
               if(test_state_exist == 0)
                   break;
               else
                   printf(" *Not found*");
                   printf("\n -_- Brazil has no state with this name, please try gain.... -_-\n\a");
           }
           system("cls");
           printf("\n ### Your city/state has been successfully changed ###\n\n");
           break;
        case 4:
           while(true){
              printf("\n Enter your new marital status: \n");
              printf(" 1- Single\n 2- Married\n 3- Separated\n 4- Divorced\n 5- Widowed\n 6- Dating\n --> ");
              scanf("%i", &auxMarital_status);
              if(auxMarital_status == 1 || auxMarital_status == 2 ||
                 auxMarital_status == 3 || auxMarital_status == 4 ||
                 auxMarital_status == 5 || auxMarital_status == 6)
                 break;
              else
                 printf("\n\n -_- Invalid option. Please try again... -_-\n\n\a");
           }
            if(auxMarital_status == 1){
                strcpy(people[code_changes - 1].marital_status, "Single");
            }else if(auxMarital_status == 2){
                printf(" Married to: ");
                scanf(" %[^\n]s",auxMarriedWith);
                strcpy(people[code_changes - 1].marital_status, "Married to ");
                strcat(people[code_changes - 1].marital_status, auxMarriedWith);
            }else if(auxMarital_status == 3){
                strcpy(people[code_changes - 1].marital_status, "Separated");
            }else if(auxMarital_status == 4){
                strcpy(people[code_changes - 1].marital_status, "Divorced");
            }else if(auxMarital_status == 5){
                strcpy(people[code_changes - 1].marital_status, "Widowed");
            }else if(auxMarital_status == 6){
                strcpy(people[code_changes - 1].marital_status, "Dating");
            }

           printf("\n\n ### Your marital status has been successfully changed ###\n\n");
           break;
        case 5:
           printf("\n Enter your new birthday: \n");
           while(true){
              fflush(stdin);
              printf(" Day: ");
              scanf(" %d",&people[code_changes - 1].birthday.day);
              if(people[code_changes - 1].birthday.day > 0 && people[code_changes - 1].birthday.day <= 31)
                 break;
              else
                 printf("\n -_- The day you entered is incorrect -_-\n\n\a");
           }
           while(true){
              fflush(stdin);
              printf(" Month: ");
              scanf(" %d",&people[code_changes - 1].birthday.month);
              if(people[code_changes - 1].birthday.month > 0 && people[code_changes - 1].birthday.month <= 12)
                 break;
              else
                 printf("\n -_- The month you entered is incorrect -_-\n\n\a");
           }
           while(true){
              fflush(stdin);
              printf(" year: ");
              scanf(" %d",&people[code_changes - 1].birthday.year);
              if(people[code_changes - 1].birthday.year > 1900 && people[code_changes - 1].birthday.year <= 2018)
                 break;
              else
                 printf("\n -_- There's no way you were born this year -_-\n\n\a");
           }
           printf("\n\n ### Your birthday has been successfully changed ###\n\n");
           break;
        case 6:
           printf("\n Enter your new username: ");
           scanf(" %[^\n]s",people[code_changes - 1].username);
           printf("\n\n ### Your username has been successfully changed ###\n\n");
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
void readInfo(struct access people[], int *j){
   int x;
   FILE *arq;
   arq = fopen("UsersData.txt", "rb");

   if(arq == NULL){
    printf("\n -_- Error opening file! -_-\n");
    system("pause");
    exit(true);
  }
  rewind(arq);

  fread(people, sizeof(struct access),2, arq);

  *j = 2;
  fclose(arq);
}












