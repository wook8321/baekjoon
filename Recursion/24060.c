#include <stdio.h>
#include <stdlib.h>

int A[500001];
int tmp[500001];
int count = 0;
int K, result;

void merge_sort(int A[], int p, int r) { 
    // A[p..r]을 오름차순 정렬한다.
    if (p < r)
    {
        int q = (p + r) / 2;        // q는 p, r의 중간 지점
        merge_sort(A, p, q);        // 전반부 정렬
        merge_sort(A, q + 1, r);    // 후반부 정렬
        merge(A, p, q, r);          // 병합
    }
}

// A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.

void merge(int A[], int p, int q, int r) {
    int i = p; 
    int j = q + 1;
    int t = 0;
    while (i <= q && j <= r) {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }
    while (i <= q)  // 왼쪽 배열 부분이 남은 경우
        tmp[t++] = A[i++];
    while (j <= r)  // 오른쪽 배열 부분이 남은 경우
        tmp[t++] = A[j++];
    i = p, t = 0;
    while (i <= r)  // 결과를 A[p..r]에 저장
    {
        count++;
        if(count == K)
            result = tmp[t];
        A[i++] = tmp[t++];
    }    
}

int main()
{
    int N;
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    merge_sort(A, 0, N-1);

    if(count < K) result = -1;  // 저장 횟수가 K보다 작은 경우 -1 출력

    printf("%d\n", result);

    return 0;
}