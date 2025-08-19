#include <stdio.h>
#include <string.h>
#define MAX 1000000 // 문제에서 N의 최대값
#define TRUE 1      // 소수면 true
#define FALSE 0     // 소수가 아니면 false

int main()
{
    int T;
    scanf("%d", &T);

    int prime[MAX+1];   // 소수 판별 배열
    memset(prime, TRUE, sizeof(prime)); // 처음엔 전부 소수로 취급

    prime[0] = prime[1] = FALSE;        // 0과 1은 소수가 아님.

    // 에라토스테네스의 체
    for(int i = 2; i * i <= MAX; i++)
    {
        if(prime[i])    // i가 소수면 i의 배수인 j를 false로 
        {
            for(int j = i * i; j <= MAX; j += i)
                prime[j] = FALSE;
        }
    }
    
    while(T--)
    {
        int N;
        scanf("%d", &N);    // 짝수 N 입력
        int count = 0;      // 파티션 개수

        // 짝수 N의 절반 값까지만 계산
        for(int i = 2; i <= N / 2; i++)
        {
            // 숫자 i와 숫자 N - i가 모두 소수면 count + 1
            if(prime[i] && prime[N - i])    // i + (N - i) = N
                count++;
        }

        printf("%d\n", count);
    }

    return 0;
}