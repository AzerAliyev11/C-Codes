#include <stdio.h>
#include <pthread.h>

pthread_cond_t cond_recv = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_send = PTHREAD_COND_INITIALIZER;
pthread_mutex_t cond_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;

int count = 0;
int full = 0;

void* produce(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&cond_mutex);

        while(full)
        {
            pthread_cond_wait(&cond_recv, &cond_mutex);
        }

        pthread_mutex_unlock(&cond_mutex);
        pthread_mutex_lock(&count_mutex);
        count++;
        full = 1;
        printf("produced %d\n", count);
        pthread_cond_broadcast(&cond_send);
        pthread_mutex_unlock(&count_mutex);
        if(count >=10 )
            break;
    }
    pthread_exit(NULL);
}

void* consume(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&cond_mutex);
        while(!full)
        {
            pthread_cond_wait(&cond_send, &cond_mutex);
        }

        pthread_mutex_unlock(&cond_mutex);
        pthread_mutex_lock(&count_mutex);\
        full = 0;
        printf("consumed %d\n", count);
        pthread_cond_broadcast(&cond_recv);
        pthread_mutex_unlock(&count_mutex);
        if(count >=10 )
            break;
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t cons_thread, prod_thread;
    pthread_create(&prod_thread, NULL, produce, NULL);
    pthread_create(&cons_thread, NULL, consume, NULL);

    pthread_join(cons_thread, NULL);
    pthread_join(prod_thread, NULL);
    
}