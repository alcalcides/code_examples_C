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
    printf("[%02d]\t Hello World\n", id);
    sleep(1);
    printf("[%02d]\t Bye bye\n", id);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t thread[NUM_OF_THREADS];
    pthread_attr_t attributes;
    int status, i;

    pthread_attr_init(&attributes);
    pthread_attr_setdetachstate(&attributes, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < NUM_OF_THREADS; i++)
    {
        printf("[Main]\t Creating thread %02d\n", i);
        status = pthread_create(&thread[i], &attributes, helloThread, (void *)(long)i);
        if (status)
        {
            perror("Thread not created");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_OF_THREADS; i++)
    {
        printf ("[Main]\t Waiting for thread %02d\n", i);
        status = pthread_join(thread[i], NULL);
        if (status)
        {
            perror("Thread not joined");
            exit(EXIT_FAILURE);
        }
    }

    printf("[Main]\t Bye bye\n");
    pthread_attr_destroy(&attributes);
    pthread_exit(NULL);
}
