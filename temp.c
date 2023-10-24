#include<stdio.h>

enum TempType
{
    F,
    C
};

union Temperature
{
    float faranheit;
    float celcius;
};

struct TempStruct
{
    enum TempType type;
    union Temperature temp;
};

float Convert(struct TempStruct t)
{
    if(t.type == C)
    {
        return 1.8 * t.temp.celcius + 32;
    }
    else
    {
        return (t.temp.faranheit - 32)/1.8;
    }
}

int main()
{
    union Temperature tmp;
    tmp.celcius = 0;

    enum TempType tt = C;
    struct TempStruct t = {tt, tmp};
    printf("%f\n", Convert(t));
}