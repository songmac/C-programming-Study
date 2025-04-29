#include <stdio.h>

void main()
{
    int test[] = {1, 2, 3};
    int *p = test;
    printf("%d\n", *p);     // 1
    printf("%d\n", ++*p);   // 2
    printf("%d\n", *p++);   // 2
    printf("%d\n", *(p++)); // 2
    printf("%d\n", (*p)++); // 3
    printf("%d\n", *p);     // 4
}