#include<stdio.h>

enum DataType
{
    INT,
    FLOAT
};

union data
{
    int idata;
    float fdata;
};

struct multidata
{
    enum DataType dtype;
    union data dt;
};

int main()
{
    struct multidata md[3];
    md[0].dtype = FLOAT;
    md[0].dt.fdata = 12.3;

    md[1].dtype = INT;
    md[1].dt.idata = 12;

    md[2].dtype = FLOAT;
    md[2].dt.fdata = 3.4;

    for (int i = 0; i < 3; i++)
    {
        if(md[i].dtype == FLOAT)
        {
            printf("%.2f ", md[i].dt.fdata);
        }

        if(md[i].dtype == INT)
        {
            printf("%d ", md[i].dt.idata);
        }
    }
    
}