#include <stdio.h>
#include <stdlib.h> // srand, rand 사용하기 위해 필요
#include <time.h> // time 사용하기 위해 필요

# define MAX 10000 // 상수 정의

int main(void)
{
    // 파일 입출력
    // 파일에 어떤 데이터를 저장 
    // 사용하는 이유? 프로그램을 껐다 키면 메모리에 저장된 데이터는 휘발성이기 때문에 날아가지만, 파일로 저장하면 데이터가 남아있게 되므로, 데이터 저장시 유용
    // 파일에 저장된 데이터를 불러오기


    // fputs, fgets 쌍 : 문자열 저장 및 불러오기에 사용
    // 파일에 쓰기

/*
    char line[MAX];
    FILE * file = fopen("C:/Users/selena/songmac/C-programming-Study/game9/test1.txt", "wb"); // Visual Studio 에서는 역슬래시 두개(\\)로 경로 설정해줘야 함
        // fopen : 파일을 여는 함수, 첫번째 인자 : 파일 경로, 두번째 인자 : 모드
        // w : write, r : read, a : append // w 뒤에 붙을 수 있는 것 2가지 : t(text), b(binary) 
    if (file == NULL) // 파일 열기 실패 시
    {
        printf("파일을 열 수 없습니다.\n");
        return 1; // 에러 코드 반환
    }
    fputs("fputs 를 이용해서 글을 적어볼게요 \n", file); // fputs : 파일에 문자열을 쓰는 함수, 첫번째 인자 : 문자열, 두번째 인자 : 파일 포인터 
    fputs("잘 적히는지 확인해주세요\n", file);
    fclose(file); // 파일 닫기 및 저장 
                  // 항상 닫는 습관을 들여야 함. 그 이유는?
                  // - 파일 닫지 않은 상태에서 프로그램 종료 시, 파일 손상 가능
                  // - 파일 닫지 않은 상태에서 프로그램에 문제가 생기면 데이터 손실 발생 가능
    // 파일 읽기
    // 파일 쓰기코드를 주석 처리하고, 파일 읽기 코드 작성
    FILE * file = fopen("C:/Users/selena/songmac/C-programming-Study/game9/test1.txt", "rb"); // 읽기 모드로 파일 열기 (다른 변수로 열어야 함)
    if (file == NULL)
    {
        printf("파일 열기 실패\n");
        return 1; // 에러 코드 반환
    }
    else
    {
        while(fgets(line, MAX, file) != NULL)
        {
            printf("%s", line);
        }
    }

    // 파일 쓰기코드를 주석 처리하지 않고, 파일 읽기 코드 작성 (FILE 변수를 다르게 설정 후 읽어야 오류 없이 읽어짐)
    FILE * file2 = fopen("C:/Users/selena/songmac/C-programming-Study/game9/test1.txt", "rb"); 
    if (file2 == NULL)
    {
        printf("파일 열기 실패\n");
        return 1; // 에러 코드 반환
    }
    else
    {
        while(fgets(line, MAX, file2) != NULL)
        {
            printf("%s", line);
        }
    }
*/


    // fprintf, fscanf 쌍 : 기존에 사용했던 (printf, scanf 처럼) 포맷을 지정해서 저장 및 불러오기
    // 로또 추첨 결과 파일에 쓰기
    int num[7] = {0, 0, 0, 0, 0, 0, 0}; // 추첨번호 6개 + 보너스번호 1개 : 총 7개   
    char str1[MAX]; // 추첨번호 (총 12바이트 : 한글 1글자당 3바이트)
    char str2[MAX]; // 보너스번호 (총 15바이트 : 한글 1글자당 3바이트)

    srand(time(NULL));

    FILE * file3 = fopen("C:/Users/selena/songmac/C-programming-Study/game9/test2.txt", "wb"); // 파일 열기
    if (file3 == NULL)
    {
        printf("파일 열기 실패\n");
        return 1; // 에러 코드 반환 
    }
    else
    {
        // 로또 추첨 번호 저장
        for (int i = 0; i < 7; i++)
        {
            num[i] = rand() % 45 + 1; // 1~45 사이의 랜덤한 숫자 생성
            for (int j = 0; j < i; j++)
            {
                if (num[i] == num[j]) // 중복된 번호가 있으면 다시 생성
                {
                    i--;
                    // break;
                }
            }
        }
        fprintf(file3, "%s %d %d %d %d %d %d\n", "추첨번호", num[0], num[1], num[2], num[3], num[4], num[5]);
        fprintf(file3, "%s %d\n", "보너스번호", num[6]);
    }
    fclose(file3); // 파일 닫기 및 저장

    // 로또 추첨 번호가 저장된 파일 읽기
    FILE * file4 = fopen("C:/Users/selena/songmac/C-programming-Study/game9/test2.txt", "rb"); // 파일 읽기
    if (file4 == NULL)
    {
        printf("파일 열기 실패\n");
        return 1; // 에러 코드 반환
    }
    else
    {
        fscanf(file4, "%s %d %d %d %d %d %d\n", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]); 
        fscanf(file4, "%s %d\n", str2, &num[6]); 
        printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);
        printf("%s %d\n", str2, num[6]);
    }
    fclose(file4); // 파일 닫기 및 저장

    return 0;
}