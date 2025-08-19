#include <stdio.h>

int main()
{
    int low = 1, high = 1;
    int num = 1;

    int N;
    scanf("%d", &N);

    while(1)
    {
        if(N - high <= 0)
            break;
        
        low += 1 + 6 * (num - 1);
        high += 6 * num;
        num += 1; 
    }
    printf("%d", num);

    return 0;
}


/*  내 생각
#include <stdio.h>

int sum(int i)
{
    return i * (i-1);
}

int main()
{
    int N;
    scanf("%d", &N);

    int result, temp;
    temp = (N - 1) / 3;

    for(int k = 1;;k++)
    {
        if(sum(k-1) <= temp && temp <= sum(k))
        {
            result = k;
        }
    }

    if(N = 1) result = 1;

    printf("%d", result);
    return 0;
}
*/