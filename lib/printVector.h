#include <stdio.h>

void printVector(int *vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", vector[i]);
        if (i < size - 1)
            printf(" - ");
    }
    printf("\n");
}