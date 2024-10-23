#include <stdio.h>
#include<string.h>

#define array_length(arr) (int)(sizeof(arr) == 0 ? 0 : sizeof(arr)/sizeof(arr[0]))

int arr[10] = {1,5,8,3,4,5,4,2,6,9};

void reverse_array()
{
    int len = array_length(arr);

    for(int i = 0; i < len/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[len-1-i];
        arr[len-1-i] = temp;
    }
}

int string_length(char *str)
{
    int length = 0;

    while(*str != '\0')
    {
        length++;
        str++;
    }

    return length;
}

void copy_string(char *dest, char *source, int destSize)
{
    int len = string_length(source);

    if(len > destSize)
    {
        printf("Destination size is not large enough!\n");
        return;
    }

    int i = 0;
    while(source[i]!='\0')
    {
        dest[i] = source[i];
        i++;
    }
}

void con_string(char *str1, char *str2)
{
    while(*str1 != '\0')
    {
        str1++;
    }

    while(*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0';
}

int* LinearSearch(int* arr, int val, int size)
{
    int* begin = arr;
    int *end = arr+size;

    int i = 0;

    while(begin < end)
    {
        if(*begin == val)
        {
            return begin;
        }

        begin++;
    }

    return NULL;
}

void InsertionSortP(int* arr, int size)
{
    for(int* begin = arr+1; begin < arr + size; begin++)
    {
        int insertValue = *begin;
        int* j;
        for(j = begin-1; j >= arr; j--)
        {
            if(insertValue < *j)
            {
                *(j+1) = *j;
            }
            else
            {
                break;
            }
        }

        *(j+1) = insertValue;
    }
}

void InsertionSort(int arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int insertValue = arr[i];
        int j;
        for(j = i-1; j >= 0; j--)
        {
            if(insertValue < arr[j])
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
        }

        arr[j+1] = insertValue;
    }
}

int main() {

    reverse_array();

    int len = array_length(arr);
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n%d\n", string_length("Hi everyone"));

    char str[20] = "hi everyone";
    char str1[20] = " now!";

    //copy_string(str1, str, sizeof(str1));

    con_string(str, str1);
    printf("%s\n", str);
}