#include <stdio.h>
#include <time.h>

// 프로젝트 : 물고기 키우기
// 1. 물고기가 6마리가 있어요.
// 2. 이들은 어항에 살고 있는데, 사막이에요.
// 3. 사막이 너무 더워서, 너무 건조해서 물이 아주 빨리 증발해요.
// 4. 물이 다 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살려주세요!
// 5. 물고기는 시간이 지날수록 점점 커져서 .. 나중에는 .. 냠냠 ..

int level;
int arrayFish[6]; // 물고기 6마리의 어항 높이 (0~100)
int * cursor; // 커서 (물주기 위치) (0~5)
void initData(); // 초기화 함수 선언
void printfFishes(); // 물고기 어항 상태 출력


int main(void)
{
    long startTime = 0; // 시작 시간
    long totalElapsedTime = 0; // 총 경과 시간
    int prevElapsedTime = 0; // 직전 경과 시간 (최근에 물을 준 시간 간격)

    int num;
    initData();

    cursor = arrayFish; // cursor[0] .. cursor[1] .. cursor[5] 로 똑같이 사용 할 수 있음

    startTime = clock(); // 현재 시간을 milliseconds 단위로 반환 (1/1000초)
    while (1) // 물고기가 다 죽거나 레벨업 완료할 때까지 진행
    {
        printfFishes(arrayFish, cursor); // 물고기 어항 상태 출력
        getchar(); // 사용자 입력 대기
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