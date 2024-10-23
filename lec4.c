#include <stdio.h>

int main()
{
    char name[20];
    char surname[20];
    int grade;

    FILE* myFile = fopen("lec4.txt", "w");;

    for(int i = 1; i <= 10; i++)
    {
        char msg[200];
        sprintf(msg, "Enter name, surname and grade for student %d\n", i);
        printf("%s", msg);
        scanf("%s %s %d", name, surname, &grade);
        fprintf(myFile, "Name: %s Surname: %s Grade: %d\n", name, surname, grade);
    }

    fclose(myFile);

    myFile = fopen("lec4.txt", "r");
    float average = 0;
    int numOfStudents = 0;

    char copyStr[1000];

    while(fscanf(myFile, "Name: %s Surname: %s Grade: %d\n", name, surname, &grade) != EOF)
    {
        average += (float)grade;
        numOfStudents++;
    }

    printf("average is: %f\n", average/numOfStudents);
}