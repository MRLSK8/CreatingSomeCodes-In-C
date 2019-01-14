#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// SetCursorPos(x,y) setar local do mouse;
// GetCursorPos(&variavel) coletar local do mouse;
int main(void)
{
	POINT coods;

	for( ; ; ){
		GetCursorPos(&coods);
		system("cls");
		printf("%i, %i",coods.x,coods.y);
	}

	return 1;
};