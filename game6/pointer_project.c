#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// 프로젝트 : 물고기 키우기
// 1. 물고기가 6마리가 있어요.
// 2. 이들은 어항에 살고 있는데, 사막이에요.
// 3. 사막이 너무 더워서, 너무 건조해서 물이 아주 빨리 증발해요.
// 4. 물이 다 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살려주세요!
// 5. 물고기는 시간이 지날수록 점점 커져서 .. 나중에는 .. 냠냠 ..

int level;
int arrayFish[6];                     // 물고기 6마리의 어항 높이 (0~100)
int *cursor;                          // 커서 (물주기 위치) (0~5)
void initData();                      // 초기화 함수 선언
void printfFishes();                  // 물고기 어항 상태 출력
void decreaseWater(long elapsedTime); // 어항에 물이 감소하는 함수 선언
int checkFishAlive();                     // 물고기가 살아있는지 체크하는 함수 선언

int main(void)
{
    // UTF-8 출력
    SetConsoleOutputCP(CP_UTF8);

    long startTime = 0;        // 시작 시간
    long totalElapsedTime = 0; // 총 경과 시간
    int prevElapsedTime = 0;   // 직전 경과 시간 (최근에 물을 준 시간 간격)

    int num;
    initData();

    cursor = arrayFish; // cursor[0] .. cursor[1] .. cursor[5] 로 똑같이 사용 할 수 있음

    startTime = clock(); // 현재 시간을 milliseconds 단위로 반환 (1/1000초)
    while (1)            // 물고기가 다 죽거나 레벨업 완료할 때까지 진행
    {
        printfFishes(arrayFish, cursor); // 물고기 어항 상태 출력
        // getchar(); // (임시로) 사용자 입력 대기 확인용
        printf("몇 번 어항에 물을 주시겠어요? ");
        scanf_s("%d", &num); // 물을 줄 어항 번호 입력 받기 (1~6)

        // 입력값 체크
        // 번호가 123... 이렇게 연속적으로 입력될 경우 1, 2 가 아닌 12로 입력될 경우를 방지
        if (num < 1 || num > 6) // 입력값이 1~6이 아닐 경우
        {
            printf("잘못된 입력입니다. 다시 입력하세요.\n\n");
            continue; // 잘못된 입력일 경우 다시 물어보기
        }

        // 총 경과 시간
        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // 경과 시간 계산 (초 단위)
        printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

        // 직전 물 준 시간 (마지막으로 물 준 시간) 이후로 흐른 시간
        prevElapsedTime = totalElapsedTime - prevElapsedTime; // 직전 물 준 시간 이후로 흐른 시간 계산 (초 단위)
        printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

        // 어항의 물을 감소 (증발)
        decreaseWater(prevElapsedTime);

        // 사용자가 입력한 어항에 물을 준다
        // 1. 어항의 물이 0 이면? 물을 주지 않는다... 이미 고기가.. ㅠㅠ 흑흑...
        if (cursor[num - 1] <= 0) // 물고기가 죽은 경우
        {
            printf("%d 번 물고기는 이미 죽었습니다.. 물을 주지 않습니다 \n", num);
        }
        // 2. 어항의 물이 0이 아닌 경우? 물을 준다! 100 을 넘지 않는지 체크
        else if (cursor[num - 1] + 1 <= 100)
        {
            // 물을 준다
            printf("%d 번 어항에 물을 줍니다.\n\n", num);
            cursor[num - 1] += 1; // 물을 준다
        }

        // 레벨없을 할 건지 확인 (레벨업은 20초마다 한번씩 수행)
        if (totalElapsedTime / 20 > level - 1)
        {
            // 레벨업
            level++; // level : 1 -> level : 2 -> level : 3 -> ...
            printf("*** 축 레벨업 ! 기존 %d 레벨에서 %d 레벨로 업그레이드 ***\n\n", level - 1, level);

            // 최종 레벨 : 5
            if (level == 5)
            {
                printf("\n\n축하합니다, 최고 레벨을 달성하셨습니다. 게임을 종료합니다\n\n");
                exit(0); // 게임 종료 // 모든 프로그램 자체를 종료
            }
        }

        // 모든 물고기가 죽었는지 확인
        if (checkFishAlive() == 0) // 모든 물고기가 죽은 경우
        {
            // 물고기 모두 ㅠㅠ
            printf("모든 물고기가.. ㅠㅠ 흑흑... \n\n");
            exit(0);
        }
        else
        {
            // 최소 한마리 이상의 물고기는 살아 있음
            printf("물고기가 아직 살아 있어요!\n");
        }
        prevElapsedTime = totalElapsedTime; // 직전 물 준 시간 업데이트
        // 10ch -> 15초 (5초 : prevElapsedTime) -> 25초 (10초...?)
    }

    return 0;
}

void initData(void) // 어항 높이 초기화
{
    level = 1; // 게임 레벨 (1~5)
    for (int i = 0; i < 6; i++)
    {
        arrayFish[i] = 100; // 어항의 물 높이(0~100)
    }
}

void printfFishes() // 물고기 어항 상태 출력
{
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번 \n", 1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 6; i++)
    {
        printf(" %4d ", arrayFish[i]);
    }
    printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
    for (int i = 0; i < 6; i++)
    {
        arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3: 난이도 조절을 위한 값
        if (arrayFish[i] < 0)                           // 물고기 죽음
        {
            arrayFish[i] = 0; // 물고기 죽음
        }
    }
}

int checkFishAlive()
{
    for (int i = 0; i < 6; i++)
    {
        if (arrayFish[i] > 0) // 물고기가 살아있음
        {
            return 1; // 살아있는 물고기 있음
        }
    }
    return 0; // 모든 물고기가 죽음
}