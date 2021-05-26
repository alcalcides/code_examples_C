#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void initializeRandomSeed()
{
    srand(time(NULL));
}

/**
 * Returns a integer X
 * @param from is the smaller possible value returned
 * @param until is the highter possible value returned
 * 
 */
int randomize(int from, int until)
{
    return rand() % (until - from + 1) + from;
}