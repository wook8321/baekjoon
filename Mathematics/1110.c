#include <stdio.h>

int main()
{
    int n;              // 입력받을 수 n
    scanf("%d", &n);

    int plus = n / 10 + n % 10;  // 각 자릿수들의 합
    int temp = 0;       // 계속 바뀌는 새로운 수
    int cycle = 0;      // 사이클 수 

    int first = n;      // 처음 한 번 n의 값을 담을 수

    do                  // 한 번 실행 후 while 조건 확인
    {
        temp = ((first + temp) % 10) * 10 + plus % 10;

        first = 0;
        plus = temp / 10 + temp % 10;
        cycle++;
    } while(n != temp);    // n이 0이 아닐 때

    printf("%d", cycle);

    return 0;
}