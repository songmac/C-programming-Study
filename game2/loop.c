#include <stdio.h>
#include <windows.h>

// 하나의 프로젝트 파일(폴더 단위)에서 main 함수는 한 개 여야 함
// main 함수란? 프로그램의 시작점이자 종료 시 결과 값을 운영체제에 알려주는 함수 (운영체제가 자동으로 호출)
// return 0; 은 프로그램이 정상적으로 종료되었어요 라고 알려주는 것. 하지만 최신 컴파일러에서는 컴파일러가 자동으로 넣어줌

int main(void)
{
    // UTF-8 출력
    SetConsoleOutputCP(CP_UTF8);
    /*
    // ++(뿔뿔)
    int a = 10;
    printf("a는 %d\n", a);
    a++; // a = a + 1;
    printf("a는 %d\n", a);
    a++;
    printf("a는 %d\n", a);


    int b = 20;
    printf("b는 %d\n", b);
    printf("b는 %d\n", ++b);    // b에 1을 더하고 출력
    printf("b는 %d\n", b++);    // b를 출력한 후 1을 더함
    printf("b는 %d\n", b);


    int i = 1;
    printf("Hello, World %d\n", i++);
    printf("Hello, World %d\n", i++);
    printf("Hello, World %d\n", i++);
    printf("Hello, World %d\n", i++);
    printf("Hello, World %d\n", i++);
    printf("Hello, World %d\n", i++);
    printf("Hello, World %d\n", i++);
    printf("Hello, World %d\n", i++);
    printf("Hello, World %d\n", i++);
    printf("Hello, World %d\n", i);


    // 반복문(for, while, do while)
    // for (선언: 조건: 증감){ }
    for (int i = 1; i <= 10; i++)
    {
        printf("Hello, World %d\n", i);
    }

    // while (조건){ }
    int i = 1;
    while (i <= 10)
    {
        printf("Hello, World %d\n", i++);
        // i++;
    }

    // do { } while (조건);
    int i = 1;
    do {
        printf("Hello, World %d\n", i++);
    } while (i <= 10);

    // 이중 반복문
    for (int i = 1; i <= 3; i++)
    {
        printf("첫 번째 반복문 %d\n", i);

        for (int j = 1; j <= 5; j++)
        {
            printf("    두 번째 반복문 %d\n", j);
        }

    }

    // 구구단
    for (int i = 2; i <= 9; i++)
    {
        printf("---%d단 계산---\n", i);

        for (int j = 1; j <= 9; j++)
        {
            printf("%d X %d = %d\n", i, j, i*j);
        }
    }

    // 이중 반복문 파헤치기
    // 별 출력
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
    printf("\n");

    }

    // 거꾸로 별 출력
    for (int i = 1; i <= 5; i++)
    {
        // 공백 출력
        for (int j = 1; j <= 5 - i; j++)
        {
            printf(" ");
        }
        // 별 출력
        for (int k = 1; k <= i; k++)
        {
            printf("*");
        }

    printf("\n");

    }
    */

    // 프로젝트 : 피라미드를 쌓아라
    int floor;
    printf("몇 층으로 쌓겠느냐? ");
    scanf_s("%d", &floor);
    for (int i = 0; i < floor; i++)
    {
        for (int j = 0; j < floor - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i * 2 + 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}