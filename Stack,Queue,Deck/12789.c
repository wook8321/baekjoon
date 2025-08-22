#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int number[1000];    // 입력받는 학생들의 번호표
    int stack[1000];     // 한 명씩 설 수 있는 공간

    int top = -1;

    int target = 1;   // 
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &number[i]);

        if(number[i] == target)
        {
            target++;

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