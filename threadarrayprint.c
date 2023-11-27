#include <stdio.h>
#include <pthread.h>
#include <time.h>

struct Index
{
    int start;
    int end;
};

int arr[10] = {1,2,3,4,5,6,7,8,9,10};

void* PrintArray(void *index)
{
    struct Index ind = *(struct Index*)(index);
    for (int i = ind.start; i <= ind.end; i++)
    {
        printf("Array[%d] = %d\n", i, arr[i]);
    }
    pthread_exit(NULL);
}

// int main()
// {
//     pthread_t threads[3];
//     struct Index indices[3];
//     clock_t start = clock();
//     for (int i = 0; i < 3; i++)
//     {
//         indices[i].start = i*3+1;
//         indices[i].end = i*3+3;
//         pthread_create(&threads[i], NULL, PrintArray, (void*)&indices[i]);
//         //pthread_join(threads[i], NULL);
//     }
//     clock_t end = clock();

//     printf("Time spent for execution: %f\n", ((double)end-start)/CLOCKS_PER_SEC);
//     pthread_exit(NULL);
// }

int main()
{
    clock_t start, end;
    start = clock();
    for (int i = 1; i < 10; i++)
    {
        printf("Array[%d] = %d\n", i, arr[i]);
    }
    end = clock();
    printf("Time spent for execution: %f\n", ((double)end-start)/CLOCKS_PER_SEC);
}