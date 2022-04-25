#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print(char * msg) {
    printf("[%d] %s\n", getpid(), msg);
}

int main(int argc, char const *argv[])
{
    char op;    
    __pid_t pid;

    pid = fork();

    if(pid < 0) {
        perror("Fork failure");
        exit(EXIT_FAILURE);
    }
    else if(pid > 0){
        print("I am the father");
    }
    else {
        print("I am the son");
    }

    print("Bye");
    exit(EXIT_SUCCESS);
}
