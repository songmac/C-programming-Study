#include <stdio.h>
#include <time.h>
// 10마리의 서로 다른 동물 (각 카드 2장씩)
// 사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
// 모든 동물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기

int arrayAnimal[4][5]; // 카드 지도(20장)
char *strAnimal[10];   // 동물 이름

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);

int main(void)
{
    srand(time(NULL));

    initialArray();
    initAnimalName();
    shuffleAnimal();

    int failCount = 0; // 실패 횟수

    while (1)
    {
        int select1 = 0; // 사용자가 선택한 첫번째 수
        int select2 = 0; // 사용자가 선택한 두번째 수

        printAnimals(); // 동물 위치 출력
        printQuestion(); // 문제 출력 (카드 지도)
        printf("뒤집을 카드를 2개 고르세요 : ");
        scanf_s("%d %d", &select1, &select2);
    }

    return 0;
}

void initAnimalArray()
{
    for (int i; i < 4; i++)
    {
        for (int j; j < 4; j++)
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
    // ㅁㅁㅁㅁㅁ  0  1  2  3  4
    // ㅁㅁㅁㅁㅁ  5  6  7  8  9
    // ㅁㅁㅁㅁㅁ  10 11 12 13 14
    // ㅁㅁㅁㅁㅁ  15 16 17 18 19
    while (1)
    {
        int randPos = rand() % 20; // 0~19 사이의 숫자 반환
        // 19 -> (3, 4)
        int x = conv_pos_x(randPos); // 0 ~ 3 (추후 5로 나눈 몫의 값)
        int y = conv_pos_y(randPos); // 1 ~ 4 (추후 5로 나눈 나머지 값)

        if (arrayAnimal[x][y] == -1) // 카드 지도에 값이 비어있으면 실행
                                     // ->값이 비어있지 않으면, 동물 이름에 맞는 번호가 들어간 상태
        {
            return randPos;
        }
    }
    return 0;
}

int conv_pos_x(int x)
{
    // 19 -> (3, 4)
    return x / 5; // 0 ~ 3 (규칙 : 5로 나눈 몫의 값)
}

int conv_pos_y(int y)
{
    // 19 -> (3, 4)
    return y % 5; // 1 ~ 4 (규칙 : 5로 나눈 나머지 값)
}

void printAnimals()
{

}

void printQuestion()
{
    
}