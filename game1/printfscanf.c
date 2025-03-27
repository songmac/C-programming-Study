#include <stdio.h>
#include <windows.h>
#include <wchar.h>
#include <fcntl.h>
#include <io.h>

int main(void)
{
    // UTF-8 출력
    SetConsoleOutputCP(CP_UTF8);

    // UTF-16 입출력 모드로 설정
    _setmode(_fileno(stdout), _O_U8TEXT); // 출력은 UTF-8
    _setmode(_fileno(stdin), _O_U16TEXT); // 입력은 UTF-16

    /*
    // 정수형 변수에 대한 예제
    int age = 12;
    printf("%d\n", age);


    // 실수형 변수에 대한 예제
    float f = 46.5f;
    printf("%.2f\n", f);
    double d = 4.428;
    printf("%.2lf\n", d);

    // 상수에 대한 예제
    const int YEAR = 2000;
    printf("태어난 년도 : %d\n", YEAR);
    // YEAR = 2001;
        return 0;


    // printf (연산 가능)
    int add = 3 + 7;
    printf("3 + 7 = %d\n", add);
    printf("%d + %d = %d\n", 39, 79, 39+79);


    // scanf (키보드 입력을 받아서 저장)
    int input;
    printf("값을 입력하세요: ");
    scanf_s("%d", &input);
    printf("입력값 : %d\n", input);


    int one, two, three;
    printf("3개의 정수를 입력하세요: ");
    scanf_s("%d %d %d", &one, &two, &three);
    printf("첫번째 값 : %d\n", one);
    printf("두번째 값 : %d\n", two);
    printf("세번째 값 : %d\n", three);


    // 문자(한 글자), 문자열(한 글자 이상의 여러 글자)
    char c = 'A';
    printf("%c\n", c);

    // char str[256];
    // scanf_s("%s", str, sizeof(str));
    // printf("%s\n", str);  
    // char + scanf/printf는 한글 입력이 깨짐!

    wchar_t input[256]; // 유니코드 문자형(한글, 이모지 등) 같은 넓은 문자를 저장할 수 있는 자료형

    wprintf(L"문자열 입력: ");  // 유니코드 전용 출력 함수
    wscanf(L"%255s", input);    // L"..." 은 유니코드 문자열 상수를 의미  // 255는 최대 255글자까지 문자열을 읽겠다는 의미
    wprintf(L"입력한 문자열: %s\n", input);

    */

    // 프로젝트 : 경찰관이 범죄자의 정보를 입수 (조서 작성)
    // 이름? 나이? 몸무게? 키? 범죄명?

    wchar_t name[256];
    wprintf(L"이름이 뭐예요? ");
    wscanf(L"%255s", name);

    int age;
    wprintf(L"몇살이예요? ");
    wscanf(L"%d", &age);    // 정수, 실수 입력은 반드시 &변수명 으로 주소 전달 해야 함
    
    float weight;
    wprintf(L"몸무게는 몇 kg 이예요? ");
    wscanf(L"%f", &weight);

    double height;
    wprintf(L"키는 몇 cm 이예요? ");
    wscanf(L"%lf", &height);

    wchar_t what[256];
    wprintf(L"무슨 범죄를 저질렀어요? ");
    wscanf(L"%s", what);

    // 조서 내용 출력
    wprintf(L"\n\n--- 범죄자 정보 ---\n\n");
    wprintf(L"이름      : %s\n", name);
    wprintf(L"나이      : %d\n", age);
    wprintf(L"몸무게    : %f\n", weight);
    wprintf(L"키        : %.2lf\n", height);
    wprintf(L"범죄      : %s\n", what);

    return 0;
}