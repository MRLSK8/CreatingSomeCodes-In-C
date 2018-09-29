#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
  system("cls");
  char sentence[100];

  printf(" Enter a sentense to be coded: ");
  scanf(" %[^\n]s",sentence);

  strlwr(sentence);

  for(int i = 0 ; i < strlen(sentence); i++){
    if(sentence[i] == '\0')
    	 break;
    if(sentence[i] >= 'x'){
      sentence[i] -= 26;
    }
    if(sentence[i] != ' '){
      sentence[i] += 3;
    }
  }
  printf("\n Sentence coded: %s\n\n",strupr(sentence));

  return 0;
}
