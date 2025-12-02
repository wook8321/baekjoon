#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    if(N == 1 || N == 0)
        printf("1\n");
    else
    {
        long long int res = 1;
        for(int i = 2; i <= N; i++)
        {
            res *= i;
        }

        printf("%lld\n", res);
    }

    return 0;
}