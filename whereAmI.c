#include <stdlib.h>
#include <stdio.h>

int main(void){
	char menuOption;
	do{
		printf("Hello World!\n");
		system("pwd");

		printf("\npress 0 to end: ");
		menuOption = getchar();
		printf("%c\n", menuOption);

	} while( menuOption != '0');

	return 0;
}
