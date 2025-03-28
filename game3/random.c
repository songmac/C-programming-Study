#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // srand(time(NULL)); // 난수 초기화
    // int num = rand() % 3;   // 0~2 중에 랜덤한 숫자를 뽑음

    printf("난수 초기화 이전..\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand() % 10); // 난수 처리를 안했기 때문에 매번 일정한 값이 출력됨
    }

    srand(time(NULL)); // 난수 초기화
    printf("\n난수 초기화 이후..\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand() % 10); // 난수 처리를 안했기 때문에 매번 일정한 값이 출력됨
    }


    return 0;
}