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

    // 구조체 안의 구조체 : 구조체 안에서 똑같은 내용의 구조체를 가질 수 있음
    struct GameInfo *friendGame; // friendGame의 타입은 다른 GameInfo를 가리키는 포인터임
                                 // 따라서, friendGame에 값을 넣으려면 진짜로 존재하는 GameInfo 구조체의 주소를 넣어야 함
};


// 구조체의 typedef
typedef struct GameInformation
// typedef struct // 이렇게 typedef의 이름을 지정해주지 않아도 사용 가능
{
    char *name; // 포인터변수 사용 이유? 문자열 리터럴의 주소를 저장 (읽기전용)
                // char name[100] 처럼 배열로 선언하면  직접 문자열 데이터를 저장하기 때문에 메모리 효율이 떨어짐 (문자열을 복사해서 사용, 값 수정 가능)
    int year;
    int price;
    char *company;

    struct GameInfo *friendGame; 
} GAME_INFO; // typedef를 사용하여 GameInformation 라는 구조체를 GAME_INFO로 치환하겠다는 뜻 


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

    struct GameInfo gameInfo2;
    gameInfo2.name = "너도게임";
    gameInfo2.year = 2017;
    gameInfo2.price = 100;
    gameInfo2.company = "너도회사";
    // 구조체 출력
    printf("\n\n-- 또 다른 게임 출시 정보 --\n");
    printf("게임명 : %s\n", gameInfo2.name);
    printf("발매년도 : %d\n", gameInfo2.year);
    printf("가격 : %d\n", gameInfo2.price);
    printf("제작사 : %s\n", gameInfo2.company);

    /*
    // 구조체를 배열처럼 초기화
    struct GameInfo gameInfo2 = {"너도게임", 2017, 100, "너도회사"};
    printf("-- 또다른 게임 출시 정보 --\n");
    printf("게임명 : %s\n", gameInfo2.name); // 구조체의 변수에 접근하기 위해 '.' 을 사용
    printf("발매년도 : %d\n", gameInfo2.year);
    printf("가격 : %d\n", gameInfo2.price);
    printf("제작사 : %s\n", gameInfo2.company);
    */

    // 구조체 배열
    struct GameInfo gameArray[2] = {
        {"나도게임", 2017, 50, "나도회사"},
        {"너도게임", 2017, 100, "너도회사"}};

    printf("\n\n-- 구조체 배열로 출력한 게임 출시 정보 --\n");
    printf("게임명 : %s\n", gameArray[0].name);
    printf("발매년도 : %d\n", gameArray[0].year);
    printf("가격 : %d\n", gameArray[0].price);
    printf("제작사 : %s\n", gameArray[0].company);
    printf("게임명 : %s\n", gameArray[1].name);
    printf("발매년도 : %d\n", gameArray[1].year);
    printf("가격 : %d\n", gameArray[1].price);
    printf("제작사 : %s\n", gameArray[1].company);


    // 구조체 포인터
    struct GameInfo *gamePtr; // 미션맨
    gamePtr = &gameInfo1;
    printf("\n\n-- 미션맨의 게임 출시 정보 --\n");
    /*
    // 기본 표현
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


    // 구조체 안의 구조체
    // 연관 업체 게임 소개
    gameInfo1.friendGame = &gameInfo2; // gameInfo1의 friendGame이 gameInfo2를 가리킴
                                       // gameInfo1.friendGame에는 기존에 선언한 변수의 주소를 넣어줘야 제대로 작동함
    printf("\n\n-- 연관 업체의 게임 출시 정보 --\n");
    printf("게임명 : %s\n", gameInfo1.friendGame->name);
    printf("발매년도 : %d\n", gameInfo1.friendGame->year);
    printf("가격 : %d\n", gameInfo1.friendGame->price);
    printf("제작사 : %s\n", gameInfo1.friendGame->company);


    // typedef : 자료형에 별명 지정
    int i = 1;
    typedef int 정수;
    typedef float 실수;
    정수 정수변수 = 3;    // int i = 3;
    실수 실수변수 = 3.23f; // float f = 3.23f; // 3.23 으로 입력 시, double 타입으로 값이 들어감
    printf("\n정수변수 : %d, 실수변수 : %.2f\n\n", 정수변수, 실수변수);

    
    typedef struct GameInfo 게임정보;
    게임정보 game1;
    game1.name = "한글 게임";
    game1.year = 2015;
    printf("게임명 : %s\n",game1.name);
    printf("발매년도 : %d\n", game1.year);

    GAME_INFO game2;
    game2.name = "한글 게임2";
    game2.year = 2014;
    printf("게임명 : %s\n",game2.name);
    printf("발매년도 : %d\n", game2.year);

    struct GameInformation game3;
    game3.name = "한글 게임3";
    game3.year = 2013;
    printf("게임명 : %s\n",game3.name);
    printf("발매년도 : %d\n", game3.year);

    return 0;
}

// 참고 : c에서 변수명을 한글로 작성할 수 있는 이유는 컴파일러가 유니코드 또는 멀티바이트 문자를 변수로 허용하기 때문