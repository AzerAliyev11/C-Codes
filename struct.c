#include<stdio.h>

struct employee
{
    char *name;
    int *age;
};

struct point
{
    long l;
    int i;
};

//packing a variable in memory
int variable __attribute__((aligned(16)));

int main()
{
    // int a = 27;
    // struct employee e1 = {"John", &a};
    // struct employee e2;

    // e2 = e1;

    // printf("name e1 = %d, name e2 = %d\n", *e1.age, *e2.age);
    // printf("name e1 = %p, name e2 = %p\n", &e1.age, (void*)e2.age);
    // *e2.age = 12;
    // printf("name e1 = %d, name e2 = %d\n", *e1.age, *e2.age);

    // struct employee *e3 = &e2;
    // *(e3->age) = 13;
    // printf("e2 age = %d\n", *e2.age);

    // // struct point p[3] = {{1,2},{3,4},{5,6}};
    // // printf("p3.x = %d\n", p[2].x);

    struct point p[3] = {4,5,6,7,1,2};
    //struct point *p1
    printf("%p\n", (&(p[0].l) + 2));
    printf("%p\n", (&(p[0].l) + 1));
}