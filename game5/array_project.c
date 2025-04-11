// 수정중

#include <stdio.h>
#include <time.h>
#include <stdlib.h> // srand(), rand()

int main(void)
{
    // 0. 변수 초기화
    srand(time(NULL));                              // 난수 생성기 초기화
    printf("\n\n === 아빠는 대머리 게임 === \n\n"); // 게임 설명 : 발모제를 맞추는 게임

    int answer;                 // 사용자 입력값 (1~4)
    int treatment = rand() % 4; // 발모제 선택 (0~3)

    int cntShowBottle = 0;     // 이번 게임에 보여줄 병 갯수
    int prevCntShowBottle = 0; // 이전 게임에 보여준 병 갯수
    // 서로 보여주는 병 갯수를 다르게 하여 정답률 향상 (처음엔 2개 -> 다음엔 3개 ...)

    // 0. 3번의 기회를 주는 루프 (3번의 발모제 투여 시도)
    for (int i = 1; i <= 3; i++)
    {
        int bottle[4] = {0, 0, 0, 0}; // 병 배열 초기화 (4개)
        do
        {
            cntShowBottle = rand() % 4; // 보여줄 병 갯수 (0~3)
        } while (cntShowBottle == prevCntShowBottle); // 이전과 같은 갯수는 안됨
        prevCntShowBottle = cntShowBottle; // 이전 게임에 보여준 병 갯수 저장

        int isincluded = 0; // 보여줄 병 중에 발모제가 포함되었는지 여부 (1 :포함, 0 : 미포함)

        // 1. [내부 로직] 보여줄 병 종류를 선택
        for (int j = 0; j < cntShowBottle; j++)
        {
            int randBottle = rand() % 4; // 보여줄 병 종류 (0~3)

            // 아직 선택되지 않은 병 종류라면, 선택 처리
            if (bottle[randBottle] == 0)
            {
                bottle[randBottle] = 1; // 선택된 병 종류에 1 저장

                if (randBottle == treatment) // 발모제가 포함된 병 종류일 때,
                {
                    isincluded = 1; // 선택된 병 종류가 있음을 표시 (내부 변수임)
                }
            }
            // 이미 선택된 병 종류라면, 다시 선택
            else
            {
                j--; // 다시 선택하기 위해 인덱스 감소
            }
        }

        // 2. [외부 화면] 사용자에게 문제 표시
        printf(" > %d번째 시도 : ", i);

        // 몇 번 물약을 머리에 바르는지 나타냄
        for (int k = 0; k < 4; k++)
        {
            if (bottle[k] == 1) // 보여줄 병 종류라면
            {
                printf("%d ", k + 1); // 병 번호는 1부터 시작
            }
        }
        printf("물약을 머리에 바릅니다 \n\n");

        if (isincluded == 1) // 발모제가 포함된 병이 있다면
        {
            printf(" > 발모제 투여 성공! 머리가 났어요 !! \n\n");
            // break; // 게임 종료
        }
        else // 발모제가 포함된 병이 없다면
        {
            printf(" > 발모제 투여 실패! 머리가 나지 않았어요 ㅠㅠ \n\n");
        }

        printf("\n... 계속 하려면 아무키나 누르세요...");

        // getchar(); // 버퍼에 남은 \n 제거
        getchar(); // 사용자 입력 대기
        printf("\n\n\n");
    }

    // 3. [외부 화면] 사용자가 정답을 입력

    printf("\n\n발모제는 몇 번일까요? (1~4) : ");
    scanf("%d", &answer); // 사용자 입력값

    if (answer - 1 == treatment)
    {
        printf(" > 정답입니다! 발모제는 %d번입니다.\n\n", treatment + 1); // 정답
    }
    else
    {
        printf(" > 오답입니다! 발모제는 %d번입니다.\n\n", treatment + 1); // 오답
    }

    return 0;
}