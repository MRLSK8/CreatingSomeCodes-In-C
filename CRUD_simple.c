#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  char name[30];
  int age;
  float hight;
  bool registered;
}Tperson;
int main(void){
  system("cls");
  int initial_people = 1;  // Initial amount of people
  Tperson *people = NULL;
  people = (Tperson *)calloc(initial_people, sizeof(Tperson)); 
  // Functions
  void deleting(char *name, Tperson people[], int *initial_people);
  int registering(Tperson people[], int *initial_people);
  void saving(Tperson people[], int *initial_people);
  int Menu();
  // Variables
  int option, i, a, more_person;
  char name_delete[30];

  do{
    option = Menu();

    switch(option){
      case 1:
        while(true){
          people = (Tperson *)realloc(people, initial_people * sizeof(Tperson));
          if(people == NULL){
            printf("\n Error, your computer ran out of space...\n\a");
          }
          more_person = registering(people, &initial_people);
          if(more_person == 2){
            break;
          }
        }
      break;
      case 2:
        system("cls");
        printf("\n Enter the person's name: ");
        scanf(" %[^\n]s", name_delete);
        deleting(name_delete, people, &initial_people);
      break;
      case 3:
        system("cls");
        if(initial_people == 1){
          printf("\n There's no people registered yet!\a\n");
          break;
        }
        for(i = 0; i < initial_people - 1; i++){
          printf("\n\xC9");
          for(a = 0; a < 23; a++){
            printf("\xCD");
          }
          printf("\xBB");
          printf("\n\xBA  Person %i:\t\t\xBA \n", i+1);
          printf("\xBA  Name: %s  \t\xBA \n", people[i].name);
          printf("\xBA  Age: %d \t\t\xBA \n", people[i].age);
          printf("\xBA  Hight: %.2f \t\t\xBA \n", people[i].hight);
          if(people[i].registered == 1){
            printf("\xBA  Registered = True.\t\xBA");
          }else
            printf("\xBA  Registered = False.\t\xBA");

          printf("\n\xC8");
          for(a = 0; a < 23; a++){
            printf("\xCD");
          }
          printf("\xBC\n\n");
        }
      break;
      case 4:
        system("cls");
      break;
      case 5:
        system("cls");
        saving(people, &initial_people);
        printf("\n Person succesfuly saved!!!\n");
      break;
      case 6:
        printf("\n Finishing....\n\n");
      break;
      default:
        printf("\n Error, wrong option\n\a");
      break;
    }
  }while(option != 6);
  
  free(people);
  return 0;
}
int Menu(){
  int i, op;

  printf("\n\t Registration Menu \n\t");
  for(i = 0; i < 19; i++){
    printf("\xCD");
  }
  printf("\n 1- To register\n 2- To delete\n 3- To show all registed\n 4- to clean the scream\n"
  " 5- To save\n 6- To exit\n --> ");
  scanf("%i", &op);

  return op;
}
int registering(Tperson people[], int *initial_people){
  system("cls");
  int option, i, position_free = - 1;
  
  for(i = 0; i < *initial_people - 1; i++){
    if(people[i].registered == false){
      position_free = i + 1;
      break;
    }
  }
  if(position_free == -1){
    position_free = *initial_people;
  }

  printf("\n\t ......Registering......\n");
  printf("\n Person %i:\n ", position_free);
  printf(" Enter your name and last name: ");
  scanf(" %[^\n]s", people[position_free - 1].name);
  printf("  Enter your age: ");
  scanf("%i", &people[position_free - 1].age);
  printf("  Enter your hight: ");
  scanf("%f", &people[position_free - 1].hight);
  people[position_free - 1].registered = true;
  if(position_free == *initial_people){
    *initial_people = *initial_people + 1;
  }

  system("cls");
  printf("\n\n Do you want to register another person? (1 - Yes | 2- No)\n --> ");
  scanf("%i", &option);
  
  system("cls");

  return option;
}
void deleting(char *name, Tperson people[], int *initial_people){
  int i, aux = 0;

  for(i = 0; i < *initial_people - 1; i++){
    if(stricmp(people[i].name, name) == 0){
      people[i].registered = false;
      printf("\n Person succesfuly deleted! \n\n");
      aux++;
    }
  }
  if(aux == 0){
    printf("\n Error, person not found!\a\n");
    printf(" Make sure you're typing the name correctly!\n\n");
  }
}
void saving(Tperson people[], int *initial_people){
  FILE *archive = fopen("all_data.txt", "w");
  int i, a = 1;
  
  for(i = 0; i < *initial_people - 1; i++){
    if(people[i].registered == true){
      fprintf(archive, "------------------------------\n");
      fprintf(archive,"\n Person %i:", a);
      fprintf(archive,"\n   Name: %s", people[i].name);
      fprintf(archive,"\n   Age: %d", people[i].age);
      fprintf(archive,"\n   Hight: %.2f\n", people[i].hight);
      a++;
    }
  }
  fclose(archive);
}