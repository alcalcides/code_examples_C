#include <stdio.h>

int main (void) {
	// input
	const int SIZE = 5;
	int num[5] = {1, -60, 8, 5, 10};
	int key, i;

	// insertion sort
	for(int j = 1; j < SIZE; j++) {
		key = num[j];
		i = j - 1;
		while(i >= 0 && num[i] > key) {
			num[i + 1] = num[i];
			i--;
		}
		num[i + 1] = key;
	}
	
	// output
	printf("{");
	for (int j = 0; j < SIZE; j++) {		
		printf("%d; ", num[j]);

	}
	printf("\b\b}\n");


	return 0;
}
