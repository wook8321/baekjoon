#include <stdio.h>

/*
int main()
{
    int N;
    scanf("%d", &N);

    char* windows = (char*)calloc(N+1, sizeof(char));
    
    for(int i = 1; i <= N; i++)
    {
        windows[i] = 0;     // 처음엔 모든 창문 닫힘.
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = i; j <= N; j += i)
        {
            
            if(windows[j] == 0)
            {
                windows[j] = 1;
            }
            else
            {
                windows[j] = 0;
            }

            // => XOR과 같은 역할
            
            // windows[j] ^= 1;
        }
    }

    int count = 0;
    for(int i = 1; i <= N; i++)
    {
        if(windows[i] == 1)
            count++;
    }

    printf("%d\n", count);

    return 0;
}

=> 위 방법 사용 시 calloc으로 인한 메모리 초과.

*/

// 사실 완전제곱수(n * n) 번째의 창문만 열리게 된다.

int main()
{
    int count = 0;
    int N;
    scanf("%d", &N);

    for(int i = 1; i * i <= N; i++)
    {
        count++;
    }

    printf("%d", count);

    return 0;
}