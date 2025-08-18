#include <stdio.h>

int decimal(long long a)        // 합성수면 0을 반환, 소수면 1을 반환
{
    if(a < 2) return 0;         // 2보다 작으면 소수가 아님.

    if(a == 2 || a == 3) return 1;  // 2나 3은 소수.

    if(a % 2 == 0) return 0;        // 2로 나누어지면 소수가 아님.

    for(long long i = 3; i * i <= a; i += 2)   // a의 제곱근보다 작은 홀수들만 확인
    {
        if(a % i == 0)      // a가 홀수로 나누어지면 합성수.
            return 0;
    }

    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        long long temp;
        scanf("%lld", &temp);
        
        while(!decimal(temp))   // 합성수면 temp에 1을 계속 더한다.
        {
            temp++;
        }

        printf("%lld\n", temp);
    }

    return 0;
}