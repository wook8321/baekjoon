#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int count[20000001] = {0};

    int num;

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        count[num + 10000000] = 1;
    }

    int M;
    scanf("%d", &M);

    for(int i = 0; i < M; i++)
    {
        scanf("%d", &num);
        printf("%d ", count[num + 10000000]);
    }

    return 0;
}