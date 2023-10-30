#include<stdio.h>
#include<stdlib.h>

int main()
{
    int rows = 3;
    int cols;

    int **matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++)
    {
        scanf("%d", &cols);
        matrix[i] = (int*)malloc((cols + 1) * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            int a;
            scanf("%d", &a);
            matrix[i][j] = a;
        }
        
        matrix[i][cols] = -1;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; matrix[i][j] != -1; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}