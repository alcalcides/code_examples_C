#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    __pid_t pid;
    char * ops[] = {"../lessons/helloWorld\0", (char *) NULL};

    pid = fork();

    if (pid < 0 ){
        perror("Impossible forking");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0 ) {
        int status = execvp("../lessons/helloWorld", ops);
        if(status == -1){
            printf("%d\t%s\n", errno, strerror(errno));
        }
    }
    else {
        printf("waiting my son\n");
        wait(0);
    }
    printf("bye bye\n");
    exit(EXIT_SUCCESS);
}
