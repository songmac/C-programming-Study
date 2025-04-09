#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int getRandomNumber(int level);                   // 랜덤한 수를 생성하는 함수
void showQuestion(int level, int num1, int num2); // 문제를 보여주는 함수
void playGame(); // 게임을 실행하는 함수

int main(void)
{
    // 문이 5개가 있고, 각 문마다 점점 어려운 수식 퀴즈가 출제 (랜덤)
    // 문제 유형 : x*y = ?
    // 맞히면 통과, 틀리면 실패

    srand(time(NULL)); // 랜덤 시드 초기화

    printf("\n🎉비밀번호 맞히기 게임에 오신 것을 환영합니다!🎉\n\n");
    printf("비밀번호는 문제의 수식을 계산한 답입니다.\n단, 정답을 못맞췄을 경우 게임이 곧바로 종료됩니다.\n");
    printf("문제는 총 5문제이며, \n게임을 시작하려면 Y, 나가기를 원한다면 N을 입력해주세요.\n\n");
    printf("게임을 시작하시겠습니까? (Y/N) >> ");

    while (1)
    {
        char start;           // 게임 시작 여부
        scanf(" %c", &start); // 문자열 입력받기 (공백을 넣어줘야 정상적으로 입력됨)
        int count = 0;        // 정답 개수

        if (start == 'N' || start == 'n') // 게임 종료
        {
            printf("\n게임을 종료합니다.\n\n");
            exit(0); // main 포함, 프로그램 종료
        }
        else if (start != 'Y' && start != 'y') // 잘못된 입력
        {
            printf("\n잘못된 입력입니다. 게임을 종료합니다.\n\n");
            exit(0); // main 포함, 프로그램 종료
        }

        for (int i = 1; i <= 5; i++)
        {
            int num1 = getRandomNumber(i);
            int num2 = getRandomNumber(i);
            showQuestion(i, num1, num2); // 문제를 보여주는 함수

            int answer = -1;
            scanf("%d", &answer); // 정답 입력 받기
            if (answer == -1)     // 종료 조건
            {
                printf("\n게임을 종료합니다.\n");
                break;  // 가장 가까운 반복문 종료
            }

            if (answer == num1 * num2) // 정답 체크
            {
                printf("\n=> 정답입니다!\n");
                count++;
            }
            else
            {
                printf("\n=> 틀렸습니다.\n");
                printf("\n\n%d개의 문제 중 정답의 개수는 %d 입니다!\n", i, count);
                printf("\n게임을 종료합니다.\n\n");
                break; 
            }

            if (count == 5)
            {
                printf("\n\n\n축하합니다! 비밀번호를 모두 맞히셨습니다!\n\n");
                printf("\n게임을 다시 시작하시겠습니까? (Y/N) >> ");
            }
        }
        // 게임 끝나고 나면 항상 재시작 물어보기
        printf("\n게임을 다시 시작하시겠습니까? (Y/N) >> ");
        scanf(" %c", &start);

        if (start == 'N' || start == 'n')
        {
            printf("\n게임을 종료합니다.\n\n");
            break;
        }
        else if (start != 'Y' && start != 'y')
        {
            printf("\n잘못된 입력입니다. 게임을 종료합니다.\n\n");
            break;
        }
    }
}

int getRandomNumber(int level)
{
    return rand() % (level * 7) + 1;  // 난이도에 따라 랜덤 숫자 커지도록 설정
}
void showQuestion(int level, int num1, int num2)
{
    printf("\n\n\n######## %d 번째 비밀번호 ########\n", level);
    printf("\n\t%d x %d = ?\n\n", num1, num2);
    printf("#################################\n\n");
    printf("비밀번호를 입력하세요 (종료 : -1) >> ");
}