#include<stdio.h>
#define array_length(arr) (sizeof(arr) == 0 ? 0 : sizeof(arr)/sizeof(arr[0]))

int arr[5] = {3,4,1,2,5};

int *findMin()
{
    int *first = arr;
    int *last = arr + array_length(arr);
    int *min = &arr[0];

    for(;first < last; first++)
    {
        if(*first < *min)
        {
            *min = *first;
        }
    }

    return min;
}

void reverse_array()
{
    int *beg = arr;
    int *end = arr + array_length(arr) - 1;

    while(beg < end)
    {
        int copy = *beg;
        *beg = *end;
        *end = copy;
        beg++;
        end--;
    }
}

int main()
{
    //printf("Min = %d\n", *findMin());
    reverse_array();
    for(int i = 0; i < array_length(arr); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}