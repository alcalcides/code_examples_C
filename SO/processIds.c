#include <stdio.h>
#include <unistd.h>


int main(void)
{
    
    printf("I am the process with id %ld\n", (long) getpid());
    printf("My parent is %ld\n", (long) getppid());
    printf("My real user ID is %ld\n", (long) getuid());
    printf("My effective user ID is %ld\n", (long) geteuid());
    printf("My group ID is %ld\n", (long) getgid());
    printf("My effective group ID is %ld\n", (long) getegid());
    sleep(20);

    return 0;
}
