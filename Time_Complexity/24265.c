/* 

#include <stdio.h>

int a = 0; // 시행 횟수

int MenOfPassion(int A[], int n) {
    int sum = 0;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            sum = sum + A[i] * A[j]; // 코드1
            a++;
        }
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
    printf("2\n");          // 최고차항 출력

    return 0;
}
*/ 


/* 실제로 돌리면 시간 초과가 난다. */



#include <stdio.h>

int main()
{   
    int n;
    scanf("%d", &n);

    long long a = (long long) n * (n - 1) / 2; // O(n^2)의 수행 횟수 계산

    printf("%lld\n", a); // 수행 횟수
    printf("2\n");       // 최고차항 차수

    return 0;
}

