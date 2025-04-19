#include <stdio.h>

int refunc(int i)
{
    printf("%d ", i); // c언어는 자동 띄어쓰기 기능이 없음
    if (i < 1)
    {
        return 2;
    }
    else
    {
        return (3 * refunc(i - 1) + 1);
    }
}

void main()
{
    int n;
    n = refunc(7);

    printf("\n");
    printf("%d\n", n);
}