#include <stdio.h>

// 구조체 선언 (전역 위치에)
// 구조체 : 반복되는 정보를 관리할 때 용이
struct GameInfo
{
    char *name; // 포인터변수 사용 이유? 문자열 리터럴의 주소를 저장 (읽기전용)
                // char name[100] 처럼 배열로 선언하면  직접 문자열 데이터를 저장하기 때문에 메모리 효율이 떨어짐 (문자열을 복사해서 사용, 값 수정 가능)
    int year;
    int price;
    char *company;
};

int main(void)
{
    /*
    // [게임 출시]
    // 이름 : 나도 게임
    // 발매년도 : 2017 년
    // 가격 : 50원
    // 제작사 : 나도회사

    char * name = "나도게임";
    int year = 2017;
    int price = 50;
    char * company = "나도회사";

    // [또 다른 게임 출시]
    // 이름 : 너도 게임
    // 발매년도 : 2017 년
    // 가격 : 100원
    // 제작사 : 너도회사
    char * name2 = "너도게임";
    int year2 = 2017;
    int price2 = 100;
    char * company2 = "너도회사";
    */


    // 구조체 사용
    struct GameInfo gameInfo1; // struct GamdInfo 까지 자료형, 그 이후가 변수명임
    // struct GameInfo gameInfo2;
    gameInfo1.name = "나도게임";
    gameInfo1.year = 2017;
    gameInfo1.price = 50;
    gameInfo1.company = "나도회사";

    // 구조체 출력
    printf("-- 게임 출시 정보 --\n");
    printf("게임명 : %s\n", gameInfo1.name);
    printf("발매년도 : %d\n", gameInfo1.year);
    printf("가격 : %d\n", gameInfo1.price);
    printf("제작사 : %s\n", gameInfo1.company);

    // 구조체를 배열처럼 초기화
    struct GameInfo gameInfo2 = {"너도게임", 2017, 100, "너도회사"};
    printf("-- 또다른 게임 출시 정보 --\n");
    printf("게임명 : %s\n", gameInfo2.name); // 구조체의 변수에 접근하기 위해 '.' 을 사용
    printf("발매년도 : %d\n", gameInfo2.year);
    printf("가격 : %d\n", gameInfo2.price);
    printf("제작사 : %s\n", gameInfo2.company);

    // 구조체 배열
    struct GameInfo gameArray[2] = {
        {"나도게임", 2017, 50, "나도회사"},
        {"너도게임", 2017, 100, "너도회사"}
    };

    // 구조체 포인터
    struct GameInfo * gamePtr; // 미션맨
    gamePtr = &gameInfo1;
    printf("-- 미션맨의 게임 출시 정보 --\n");
    /*
    printf("게임명 : %s\n", (*gamePtr).name); // 포인터가 가리키는 값의 정보에 접근하기 때문에 (*gamePtr) 이라 작성함
    printf("발매년도 : %d\n", (*gamePtr).year);
    printf("가격 : %d\n", (*gamePtr).price);
    printf("제작사 : %s\n", (*gamePtr).company);
    */
    // 조금 더 간단한 표현
    printf("게임명 : %s\n", gamePtr->name); // 구조체 포인터에 접근하기 위해 '->' 를 사용
    printf("발매년도 : %d\n", gamePtr->year);
    printf("가격 : %d\n", gamePtr->price);
    printf("제작사 : %s\n", gamePtr->company);

    return 0;
}