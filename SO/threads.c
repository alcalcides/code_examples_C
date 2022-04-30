// compile with -lpthread, i.e.
// gcc -Wall threads.c -lpthread

#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_OF_THREADS 4

void *helloThread(void *threadID)
{
    int id = (int)(long)threadID;
    printf("[%02d]: Hello World\n", id);
    sleep(1);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t thread[NUM_OF_THREADS];
    int status, i;

    for (i = 0; i < NUM_OF_THREADS; i++)
    {
        printf("Main: criando thread %02d\n", i);
        status = pthread_create(&thread[i], NULL, helloThread, (void *)(long)i);
        if (status)
        {
            perror("Thread not created");
            exit(EXIT_FAILURE);
        }
    }

    pthread_exit(NULL);
}
