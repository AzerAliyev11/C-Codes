//task 1. Count the number of words in a string that can have
//multiple whitespaces between the words.

//example 1. "   Hi everyone    welcome  to   the class    "

//task2: abcdabbde -> abcde

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int WordCount(char* sentence)
{
    int size = strlen(sentence);

    bool whiteSpaceFlagReset = false; //whether we are in white space area or not
    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(sentence[i] != ' ')
        {
            whiteSpaceFlagReset = true; //to indicate end of white spaces tiil current word
        }
        else
        {
            if(whiteSpaceFlagReset == true) //my word has ended
            {
                count++;
            }
            whiteSpaceFlagReset = false; //we are in white space area
        }
    }

    if(whiteSpaceFlagReset == true)
        count++;

    return count;
}

char* RemoveDuplicatesI(char sentence[])
{
    int size = strlen(sentence);

    char* ans = (char*)malloc(26 * sizeof(char));
    int j = 0;

    for(int i = 0; i < size; i++)
    {
        bool flag = true;
        for(int j = i - 1; j >= 0; j--)
        {
            if(sentence[i] == sentence[j])
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            ans[j] = sentence[i];
            j++;
        }
    }

    ans[j] = '\0';

    return ans;
}



int main()
{
    char sentence[] = "programming";
    
    int size = strlen(sentence);
    char ans[26];
    int j; //index of ans

    printf("test: %s\n", RemoveDuplicatesI(sentence));

    int characterCount[26]; //frequency array
    memset(characterCount, 0, 26 * sizeof(int)); //array initialization with function (initialized to 0)

    // manual array initialization
    // for(int i = 0; i < 26; i++)
    // {
    //     characterCount[i] = 0;
    // }

    //if characterCount array was global, it would have been initialized to 0's by default

    //count array method
    for(int i = 0; i < size; i++)
    {
        char currentLetter = sentence[i];
        characterCount[currentLetter - 'a']++;
        if(characterCount[currentLetter - 'a'] == 1)
        {
            ans[j] = currentLetter;
            j++;
        }
    }

    //boolean array method (uncomment to use)
    // for(int i = 0; i < size; i++)
    // {
    //     char currentLetter = sentence[i];
    //     if(characterCount[currentLetter - 'a'] == 0) //if we have not seen it before
    //     {
    //         ans[j] = currentLetter; //copy to answer
    //         j++; //move your answer index forward
    //         characterCount[currentLetter - 'a'] = 1; // mark currentLetter as seen
    //     }
    // }

    ans[j] = '\0';

    printf("ans = %s\n", ans);
    
}