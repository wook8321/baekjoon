#include <stdio.h>

char count[20000001] = {0}; 
/* 
    0 또는 1만 사용하기 때문에 1바이트를 사용하는 char배열을 사용하는 것이 int형 배열보다 메모리 사용량이 적다.
    수의 범위가 -10,000,000 ~ 10,000,000 이기 때문에 배열을 20,000,000개로 설정하고 0으로 초기화한다.
    함수 안의 선언값은 스택 메모리에 할당되는데, 20,000,000 크기의 배열은 스택을 초과한다. 
    => 전역 변수는 데이터 세그먼트(.bss)에 저장된다. or static 키워드를 쓰면 전역처럼 동작한다.
*/

int main()
{
    int N;
    scanf("%d", &N);
    
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