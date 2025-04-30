#include <stdio.h>
#include <time.h>
// 10마리의 서로 다른 동물 (각 카드 2장씩)
// 사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
// 모든 동물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기


int arrayAnimal[4][5]; // 카드 지도(20장)
char * strAnimal[10]; // 동물 이름

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
void conv_pos_x();
void conv_pos_y();

int main(void)
{
    srand(time(NULL));

    initialArray();
    initAnimalName();
    shuffleAnimal();

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

void initAnimalName()
{
    strAnimal[0] = "원숭이";
    strAnimal[1] = "하마";
    strAnimal[2] = "강아지";
    strAnimal[3] = "고양이";
    strAnimal[4] = "돼지";
    strAnimal[5] = "코끼리";
    strAnimal[6] = "기린";
    strAnimal[7] = "낙타";
    strAnimal[8] = "타조";
    strAnimal[9] = "호랑이";
}

void shuffleAnimal()
{
    // ㅁㅁㅁㅁㅁ
    // ㅁㅁㅁㅁㅁ
    // ㅁㅁㅁㅁㅁ
    // ㅁㅁㅁㅁㅁ
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);

            arrayAnimal[x][y] = i; // 동물 이름 중 하나가 카드 지도에 좌표처럼 들어감
        }
    }
}

int getEmptyPosition() // 좌표에서 빈 공간 찾기
{
    while(1)
}

void conv_pos_x()
{

}

void conv_pos_y()
{

}