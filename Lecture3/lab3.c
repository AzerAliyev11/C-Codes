#include <stdio.h>

int SumOfDigits(int n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += n%10;
        n /= 10;
    }

    return sum;
}

void FibonacciSequence(int n)
{
    int first = 0;
    int second = 1;

    if(n == 1)
    {
        printf("0\n");
        return;
    }

    if(n >= 2)
    {
        printf("0 1 ");
    }

    while(n - 2 > 0)
    {
        int nextFib = first + second;
        printf("%d ", nextFib);
        first = second;
        second = nextFib;
        n--;
    }
}

void PrintRightTriangle(int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void PrintPyramid(int rows)
{
    for(int i = 1; i <= rows; i++)
    {
        for(int j = rows - i; j > 0; j--)
        {
            printf(" ");
        }

        for(int k = 1; k <= 2*i - 1; k++)
        {
            printf("*");
        }

        printf("\n");
    }
}

int main()
{
    //first question
    char ch;
    switch (ch)
    {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            puts("Vowel");
            break;
        default:
            puts("Consonant");
            break;
    }

    int month;
    switch (month)
    {
        case 12:
        case 1:
        case 2:
            puts("Winter");
            break;
        case 3:
        case 4:
        case 5:
            puts("Spring");
            break;
        case 6:
        case 7:
        case 8:
            puts("Summer");
            break;
        case 9:
        case 10:
        case 11:
            puts("Autumn");
            break;
        default:
            puts("Invalid month");
            break;
    }

    PrintPyramid(4);

    //FibonacciSequence(10);

    //PrintRightTriangle(6);
}