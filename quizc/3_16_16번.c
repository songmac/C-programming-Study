// 자릿수 합계 구하기

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

int main(void) 
{
    SetConsoleOutputCP(CP_UTF8);

    int input;
    int output = 0;
    printf("자연수 입력 : ");
    scanf("%d", &input);
    while(input)
    {
        output += input % 10;
        input /= 10;
    }
    printf("자릿수 합계 : %d\n", output);

    return 0;
}