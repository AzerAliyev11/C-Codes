#include<stdio.h>

typedef union
{
    int intData;
    float floatData;
} Data;

typedef enum
{
    INT_DATA,
    FLOAT_DATA
} DataType;

typedef struct
{
    Data data;
    DataType dType;
} myStruct;

void Adder(myStruct s1, myStruct s2)
{
    if(s1.dType != s2.dType)
    {
        printf("Data types does not match!\n");
        return;
    }

    if(s1.dType == INT_DATA)
    {
        printf("result = %d\n", s1.data.intData + s2.data.intData);
    }
    else
    {
        printf("result = %f\n", s1.data.floatData + s2.data.floatData);
    }
}

int main()
{
    myStruct s1, s2;
    s1.data.intData = 45;
    s1.dType = INT_DATA;

    s2.data.floatData = 54;
    s2.dType = FLOAT_DATA;

    Adder(s1, s2); 
}