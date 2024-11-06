#include <stdio.h>
#include <string.h>

void ReverseWord(char* start, char* end)
{
    while(start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void ReverseWords(char* str)
{
    int len = strlen(str);
    char* start = str;
    char* finish = str + len;

    char* wordEnd;
    char* startWord = start;

    while(start < finish)
    {
        if(*start != ' ')
        {
            start++;
        }
        else
        {
            wordEnd = start-1; //wordEnd should be white space - 1

            ReverseWord(startWord, wordEnd);
            start++; //increment start to the beginning of the new word
            startWord = start; //indicate that this is the starting
            //for the next word
        }
    }

    wordEnd = start-2; //to compensate for the \n character
    ReverseWord(startWord, wordEnd);
}

int main()
{
    char sentence[100];
    printf("Enter the sentence: ");
    fgets(sentence, 100, stdin); //secure
    //gets(sentence);  //not secure

    ReverseWords(sentence);
    printf("sentence = %s\n", sentence);


}