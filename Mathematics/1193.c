#include <stdio.h>

int main()
{
    int X;
    scanf("%d", &X);
    
    int temp = 1;
    
    while(1)
    {
        if(X - temp <= 0)
            break;

        X -= temp;
        temp += 1;
    }

    if(temp % 2 == 0)
    {
        printf("%d/%d", X, temp - X + 1);
    }
    else
    {
        printf("%d/%d", temp - X + 1, X);
    }

    return 0;
}