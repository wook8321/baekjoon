#include <stdio.h>

// 퀵 정렬을 위한 비교 함수
int cmp(void* a, void* b)
{
    int pa = *(int*) a;        // *(int*)는 int 값을 의미함.
    int pb = *(int*) b;

    return pa - pb;
}

// 이진 탐색을 통해 퀵정렬된 배열 속에서 타겟이 처음 등장한 인덱스와 마지막으로 등장한 인덱스의 차를 구함.  시간 복잡도는 log N
int lower_bound(int* arr, int size, int target)
{
    int left = 0, right = size;
    
    while(left < right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int upper_bound(int* arr, int size, int target)
{
    int left = 0, right = size;
    
    while(left < right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    int* card = (int*)calloc(N, sizeof(int));

    for(int i = 0; i < N; i++)
        scanf("%d", &card[i]);

    qsort(card, N, sizeof(card[0]), cmp);

    int M;
    scanf("%d", &M);
    
    int val;
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &val);
        int lw = lower_bound(card, N, val);
        int up = upper_bound(card, N, val);
        printf("%d ", up - lw);
    }

    free(card);

    return 0;
}