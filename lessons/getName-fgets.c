#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 10

int main(int argc, char const *argv[]) {	
	char name[MAX_INPUT_SIZE];

	printf("What's your name? ");

	fgets(name, MAX_INPUT_SIZE, stdin);

	printf("Hello, %s\n", name);


	return 0;
}
