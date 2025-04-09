# include <stdio.h>
// #include <windows.h>
// #include <stdlib.h>

// 선언
void p(int num);
void function_without_return();
int function_with_return();
void function_without_params();
void function_with_params(int num1, int num2, int num3);
int apple(int total, int ate); // 사과를 먹는 함수
int add(int num1, int num2); // 두 수를 더하는 함수
int sub(int num1, int num2); // 두 수를 빼는 함수
int mul(int num1, int num2); // 두 수를 곱하는 함수
int div(int num1, int num2); // 두 수를 나누는 함수
int mod(int num1, int num2); // 두 수를 나눈 나머지를 구하는 함수


int main(void) // void는 이 함수에 매개변수가 없음을 뜻함. 즉, 아무것도 반환하지 않겠다는 의미
{
    // SetConsoleOutputCP(CP_UTF8);

    // function
    // 계산기
    /*
    int num = 2;
    // printf("num 은 %d 입니다.\n", num);
    p(num);

    // 2 + 3은?
    num = num + 3;
    p(num);

    // 5 - 1 은?
    num -= 1;
    p(num);

  

// 함수 호출
    // 함수 종류 
    // 반환값이 없는 함수
    function_without_return();

    // 반환값이 있는 함수
    int ret = function_with_return();
    p(ret); 

    // 파라미터(전달값)가 없는 함수
    function_without_params();

    // 파라미터(전달값)가 있는 함수
    function_with_params(1, 2, 3);


    // 파라미터(전달값)도 받고, 반환값이 있는 함수
    // int ret = apple(5, 2); // 5개의 사과 중에서 2개를 먹었어요 라는 의미
    // printf("남은 사과의 개수는 %d 개 입니다.\n", ret); // 남은 사과의 개수를 출력
    printf("사과 %d 개 중에 %d 개를 먹으면, 남은 사과의 개수는 %d 개 입니다.\n", 10, 4, apple(10, 4)); // 사과 10개 중에 4개를 먹으면, 6개가 남아요
    */

    // 프로젝트 : 함수를 이용한 계산기
    int num1, num2; // 두 수를 입력받기 위한 변수 선언
    printf("두 수를 입력하세요 : ");
    scanf_s("%d %d", &num1, &num2); // 두 수를 입력받음
    printf("입력받은 num1, num2는 각각 %d, %d 입니다.\n", num1, num2); // 입력 받은 두 수를 출력
    printf("아래는 각각 두 수를 더하고, 빼고, 곱하고, 나누고(몫을 구하고), 나눈 나머지를 구한 결과입니다.\n");
    printf("--------------------------------------------------\n");
    add(num1, num2); // 두 수를 더하는 함수
    sub(num1, num2); // 두 수를 빼는 함수
    mul(num1, num2); // 두 수를 곱하는 함수
    div(num1, num2); // 두 수를 나누는 함수
    mod(num1, num2); // 두 수를 나눈 나머지를 구하는 함수

    return 0;
}


// 정의
void p(int num) // 위에서 선언한 함수와 동일하게 작성 필수!
{
    printf("num은 %d 입니다.\n", num);
}

void function_without_return()
{
    printf("반환값이 없는 함수입니다.\n");
}

int function_with_return()
{
    printf("반환값이 있는 함수입니다.\n");
    return 10; // 반환값이 있는 함수는 반드시 return문이 있어야 함
}

void function_without_params()
{
    printf("파라미터가 없는 함수입니다.\n");
}

void function_with_params(int num1, int num2, int num3)
{
    printf("파라미터가 있는 함수이며, 전달받은 값은 %d, %d, %d 입니다.\n", num1, num2, num3);
}

int apple(int total, int ate) 
{
    printf("파라미터와 반환값이 있는 함수입니다.\n");
    // printf("%d개의 사과 중에서 %d개를 먹었어요.\n", total, ate);
    return total - ate; // 남은 사과의 개수를 반환
}

int add(int num1, int num2)
{
    // printf("두 수를 더하는 함수입니다.\n");
    printf("%d + %d = %d\n", num1, num2, num1 + num2);
    return num1 + num2; // 두 수를 더하는 함수
}
int sub(int num1, int num2)
{
    // printf("두 수를 빼는 함수입니다.\n");
    printf("%d - %d = %d\n", num1, num2, num1 - num2);
    return num1 - num2; // 두 수를 빼는 함수
}   
int mul(int num1, int num2)
{
    // printf("두 수를 곱하는 함수입니다.\n");
    printf("%d * %d = %d\n", num1, num2, num1 * num2);
    return num1 * num2; // 두 수를 곱하는 함수  
}
int div(int num1, int num2)
{
    // printf("두 수를 나누는 함수입니다.\n");
    printf("%d / %d = %d\n", num1, num2, num1 / num2);
    return num1 / num2; // 두 수를 나누는 함수  
}
int mod(int num1, int num2)
{
    // printf("두 수를 나눈 나머지를 구하는 함수입니다.\n");
    printf("%d %% %d = %d\n", num1, num2, num1 % num2);
    return num1 % num2; // 두 수를 나눈 나머지를 구하는 함수   
}
