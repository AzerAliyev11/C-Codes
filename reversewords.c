#include <stdio.h>
#include<string.h>

void ReverseWord(char word[])
{
    int len = strlen(word);
    int i = 0, j = len-1;

    while(i < j)
    {
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
        i++;
        j--;
    }
}

void GetWords(char* str, char* ans)
{
    int len = strlen(str);
    char word[100];
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] != ' ')
        {
            word[j] = str[i];
            j++;
        }
        else
        {
            word[j] = '\0';
            ReverseWord(word);
            j = 0;

            strcat(ans, word);
            strcat(ans, " ");
            printf("ans = %s\n", ans);
        }

    }
}

int main()
{
    char str[100];
    printf("Enter the sentence: ");
    gets(str);

    char ans[100] = "";
    GetWords(str, ans);

    printf("ans = %s\n", ans);
}