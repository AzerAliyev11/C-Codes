#include<stdio.h>
#include<stdlib.h>

void shift_element(int *arr[], int i)
{
    int *p;
    for(p = arr[i]; i > 0 && *arr[i - 1] > *p; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[i] = p;
}

void insertion_sort(int *arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        if(*arr[i] < *arr[i-1])
        {
            shift_element(arr, i);
        }
    }
}

int main()
{
    int arr[3];
    arr[0] = 67;
    arr[1] = 37;
    arr[2] = 13;

    int size = sizeof(arr)/sizeof(arr[0]);

    int *sortedArray[size];

    for(int i = 0; i < size; i++)
    {
        sortedArray[i] = &arr[i];
    }

    insertion_sort(sortedArray, size);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    for(int i = 0; i < size; i++)
    {
        printf("%d ", *sortedArray[i]);
    }

    printf("\n");
}