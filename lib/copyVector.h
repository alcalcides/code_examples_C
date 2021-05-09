#include <stdio.h>

void copyVector(int *to, int *from, int sinceIndex, int untilIndex)
{
    int j = 0;
    for (int i = sinceIndex; i <= untilIndex; i++)
    {
        to[j] = from[i];
        j++;
    }
}
