#include <unistd.h>     // fork, execve
#include <stdio.h>      // perror
#include <stdlib.h>     // exit, EXIT_FAILURE
#include <sys/types.h>  // wait
#include <sys/wait.h>   // wait

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
    else if (pid > 0)
    {
        print("I am the patient father");
        wait(0);    // waits for son processing ending
        print("My son has already finished");
    }
    else
    {
        print("I am the fast son");
        execve("/bin/date", argv, envp); // completely changes son's context
    }

    print("Bye");
    exit(EXIT_SUCCESS);
}
