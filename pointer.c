#include <stdio.h>
#include <conio.h>
int main(void){
	int i = 3, *j, **k, ***l;
	j = &i;
	k = &j;
	l = &k;

	printf("\n &i = %p\n", &i);
  printf("\n &j = %p\n", &j);
	printf("\n &k = %p\n", &k);
	printf("\n &l = %p\n", &l);

	printf("\n i = %d\n", i);  // i = 3 
  printf("\n j = %p\n", j);  // j = &i
	printf("\n k = %p\n", k);  // k = &j
	printf("\n l = %p\n", l);  // l = &k

  printf("\n *j = %d\n", *j);     // *j = 3
	printf("\n *k = %p\n", *k);     // *k = &i
	printf("\n **k = %d\n", **k);   // **k = 3
	printf("\n *l = %p\n", *l);     // *l = &j
	printf("\n **l = %p\n", **l);   // **l = &i
	printf("\n ***l = %d\n", ***l); // ***l = 3

	printf("\n %d\n", i * *j * i - *j * **k + ***l);

	getch();
	return 0;
}