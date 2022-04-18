#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char *stringToChar(string text, char *p_text)
{
    p_text = new char[text.length() + 1];
    std::strcpy(p_text, text.c_str());
    return p_text;
}

int main()
{
    string name;
    cin >> name;
    cout << name << endl << endl;

    char *p_name;
    p_name = stringToChar(name, p_name);
    cout << p_name << endl;
    cout << p_name[0] << endl;
    cout << sizeof(p_name) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(char *) << endl;
    cout << sizeof(p_name[0]) << endl;
    cout << &p_name << endl;
    cout << *(p_name + 0*sizeof(p_name[0])) << endl;

    return 0;
}
