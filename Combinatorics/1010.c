#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        int N, M;
        scanf("%d %d", &N, &M);

        /*
        long long int a = 1, b = 1;  a는 분모, b는 분자
        
        for(int j = N; j > 0; j--)
        {
            a *= j - N + M;
            b *= j;
        }

        이렇게 분자와 분모를 각각 계속 곱해가면 overflow 발생
        => 분모에 분자를 바로바로 나누어준다.
        */
        long long res = 1;

        for(int j = 0; j < N; j++)
        {
            res = res * (M - j) / (j + 1);
        }

        printf("%lld\n", res);
    }

    return 0;
}