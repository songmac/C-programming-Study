// 스택 연산 프로그램
// LIFO(Last In First Out) 구조를 직접 구현

#include <stdio.h>
#include <stdlib.h>  // exit 사용시 이 헤더도 필요함

# define max_stack_size 10  // 스택의 최대 용량을 넉넉하게 설정 (오버플로우 방지)

int top = -1;  // 스택에서 가장 최근에 들어간 값의 위치 (-1은 비어있음을 나타내는 초기값)
int stack[max_stack_size];  // 크기 10짜리 정수형 배열 스택


// 함수 프로토타입 : 아래쪽에 이런 함수가 나올 것이라고 미리 알려줌
    // 리턴값의타입 함수명(인자또는매개변수의타입), void는 없음을 나타냄
void stackFull(void);  
void stackEmpty(void);
void push(int);
int pop(void);

int main(){
    push(8);
    push(1);
    push(0);
    push(2);

    printf("%2d", pop()); // 최소 너비를 2칸으로 맞춤
    printf("%2d", pop());
    printf("%2d", pop());
    printf("%2d", pop());
    return 0;
}

void stackFull()
{
    printf("\nStack is full, cannot add element.\n");
    exit(0); // 정상 종료
    exit(1); // 비정상 종료 (프로그램을 여기서 바로 종료)

}
void stackEmpty()
{  
    printf("\nStack is empty, cannot delete element.\n");
    exit(1); 
}

void push(int item)
{
    if (top >= max_stack_size - 1) // 또는 9
        stackFull();
    else
        stack[++top] = item;  // 값을 스택에 넣기만 하고 결과를 돌려줄 필요가 없기에 return 값이 없음
}

int pop()
{
    if (top <= -1)
        stackEmpty();
    else
        return stack[top--];

}