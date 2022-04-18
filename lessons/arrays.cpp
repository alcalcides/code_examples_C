#include <iostream>

using namespace std;

int main()
{
    int num[] = {1, 2, 30, 40, 50};
    cout << "num = " << num << endl; // an address
    cout << "num[0] = " << num[0] << endl;
    cout << "sizeof(num[0]) = " << sizeof(num[0]) << endl;
    cout << "sizeof(num) = " << sizeof(num) << endl;
    cout << "num of eltos = " << sizeof(num) / sizeof(num[0]) << endl;
    cout << "first data out = " << num[sizeof(num) / sizeof(num[0])] << endl
         << endl; //trash

    char nome[] = {'h', 'e', 'l', 'l', 'o', '!'};
    cout << "char nome[] = " << nome << endl;
    cout << "nome[0] = " << nome[0] << endl;
    cout << "size of one elto = " << sizeof(nome[0]) << endl;
    cout << "sizeof(nome) = " << sizeof(nome) << endl;                      // '\0' was added
    cout << "nome[its lenght] = " << nome[sizeof(nome)] << endl;            // '\0' was printed like NUL
    cout << "nome[its lenght] (int) = " << (int)nome[sizeof(nome)] << endl; // NUL is 0 in table ascii
    cout << "first data out = " << nome[sizeof(nome) + 1] << endl;          //trash!
    cout << "first data out = " << (int)nome[sizeof(nome) + 1] << endl
         << endl; //trash!

    string nickname = "hi";
    cout << "string nickname = " << nickname << endl;
    cout << "nickname[0] = " << nickname[0] << endl;
    cout << "nickname.length() = " << nickname.length() << endl;
    cout << "nickname[its length] = " << nickname[nickname.length()] << endl;            // '\0'
    cout << "nickname[its length] (int) = " << (int)nickname[nickname.length()] << endl; // '\0'
    cout << "nickname[its length + 1] = " << nickname[nickname.length() + 1] << endl;    // trash!
    cout << "nickname[its length + 1] (int) = " << (int)nickname[nickname.length() + 1] << endl
         << endl; // trash!

    return 0;
}