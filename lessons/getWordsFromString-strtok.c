#include <string.h>
#include <stdio.h>

#define MAX 100

int main(int argc, char const *argv[])
{
    char str[MAX];
    char* words[MAX];

    fgets(str, MAX, stdin);

    words[0] = strtok(str, " \t\n");
    for (int i = 1; i < MAX; i++)
    {
        words[i] = strtok(NULL, " \t\n");
        if (words[i] == NULL)
            break;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (words[i] == NULL)
            break;
        printf("%s\n", words[i]);
    }

    return 0;
}
