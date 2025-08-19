#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        int C;
        int Q, D, N, P;
        scanf("%d", &C);
        
        Q = C / 25;
        D = C % 25 / 10;
        N = C % 25 % 10 / 5;
        P = C % 25 % 10 % 5 / 1;

        printf("%d %d %d %d\n", Q, D, N, P);
    }
    
    return 0;
}