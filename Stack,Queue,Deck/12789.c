#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int number[1000];   // 입력받는 학생들의 번호표
    int stack[1000];    // 한 명씩 설 수 있는 공간

    int top = -1;

    int target = 1;     // 간식 받을 학생
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &number[i]);

        if(number[i] == target)
        {
            target++;

            // 한 명이 간식을 받고 한 명씩 설 수 있는 공간에 다음 간식 받을 학생이 있을 경우
            while(top >= 0 && stack[top] == target)
            {
                top--;
                target++;
            }
        }

        else
        {
            stack[++top] = number[i];
        }
    }

    // 현재 줄에는 아무도 없고, 한 명씩만 서 있는 공간에 학생이 남은 경우
    while(top >= 0 && stack[top] == target)
    {
        target++;
        top--;
    }

    if(top == -1) 
        printf("Nice\n");
    else
        printf("Sad\n");

    return 0;
}