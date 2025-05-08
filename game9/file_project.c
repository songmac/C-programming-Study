#include <stdio.h>
#include <string.h> // strcmp 사용하기 위해 필요

// 비밀번호를 입력 받아서
// 맞는 경우? 비밀 일기를 읽어와서 보여주고, 계속 작성하도록 합니다.
// 틀린 경우? 경고 메세지를 표시하고 종료합니다.

# define MAX 10000 // 상수 정의


int main(void)
{
    // ftets, fputs 활용
    char line[MAX]; // 파일에서 불러온 내용을 저장할 변수
    char contents[MAX]; // 일기장에 입력할 내용
    char password[20]; // 비밀번호를 저장할 배열
    char c; // 비밀번호 입력 할 때 키값 확인용(마스킹)

    printf("'비밀일기'에 오신 것을 환영합니다\n"); 
    printf("비밀번호를 입력하세요 : ");

    // getchar() / getch() 의 차이?
    // gethchar() : 엔터를 입력받아야 동작함
    // getch() : 키 입력 시 바로바로 동작함

    while (1)
    {
        c = getch(); 
        int i = 0;
        if (c == 13) // c = 13 은 Enter 키를 의미함 // Enter -> 비밀번호 입력 종료  
        {
            password[i] = '\0'; // 비밀번호 끝에 NULL 문자 추가
            break;
        }
        else // 비밀번호 입력 중
        {
            printf("*");
            password[i] = c; 
        }
    i++;
    }


    // 비밀번호 : sodlfrlwkd (내일기장 영어로)
    printf("\n\n === 비밀번호 확인 중... +++\n\n");

     // 비밀번호가 일치한 경우
    if (strcmp(password, "sodlfrlwkd") == 0) // strcmp : 문자열 비교 함수
    {
        printf(" === 비밀번호 확인 완료 ===\n\n");
        char * fileName = "C:/Users/selena/songmac/C-programming-Study/game9/secretdiary.txt"; // 파일 경로 설정
        FILE * file = fopen(fileName, "a+b"); // 파일 열기 (a+b : append + binary 모드로 열기) 
                                              // 파일이 없으면 생성, 파일이 있으면 append 를 한다 (뒤에서부터 내용을 추가한다)
        if (file == NULL) // 파일 열기 실패 시
        {
            printf("파일 열기 실패 \n");
            return 1; 
        }        
        while (fgets(line, MAX, file) != NULL)
        {
            printf("%s", line); // 파일에 저장된 내용 출력
        }
        printf("\n\n 내용을 계속 작성하세요! 종료하시려면 EXIT를 입력하세요\n\n");
        while (1)
        {
            // 모든 내용은 Enter 없이 작성된다고 가정??
            scanf("%[^\n]", contents); // 새 줄(\n)이 나오기 전까지 읽어들임 (한 문장씩 읽어 들임)
            getchar(); // Enter 입력(\n)을 Flush 처리 (버퍼에 남아있던 개행문자 비우기)

            if (strcmp(contents, "EXIT") == 0) // EXIT 입력 시 종료
            {
                printf("비밀일기 입력을 종료합니다\n\n");
                break;
            }
            fputs(contents, file); // 파일에 내용 저장
            fputs("\n", file); // Enter 를 위에서 무시 처리 하였으므로 임의로 줄바꿈 추가
        }
        fclose(file); // 파일 닫기 및 저장
    }

     // 비밀번호 틀린 경우
    else
    {
        printf("=== 비밀번호가 틀렸어요 ===\n\n");
        printf("꺅!! 당신 누구야?!! 감히 내 일기장을 !!! \n\n");
    }

    return 0;
}