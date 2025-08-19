#include <stdio.h>
#include <string.h>
#define MAX 246912

int main()
{
    int prime[MAX + 1];                 // 문제의 최대값 * 2 + 1
    memset(prime, 1, sizeof(prime));    // 전부 소수로 가정
    prime[0] = prime[1] = 0;            // 0, 1은 소수 아님
    
    // 에라토스테네스의 체
    for(int i = 2; i * i <= MAX; i++)
    {
        if(prime[i])
        {
            for(int j = i * i; j <= MAX; j += i)
                prime[j] = 0;
        }
    }
    
    while(1)
    {
        int count = 0;
        int n;
        scanf("%d", &n);
        
        if(n == 0) break;

        for(int i = n + 1; i <= 2 * n; i++)
        {
            if(prime[i])
                count++;
        }
        printf("%d\n", count);
    }

    return 0;
}