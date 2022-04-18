#include <stdio.h>

int main(void){
	int op;

	fprintf(stderr, "first error message\n");
	fprintf(stdout, "if you used '2>' to redirect stderr stream, see there is already content there even and ths process didn't fineshed yet\n");
	fprintf(stdout, "type a number: ");
	scanf("%d", &op);
	fprintf(stdout, "you typed: %d\n", op);
	fprintf(stderr, "second error message\n");

	return 0;
}
