#include <stdio.h>

int transform(int n, int b)
{
    if(n != 0)
    {
        transform(n / b, b);
        if(n % b > 9 && b > 10) // 10진수 이상의 영어 진수로 나타낼 때
        {
            printf("%c", n % b - 10 + 'A');
        }
        else
        {
            printf("%d", n % b);
        }
    }        
}

int main()
{
    int n, b;
    scanf("%d %d", &n, &b);

    transform(n, b);

    return 0;
}