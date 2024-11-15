#include <stdio.h>
#include <string.h>

struct Book
{
    char title[100];
    char author[100];
    float price;
};

void SearchByAuthor(char* authorName, struct Book* books, int len)
{
    printf("Books by %s:", authorName);
    for(int i = 0; i < len; i++)
    {
        if(strcmp(authorName, books[i].author) == 0)
        {
            printf("%s, ", books[i].title);
        }
    }
    printf("\n");
}

void SortBooksByLowToHigh(struct Book* books, int len)
{
    for(int i = 1; i < len; i++)
    {
        struct Book insertVal = books[i];
        int j;

        for(j = i - 1; j >=0; j--)
        {
            if(insertVal.price < books[j].price)
            {
                books[j+1] = books[j];
            }
            else
            {
                break;
            }
        }

        books[j+1] = insertVal;
    }
}

void SortBooksByHighToLow(struct Book* books, int len)
{
    for(int i = 1; i < len; i++)
    {
        struct Book insertVal = books[i];
        int j;

        for(j = i - 1; j >=0; j--)
        {
            if(insertVal.price > books[j].price)
            {
                books[j+1] = books[j];
            }
            else
            {
                break;
            }
        }

        books[j+1] = insertVal;
    }
}

void PrintBooks(struct Book* books, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%s - %s - %.2f\n", books[i].title, books[i].author, books[i].price);
    }
}

void SearchByPriceRange(struct Book books[], int len, float rangeStart, float rangeEnd)
{
    int count = 0;

    for(int i = 0; i < len; i++)
    {
        if(books[i].price >= rangeStart && books[i].price <= rangeEnd)
        {
            printf("%s - %s - %.2f\n", books[i].title, books[i].author, books[i].price);
            count++;
        }
    }

    if(count == 0)
    {
        printf("No books in this price range. Adjust your filters!");
    }
}

int main()
{
    struct Book books[4] = {
        "Harry Potter", "J.K.Rowling", 20.99,
        "Lord Of the Rings", "Gandalf", 19.99, 
        "Crime and Punishment", "Ronaldo", 10.99,
        "Hobbit", "Gandalf", 109.99,
    };

    int len = sizeof(books)/ sizeof(books[0]);

    SearchByAuthor("Gandalf", books, len);

    SortBooksByHighToLow(books, len);
    PrintBooks(books, len);

    printf("---------------------------\n");
    SearchByPriceRange(books, len, 10, 20);
}