#include <iostream>
#include "../lib/printVector.h"
#include "../lib/copyVector.h"

using namespace std;

void merge(int* source, int indexL0, int indexLFinal, int indexUntil){
    int maxSign = 1000;
    
    int posInicialL = indexL0;
    int posFinalL = indexLFinal;
    int posInicialR = posFinalL + 1;
    int posFinalR = indexUntil;

    int sizeLeft = posFinalL - posInicialL + 2;
    int sizeRight = posFinalR - posInicialR + 2;

    int copyLeft[sizeLeft];
    int copyRight[sizeRight];

    copyVector(copyLeft, source, posInicialL, posFinalL);
    copyLeft[sizeLeft-1] = maxSign;
    
    copyVector(copyRight, source, posInicialR, posFinalR);
    copyRight[sizeRight-1] = maxSign;

    int cursorL = 0;
    int cursorR = 0;
    for(int i = indexL0 ; i <= indexUntil; i++) {
        cout << "analyzing " << copyLeft[cursorL] << " <= " << copyRight[cursorR] << endl;
        if(copyLeft[cursorL] <= copyRight[cursorR]){
            cout << "chosen: " << copyLeft[cursorL] << endl;
            source[i] = copyLeft[cursorL];
            cursorL++;
        }
        else {
            cout << "chosen: " << copyRight[cursorR] << endl;
            source[i] = copyRight[cursorR];
            cursorR++;
        }
    }
    
}

void mergeSort(int* source, int indexFrom, int indexUntil){
    if(indexFrom < indexUntil){
        int lastPosLeft = (indexFrom + indexUntil) / 2;
        int firstPosRight = lastPosLeft + 1;
        mergeSort(source, indexFrom, lastPosLeft);
        mergeSort(source, firstPosRight, indexUntil);
        merge(source, indexFrom, lastPosLeft, indexUntil);
    }
}

int main(void)
{
    int idades[] = {28, 68, 10, 31, 2, 54, 55, 47, 35, 50};
    int size = sizeof(idades) / sizeof(idades[0]);
    int lastIndex = size - 1;
    mergeSort(idades, 0, lastIndex);
    printVector(idades, size);

    return 0;
}