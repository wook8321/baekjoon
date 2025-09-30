#include <stdio.h>

int factorial(int N)
{
    int result;

    if(N == 0)
        result = 1;
    else
    {
        result = N * factorial(N-1);
    }

    return result;
}

int main()
{
    int N;
    scanf("%d", &N);

    printf("%d\n", factorial(N));

    return 0;
}