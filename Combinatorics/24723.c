#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    scanf("%d", &N);

    printf("%d\n", (int)pow(2.0, N)); // pow 함수의 반환형은 double

    return 0;
}