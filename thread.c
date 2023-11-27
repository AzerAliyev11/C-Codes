#include <stdio.h>
#include <pthread.h>

void* PrintHello(void *threadid)
{
    printf("Thread number %d\n", *(int*)threadid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Creating thread %d from main\n", i);
        pthread_create(&threads[i], NULL, PrintHello, (void*)&i);
        pthread_join(threads[i], NULL);
    }
    pthread_exit(NULL);
}