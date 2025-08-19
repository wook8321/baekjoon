#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long a = (long long)n * n; // O(n^2)의 수행 횟수 계산

    printf("%lld\n", a); // 수행 횟수
    printf("2\n");       // 최고차항 차수

    return 0;
}

/* 실제로 돌리면 시간 초과가 난다. */