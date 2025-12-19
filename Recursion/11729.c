#include <stdio.h>

void hanoi(int n, int from, int via, int to)
{
    if(n == 1)
    {
        printf("%d %d\n", from, to);
        return ;
    }

    // 1. n-1개 from에서 via로 이동 
    hanoi(n-1, from, to, via);

    // 2. 가장 큰 원판을 from에서 to로 이동
    hanoi(1, from, via, to);

    // 3. n-1개 via에서 to로 이동
    hanoi(n-1, via, from, to);
}

int main()
{
    int N;
    scanf("%d", &N);

    // 이동 횟수 (2^N -1)
    printf("%d\n", (1 << N) - 1); // 2의 N제곱 - 1


    // 수행 과정 (기둥 1,2,3)
    hanoi(N, 1, 2, 3);

    return 0;
}