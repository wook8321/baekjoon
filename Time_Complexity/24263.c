#include <stdio.h>

int a = 0; // 시행 횟수

int MenOfPassion(int A[], int n) {
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = sum + A[i]; // 코드1
        a++;
    }
    
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);        // 입력 

    int A[500000] = { 0 };  // (최대 크기 500000) 배열 선언

    MenOfPassion(A, n);     // 함수 실행

    printf("%d\n", a);      // 시행 횟수 출력
    printf("1\n");          // 최고차항 출력

    return 0;
}