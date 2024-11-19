#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int *arr, int len, int (*comp)(int, int))
{
    for(int i = 1; i < len; i++)
    {
        int insertVal = arr[i];

        int j;
        for(j = i - 1; j >= 0; j--)
        {
            if(comp(arr[j], insertVal) > 0)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
        }

        arr[j+1] = insertVal;
    }
}

void GenericArrayPrint(void* arr, int size, int len, void (*print_type)(void* val))
{
    for(int i = 0; i < len; i++)
    {
        print_type(arr + i * size);
        printf(" ");
    }
    printf("\n");
}

void print_int(void* intData)
{
    printf("%d", *(int*)intData);
}

void print_float(void* floatData)
{
    printf("%f", *(float*)floatData);
}

int Ascending(int a, int b)
{
    return a - b;
}

int Descending(int a, int b)
{
    return b - a;
}

void PrintArray(int* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[6] = {9,5,4,2,6,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr, len, Ascending);

    //PrintArray(arr, len);
    GenericArrayPrint(arr, sizeof(int), len, print_int);

    float f_arr[3] = {3.14, 5.62, 9.82};
    GenericArrayPrint(f_arr, sizeof(float), 3, print_float);
}
