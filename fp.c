#include<stdio.h>

// 8 3
int asc(int a, int b)
{
    return a-b;
}

// 3 8
int desc(int a, int b)
{
    return b-a;
}

void shift_element(int *arr, int i, int (*fp) (int, int))
{
    int p;
    for(p = arr[i]; i > 0 && fp(arr[i-1], p) > 0; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[i] = p;
}

void insertion_sort(int *arr, int size, int (*fp)(int, int))
{
    for(int i = 1; i < size; i++)
    {
        if(fp(arr[i-1], arr[i]) > 0)
        {
            shift_element(arr, i, fp);
        }
    }
}

int main()
{
    int arr[5] = {3,4,2,6,5};
    insertion_sort(arr, 5, asc);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}