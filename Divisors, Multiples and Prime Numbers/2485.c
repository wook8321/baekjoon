#include <stdio.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}   

int main()
{
    int N;
    scanf("%d", &N);
    int colon[N];

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &colon[i]);
    }

    int g = colon[1] - colon[0];
    int temp;
    for(int j = 1; j < N - 1; j++)
    {
        temp = colon[j+1] - colon[j];
        g = gcd(g, temp);
    }

    int min = ( (colon[N - 1] - colon[0]) / g ) - (N - 1);

    printf("%d", min);

    return 0;
}