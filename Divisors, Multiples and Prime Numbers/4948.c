#include <stdio.h>

int prime(int n)
{
    if(n < 2) return 0;

    if(n == 2 || n == 3) return 1;

    if(n % 2 == 0 || n % 3 == 0) return 0;

    for(int i = 5; i * i <= n; i += 6)
    {
        if(n % i == 0 || n % (i+2) == 0)
            return 0;
    }

    return 1;
}

int main()
{ 
    while(1)
    {
        int count = 0;
        int n;
        scanf("%d", &n);
        
        if(n == 0) break;

        for(int i = n + 1; i <= 2 * n; i++)
        {
            if(prime(i))
                count++;
        }
        printf("%d\n", count);
    }

    return 0;
}