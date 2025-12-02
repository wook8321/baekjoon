#include <stdio.h>

int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(n >= 2)
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;
    scanf("%d", &n);

    int res = fibonacci(n);

    printf("%d\n", res);

    return 0;
}