#include <stdio.h>
#define SIZE 4

void bubble_sort(int * list)
{
    int i, j, k, temp;
    for(i = 0; i < SIZE -1; i++)
    {
        for(j =0; j < (SIZE-1)-i; j++)
        {
            if(list[j] > list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }

    for(k = 0; k < SIZE; k++) // 변수의 유효 범위는 루프가 끝나면 새롭게 재사용해도 되기 때문에 k를 i로 바꿔도 됨.
    {
        printf("%d ", list[k]);
    }
}

void main(){
    int list[SIZE] = {7, 2, 4, 1};
    bubble_sort(list);
}