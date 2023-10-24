#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct list
{
    struct node* head;
};

struct node* CreateNode(int data)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;

    return n;
}

void AddToFront(struct list* l, int data)
{
    struct node* n = CreateNode(data);
    n->next = l->head;

    l->head = n;
}

void PrintElements(struct list* l)
{
    struct node* curr = l->head;
    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main()
{
    struct list mylist;
    mylist.head = NULL;
    AddToFront(&mylist, 5);
    AddToFront(&mylist, 12);
    PrintElements(&mylist);
}