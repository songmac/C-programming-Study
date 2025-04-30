#include <stdio.h>
#include <time.h>
// 10마리의 서로 다른 동물 (각 카드 2장씩)
// 사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
// 모든 동물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기


int arrayAnimal[4][5];
void initAnimalArray();

int main(void)
{
    srand(time(NULL));

    initialArray();

    return 0;
}    

void initAnimalArray()
{
    for (int i; i < 4; i++)
    {
        for (int j; j<4; j++)
        {
            arrayAnimal[i][j] = -1; // 우선 -1로 초기화
        }
    }
}