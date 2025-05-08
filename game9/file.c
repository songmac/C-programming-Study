#include <stdio.h>

# define MAX 10000 // 상수 정의

int main(void)
{
    // 파일 입출력
    // 파일에 어떤 데이터를 저장 
    // 사용하는 이유? 프로그램을 껐다 키면 메모리에 저장된 데이터는 휘발성이기 때문에 날아가지만, 파일로 저장하면 데이터가 남아있게 되므로, 데이터 저장시 유용
    // 파일에 저장된 데이터를 불러오기


    // fputs, fgets 쌍
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


    // fprintf, fscanf 쌍

    return 0;
}