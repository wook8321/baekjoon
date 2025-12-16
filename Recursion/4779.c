#include <stdio.h>
#include <math.h>
#include <string.h>

char tmp[600000];

void cantor(int start, int length)
{
    if (length == 1)    // 길이가 1이면 종료
        return;
    
    int one_third = length / 3;
    
    // 가운데 부분 공백 처리
    for(int i = start + one_third; i < start + 2 * one_third; i++)
    {
        tmp[i] = ' ';
    }

    // 왼쪽 3분의 1 부분과 오른쪽 3분의 1 부분 재귀
    cantor(start, one_third);
    cantor(start + 2 * one_third, one_third);
}

int main()
{
    int N; 
    while(scanf("%d", &N) != EOF)
    {
        int len = pow(3, N);

        for(int k = 0; k < len; k++)
        {
            tmp[k] = '-';
        }

        cantor(0, len);
        
        for(int i = 0; i < len; i++)
        {
            printf("%c", tmp[i]);
        }
        printf("\n");
    }

    return 0;
}