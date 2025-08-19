#include <stdio.h>
#include <stdlib.h>

int cmp(void* a, void* b)
{
   // (int*) => int형 주소
   // *(int*) => int 값
    int x = *(int*) a;
    int y = *(int*) b;
    return (x > y) - (x < y);

    // x가 y보다 클 때,    x > y = 1, x < y = 0
    // x가 y와 같을 때,    x > y = 0, x < y = 0
    // x가 y보다 작을 때,  x > y = 0, x < y = 1
}

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    int *pa = (int*)malloc(A * sizeof(int));
    
    for(int i = 0; i < A; i++)
    {
        scanf("%d", &pa[i]);
    }
    qsort(pa, A, sizeof(int), cmp);
    
    int *pb = (int*)malloc(B * sizeof(int));

    for(int i = 0; i < B; i++)
    {
        scanf("%d", &pb[i]);
    }
    qsort(pb, B, sizeof(int), cmp);
    
    int count = 0;
    int i = 0, j = 0;

    while(i < A && j < B)
    {
        if(pa[i] < pb[j])
        {
            count++;
            i++;
        }
        else if(pa[i] > pb[j])
        {
            count++;
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    count += (A - i) + (B - j); 
    // 남은 원소들 (개수가 적은 집합의 마지막 원소가 개수가 많은 집합에 속하면 count를 끝까지 세지 못하고 남는 원소가 생김.) 

    printf("%d", count);
    free(pa);
    free(pb);

    return 0;   
}