#include <stdio.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = b;
        b = a % b;
        a = r;
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
        scanf("%d", &colon[i]);     // 가로수 위치 입력받기
    }

    int diff[N-1];
 
    for(int j = 0; j < N - 1; j++)
    {
        diff[j] = colon[j+1] - colon[j];    // 가로수 간격 설정
    }

    int g = diff[0];
    for(int k = 1; k < N - 1; k++)
    {
        g = gcd(g, diff[k]);        // gcd 비교를 통해 g에 가로수 간격들의 최대공약수 설정
    }

    int min = 0;                            // 초기화!! 꼭! (안해서 계속 틀림)
    for(int m = 0; m < N - 1; m++)
    {
        min += (diff[m] / g - 1);       // 최소수는 간격들을 최대공약수로 나눈 값에 -1 한 값들을 모조리 더한 것이다.     
    }

    printf("%d", min);

    return 0;
}