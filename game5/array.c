#include <stdio.h>

int main(void)
{
    /*
    // 여러 개의 변수를 함께, 동시에 생성
    int subway_array[3]; // [0] [1] [2] : 3개의 정수형 배열 선언
    subway_array[0] = 10; // 1호선 지하철 1호차에 10명이 타고 있다
    subway_array[1] = 20;
    subway_array[2] = 30;

    for (int i = 0; i < 3; i++)
    {
        printf("%d호선 지하철 %d호차에 %d명이 타고 있습니다.\n", i, i + 1, subway_array[i]);
    }
    printf("\n");

    // 값 초기화
    int subway_array2[3] = { 30, 40, 50 }; // [0] [1] [2] 3개의 정수형 배열 선언 및 초기화
    for (int j = 0; j < 3; j++)
    {
        printf("%d호선 지하철 %d호차에 %d명이 타고 있습니다.\n", j , j + 1, subway_array2[j]);
    }
    printf("\n");

    // 값 초기화 하지 않은 경우 쓰레기 값이 나오니, 꼭 초기화 해야 함
    int arr[10];
    for (int k = 0; k < 10; k++)
    {
        printf("%d ", arr[k]);
    }


    // 배열 크기 선언 (c표준)
    // int size = 10;
    // int arr[size]; // 오류 발생! 배열 크기는 상수로 선언해야 함

    // 배열 크기는 상수로 선언해야 함
    int arr[10] = {1, 2};  // 3번째 값부터는 자동으로 '0'으로 초기화 됨
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]); // 1, 2, 0, 0, 0, 0, 0, 0, 0, 0
    }

    // int arr[] = {1, 2}; // arr[2] = {1, 2}; 와 동일함
    float arr_f[5] = {1.0f, 2.0f, 3.0f}; // 4번째 값부터는 자동으로 '0.0'으로 초기화 됨
    for (int i = 0; i < 5; i++)
    {
        printf("%.2f\n", arr_f[i]); // 1.0, 2.0, 3.0, 0.0, 0.0
    }
    printf("\n");

    // 문자 vs 문자열
    // 문자형 변수
    char c = 'A';
    printf("%c\n", c);

    // 문자열형 변수
    // 문자열 끝에는 항상 자동으로 문자열의 끝을 나타내는 값인 NULL 문자(\0) 포함됨
    // char str[6] = "coding"; // 오류 또는 이상 출력 발생!
    // 배열 크기보다 더 큰 문자열을 넣으려고 했기 때문에 배열 밖 메모리에 저장되려고 시도하다가
    // 출력이 끝나지 않고 메모리 어딘가의 쓰레기 값까지 출력됨
    char str[7] = "coding";
    // printf("%s\n", str);
    // printf("%d\n", sizeof(str));

    for (int i = 0; i < sizeof(str); i++)
    {
        printf("%c\n", str[i]); // c o d i n g \0
    }

    char kor[] = "나도코딩";
    printf("%s\n", kor); // 나도코딩
    printf("%d\n", sizeof(kor)); // 12 (문자열의 길이 + NULL 문자 포함)
    // 영어 1글자 : 1 byte
    // 한글 1글자 : 2 byte (UTF-8 인코딩 기준)
    // 한글 1글자 : 3 byte (UTF-16 인코딩 기준) 
    // char 크기 : 1 byte

    char c_array[10] = { 'c', 'o', 'd', 'i', 'n', 'g' };
    // printf("%s\n", c_array); 
    // for (int i = 0; i < sizeof(c_array); i++)
    // {
    //     printf("%c\n", c_array[i]); // c o d i n g \0 \0 \0 \0 \0 \0
    // }

    for(int i = 0; i < sizeof(c_array); i++ )
    {
        printf("%d\n", c_array[i]); // 99 111 100 105 110 103 0 0 0 0, ASCII 코드값 출력 (null 문자 0으로 입력됨)
    }


    // ASCII 코드란?
    // 0 ~ 127까지의 숫자에 문자, 기호, 숫자 등을 매핑한 것 (표준화된 문자 집합)
    // 7비트로 표현 가능 (2^7 = 128)  
    printf("%c\n", 'a');
    printf("%d\n", 'a'); // 97 (ASCII 코드값)
    printf("%c\n", 97); // a (ASCII 코드값을 문자로 변환)   

    printf("%c\n", 'A'); 
    printf("%d\n", 'A'); // 65 (ASCII 코드값)
    printf("%c\n", 65); // A (ASCII 코드값을 문자로 변환)

    printf("%c\n", '\0'); // NULL 문자
    printf("%d\n", '\0'); // 0 (ASCII 코드값)
    printf("%c\n", 0); // NULL 문자 (ASCII 코드값 0)
    */

    // 참고2 : 0~127 사이의 아스키코드 정수값에 해당하는 문자 확인
    for (int i = 0; i < 128; i++)
    {
        printf("아스키코드 %d : %c\n", i, i); // 0~127까지의 아스키코드 정수값에 해당하는 문자 확인
    }     


    return 0;
}