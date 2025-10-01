#include <stdio.h>

int factorial(int N)
{
    int result = 1;
    for(int i = 1; i <= N; i++)
    {
        result *= i;
    }

    return result;
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    /*
    int temp = 1;
    for(int i = N; i >= N-K+1; i--)
    {
        temp *= i;
    }

    for(int i = K; i > 1; i--)
    {
        temp /= i; 
    }

    이런 식으로도 직접 계산도 가능
    */

    int answer = factorial(N) / (factorial(K) * factorial(N-K));

    printf("%d\n", answer);

    return 0;
}