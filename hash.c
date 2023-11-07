#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define SIZE 10

typedef struct person
{
    char name[MAX_NAME_LENGTH];
    int age;
    struct person* next;
} person;

person* hash_table[SIZE];

void init_hash_table()
{
    for(int i = 0; i < SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table()
{
    printf("Start\n");
    for(int i = 0; i < SIZE; i++)
    {
        if(hash_table[i] == NULL)
        {
            printf("%i\t--empty--", i);
        }
        else
        {
            person* tmp = hash_table[i];
            printf("%i\t", i);
            while(tmp != NULL)
            {
                printf("%s -- ", tmp->name);
                tmp = tmp->next;
            }
        }
        printf("\n");
    }
    
    printf("End\n");
}

unsigned int hash(char *name)
{
    int len = strnlen(name, MAX_NAME_LENGTH);
    unsigned int hash_value = 0;
    
    for(int i = 0; i < len; i++)
    {
        hash_value += name[i];
        hash_value *= name[i];
    }
    
    return hash_value % SIZE;
}

int hash_table_insert(person *p)
{
    if(p == NULL)
        return 0;
        
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    
    
    return 1;
}

person* hash_table_find(char* name)
{
    int index = hash(name);
    person* tmp = hash_table[index];
    while(tmp != NULL)
    {
        if(tmp != NULL && strncmp(name, tmp->name, MAX_NAME_LENGTH) == 0)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    
    return NULL;
}

void hash_table_delete(char* name)
{
    int index = hash(name);
    person* prev = NULL;
    person* tmp = hash_table[index];
    while(tmp != NULL && strncmp(name, tmp->name, MAX_NAME_LENGTH) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp == NULL)
        return;
    if(prev == NULL)
        hash_table[index] = tmp->next;
    else
        prev->next = tmp->next;
}

int main() {
    
    init_hash_table();
    print_table();
    
    person john = {"John", 25};
    person michael = {"Michael", 18};
    person anthony = {"Anthony", 35};
    person george = {"George", 35};
    person fred = {"Fred", 17};
    
    hash_table_insert(&john);
    hash_table_insert(&michael);
    hash_table_insert(&anthony);
    hash_table_insert(&george);
    
    print_table();
    
    hash_table_insert(&fred);
    print_table();
    
    // printf("John --- %u\n", hash("John"));
    // printf("Michael --- %u\n", hash("Michael"));
    // printf("Fred --- %u\n", hash("Fred"));
    // printf("Antony --- %u\n", hash("Antony"));
    
    person* p = hash_table_find("Fred");
    if(p == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Found\n");
    }
    
    hash_table_delete("Michael");
    print_table();

    return 0;
}