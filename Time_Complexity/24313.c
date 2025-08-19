#include <stdio.h>

int main()
{
    int a, b, c, n;     // f(n)을 나타내는 정수 a1, a0, 양의 정수 c, n0 입력받음.
    scanf("%d %d %d %d", &a, &b, &c, &n);

    if(a > c)          // 양의 정수 c가 f(n)의 a1보다 작으면 n이 음수가 돼야 하므로 만족하지 않는다.
        printf("0");

    else if(a < c)               // c가 a1보다 큰 경우에는 n이 n0일 때 a1n + a0 <= cn을 만족해야야한다.
    {
        
        float content = b / (c - a);
        
        if (content <= n)
            printf("1");
        else
            printf("0");
    }

    else                        // c랑 a1이 같은 경우에는 b가 0이하일 때만 만족한다.
    {
        if(b <= 0)
            printf("1");
        else
            printf("0");
    }

    return 0;
}