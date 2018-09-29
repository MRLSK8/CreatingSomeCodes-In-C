#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

typedef struct{
  int hour;
  int minutes;
  int seconds;
}clocks;

// Funtions prototypes 
void update(clocks *x);
void show(clocks *y);

int main(void){
  clocks hora = {0, 0, 0};
 
  while(true){
      update(&hora);
      Sleep(1000);
      show(&hora);
      system("cls");
  }
  return 0;
}
void update(clocks *x){
   x->seconds++;
  
   if(x->seconds == 60){
      x->seconds = 0;
      x->minutes++;
    }
   if(x->minutes == 60){
      x->minutes = 0;
      x->hour++;
   }
   if(x->hour == 24){
      x->hour = 0;
   }

}
void show(clocks *y){
  printf(" \nHora: %02d:", y->hour);
  printf("%02d:", y->minutes);
  printf("%02d", y->seconds);
}