#include <stdio.h>

void determine(int a, int b)
{
    if(b % a == 0)
    {
        printf("factor\n");
    }
    else if(a % b == 0)
    {
        printf("multiple\n");
    }
    else
    {
        printf("neither\n");
    }
}

int main()
{
    while(1)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if(a == 0 && b == 0)
            break;

        determine(a, b);
    }

    return 0;
}