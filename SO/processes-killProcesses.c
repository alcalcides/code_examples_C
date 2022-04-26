#include <unistd.h>     // fork
#include <stdio.h>      // perror
#include <stdlib.h>     // exit, EXIT_FAILURE
#include <sys/types.h>  // kill
#include <sys/wait.h>   // wait
#include <signal.h>     // kill

void print(char *msg)
{
    printf("[%d] %s\n", getpid(), msg);
}

int main(int argc, char *argv[], char *envp[])
{
    char op;
    __pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("Fork failure");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        print("Maybe there is time to cry");
    }
    else
    {
        print("I am a crazy father... I'am killing the son process");
        kill(pid, SIGTERM);
        print("I've just killed the son process");
    }

    print("Bye");
    exit(EXIT_SUCCESS);
}
