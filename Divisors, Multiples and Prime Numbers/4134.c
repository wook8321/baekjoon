#include <stdio.h>

int decimal(long long a)        // 합성수면 0을 반환, 소수면 1을 반환
{
    if(a < 2) return 0;         // 2보다 작으면 소수가 아님.

    if(a == 2 || a == 3) return 1;  // 2나 3은 소수.

    if(a % 2 == 0 || a % 3 == 0) return 0;        // 2나 3으로 나누어지면 소수가 아님.

    for(long long i = 5; i * i <= a; i += 6)   // 소수는 항상 6k+-1 꼴 (2, 3 제외)
    {
        if(a % i == 0 || a % (i + 2) == 0)     // => 5부터 시작해서 6씩 더하며 i와 i+2를 나눠본다.
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