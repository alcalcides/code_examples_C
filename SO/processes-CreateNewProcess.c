#include <unistd.h>     // fork, pid
#include <stdio.h>      // printf, perror
#include <stdlib.h>     // exit, EXIT_FAILURE

int main(int argc, char const *argv[])
{
    __pid_t pid;
    char waiting;

    printf("me once\n");    // only father
    
    pid = fork();   // replication point    
    if(pid < 0) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    
    printf("[%d], me twice\n", getpid());   // father and son lives, 
    
    scanf("%c", &waiting); // check with: "pstree", "ps -xf" or "ps -eH"

    return 0;
}
