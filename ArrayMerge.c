#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include<stdlib.h>

int NormalSort(int a, int b)
{
    return a-b;
}

int OddEvenSort(int a, int b)
{
    if(a%2 == 0 && b%2 == 1)
    {
        return 1;
    }
    else if(a%2 == 1 && b%2 == 0)
    {
        return 0;
    }
    if((a%2 == 0 && b%2 == 0) || (a%2 == 1 && b%2 == 1))
    {
        return a-b;
    }
}

int* ConcArray(int *a1, int *a2, int size1, int size2, int (*fp)(int, int))
{
    int* newArray = (int*)malloc((size1+size2)*sizeof(int));
    int i = 0, j = 0, k = 0;

    while(i < size1 && j < size2)
    {
        if(fp(a1[i], a2[j]) > 0)
        {
            newArray[k] = a2[j];
            k++;
            j++;
        }
        else
        {
            newArray[k] = a1[i];
            k++;
            i++;
        }
    }

    while(i < size1)
    {
        newArray[k] = a1[i];
        i++;
        k++;
    }

    while(j < size2)
    {
        newArray[k] = a2[j];
        j++;
        k++;
    }

    return newArray;
}

int main () 
{   
    int a1[3] = {1,3,6};
    int a2[3] = {5,4,8};

    int* nA = ConcArray(a1, a2, 3, 3, OddEvenSort);

    for(int i = 0; i < 6; i++)
    {
        printf("%d ", nA[i]);
    }
    printf("\n");
}