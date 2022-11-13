#include <stdio.h> // exit
#include <stdlib.h> // EXIT_FAILURE
#include <unistd.h> // pipe, write, close

#define PIPE_SIZE 13

int main(void)
{
    char *message = "hello, world";

    char buffer[PIPE_SIZE];
    int fileDescriptor[2];
    int i;

    if(pipe(fileDescriptor) < 0 ) {
        exit(EXIT_FAILURE);
    }


    write(fileDescriptor[1], message, PIPE_SIZE);
    
    read(fileDescriptor[0], buffer, PIPE_SIZE);
    
    close(fileDescriptor[1]);
    close(fileDescriptor[0]);

    printf("%s\n", buffer);

    return 0;
}
