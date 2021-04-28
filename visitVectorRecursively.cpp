#include <iostream>
using namespace std;

void printvetor(int* vetor, int size) {

    if(size == 0) 
        return;
    else if(size == 1){
        cout << vetor[0] << endl;
    }
    else {
        cout << vetor[0] << " - ";
        int *parteA = &vetor[1];
        printvetor(parteA, size - 1);
    }
}


int main()
{
    int foo[5] = {16, 2, 77, 40, 12071};    
    printvetor(foo, 5);
    return 0;
}