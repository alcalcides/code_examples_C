#include <stdio.h>
#include "../lib/printVector.h"
#include "../lib/swap.h"

void bubbleSort(int *v, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (v[j] <= v[i])
            {
                swap(&v[j], &v[i]);
                printVector(v, size);
            }
        }
    }
}

int main()
{
    int idades[] = {28, 68, 10, 31, 2, 54, 55, 47, 35, 50};
    int size = sizeof(idades) / sizeof(idades[0]);
    printVector(idades, size);
    bubbleSort(idades, size);
    printVector(idades, size);
    return 0;
}