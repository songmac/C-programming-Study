#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

int main(void) // main 함수의 반환 자료형이 int 라는 것을 의미. 즉, main 함수는 정수를 반환하는 함수다.
               // 정수형이어야 하는 이유는 운영체제가 프로그램 실행 후 프로그램 실행 성공/실패 여부를 확인할 수 있어야 하기 때문.
               // e.g. return 0;은 정상종료 이고, return 1; 또는 다른 숫자를 오류 발생을 의미.
{
    SetConsoleOutputCP(CP_UTF8);

    /*
    // 버스를 탄다고 가정.
    // 학생(20세 미만) / 일반인(20세 이상)으로 구분하면?
    // if (조건) { ... } else { ... }
    int age = 18;
    if (age >= 20)
    {
        printf("일반인 입니다.\n");
    }
    else
    {
        printf("학생입니다.\n");
    }

    // 초등학생(8-13) / 중학생(14-16) / 고등학생(17-19)으로 구분하면?
    // if (조건) { ... } else if (조건) { ... } else { ... }
    int age = 25;
    if (age >= 8 && age <= 13)
    {
        printf("초등학생입니다.\n");
    }
    else if (age >= 14 && age <= 16)
    {
        printf("중학생입니다.\n");
    }
    else if (age >= 17 && age <= 19)
    {
        printf("고등학생입니다.\n");
    }
    else
    {
        printf("학생이 아닙니다.\n");
    }


    // break / continue
    // 1번부터 30번까지 있는 반에서 1번부터 4번까지 조별 발표를 합니다.
    for (int i =1; i <=30; i++)
    {
        if (i >= 6)
        {
            printf("나머지 학생은 집에 가세요.\n");
            break;  // 해당 조건에서 break를 만나면 for문을 빠져 나옴
        }
        printf("%d번 학생은 조별 발표 준비를 하세요.\n", i);
    }

    // 1번부터 30번까지 있는 반에서 7번 학생은 아파서 결석
    // 7번을 제외하고 6번부터 10번까지 조별 발표를 하세요.
    for (int i = 1; i <= 30; i++)
    {
        if (i >= 6 && i <= 10)
        {
            if (i == 7)
            {
                printf("%d번 학생은 결석입니다.\n", i);
                continue;
            }
            printf("%d번 학생은 조별 발표 준비를 하세요.\n", i);
        }
    }


    // && ||
    int a = 10;
    int b = 11;
    int c = 12;
    int d = 13;
    if (a == b && c == d)
    {
        printf("a와 b, 그리고 c와 d의 값이 같습니다.\n");
    }
    else if (a == b || c == d)
    {
        printf("a와 b, 혹은 c와 d의 값이 같습니다.\n");
    }
    else
    {
        printf("값이 서로 다르네요.\n");
    }


    // 가위 0, 바위 1, 보 2
    srand(time(NULL));
    int i = rand() % 3; // 0 ~ 2 반환
    if (i == 0)
    {
        printf("가위\n");
    }
    else if (i == 1)
    {
        printf("바위\n");
    }
    else if (i == 2)
    {
        printf("보\n");
    }
    else
    {
        printf("몰라요\n");
    }

    // 가위 0, 바위 1, 보 2
    // switch-case
    srand(time(NULL));
    int i = rand() % 3; // 0 ~ 2 반환
    // int i = 0;  // 가위, 바위, 보, 몰라요 출력
    // int i = 1;  // 바위, 보, 몰라요 출력
    switch (i)
    {
        case 0: printf("가위\n"); break;
        case 1: printf("바위\n"); break;  // 첫번째 case가 참이면 밑의 case 조건은 확인도 안하고 출력해버리기 때문에 break문이 필요
        case 2: printf("보\n"); break;
        default: printf("몰라요\n"); break;
    }


    // 초등학생(8-13) / 중학생(14-16) / 고등학생(17-19)으로 구분하면?
    // if-else를 switch-case 로 바꾸기
    int age = 25;
    switch (age)
    {
        case 8: 
        case 9: 
        case 10: 
        case 11: 
        case 12: 
        case 13: printf("초등학생입니다.\n"); break;
        case 14: 
        case 15: 
        case 16: printf("중학생입니다.\n"); break;
        case 17: 
        case 18: 
        case 19: printf("고등학생입니다.\n"); break;
        default: printf("학생이 아닙니다.\n"); break;
    }
    */


    // 프로젝트 : Up and Down
    srand(time(NULL));
    // int num = rand() % 100; // 0 ~ 99 사이의 숫자 출력
    int num = rand() % 100 + 1; // 1 ~ 100 사이의 숫자 출력
    // printf("숫자 : %d\n", num);
    int answer = 0; // 정답
    int chance = 5; // 기회
    while (chance > 0)
    {
        printf("남은 기회 %d 번\n", chance--);
        printf("숫자를 맞혀보세요 (1~100) : ");
        scanf_s("%d", &answer);

        if (answer > num)
        {
            printf("DOWN ↓\n\n");
        }
        else if (answer < num)
        {
            printf("UP ↑\n\n");
        }
        else if (answer == num)
        {
            printf("정답입니다 !\n\n");
            break;
        }
        else
        {
            printf("알 수 없는 오류가 발생했어요.");
        }
        if (chance == 0)
        {
            printf("모든 기회를 다 사용하셨네요. 아쉽게 실패했습니다.\n");
            break;
        }
    }

    return 0;
}