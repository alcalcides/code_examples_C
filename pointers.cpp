#include <iostream>

using namespace std;

void printCoord(int x, int y) {
    cout << "(" << x << ", " << y << ")" << endl;
}

void invertCoord(int* x, int *y){
    *x = -*x;
    *y = -*y;
}

int main () {
    int x = 10;
    int* px = &x;
    
    int y = 5;  
    int* py = &y;

    printCoord(x, y);
    
    invertCoord(px, py);
    printCoord(x, y);

    char name[] = "hello";
    char* p_name = name;
    cout << p_name << endl;


    return 0;
}