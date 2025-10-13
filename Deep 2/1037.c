#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int min, max, temp;
    
    if(N == 1)
    {
        scanf("%d", &temp);
        printf("%d\n", temp * temp);
    }

    else
    {
        scanf("%d", &temp);
        
        min = max = temp;

        // 처음 초기화할 때가 중요! 계속 min과 max가 바뀌므로, 처음 수를 min과 max로 설정

        for(int i = 1; i < N; i++)
        {
            scanf("%d", &temp);
            if(temp > max) max = temp;
            if(temp < min) min = temp;
        }

        printf("%d\n", min * max);

    }

    return 0;
}