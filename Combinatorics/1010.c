#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        int N, M;
        scanf("%d %d", &N, &M);

        int a = 1, b = 1;   // a는 분모, b는 분지
        for(int j = M; j >= M - N + 1; j--)
        {
            a *= j;
            b *= j - M + N;
        }

        printf("%d\n", a / b);
    }

    return 0;
}