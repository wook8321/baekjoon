#include <stdio.h>
#include <stdlib.h>

int flag = 0;

typedef struct {
    int value;
    int location;
    int compress;
} Coord;

int compare(void* a, void* b)
{
    Coord A = *(Coord*) a;
    Coord B = *(Coord*) b;

    if(!flag)   // flag가 0일 땐 값을 오름차순으로 정렬렬
    {
        if(A.value > B.value)
            return 1;
        else if(A.value < B.value)
            return -1;
        else
            return 0;
    }
    else        //flag가 0이 아닐 땐 위치를 오름차순으로 정렬렬
    {
        if(A.location > B.location)
            return 1;
        else if(A.location < B.location)
            return -1;
        else
            return 0;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    Coord* cord = (Coord*)calloc(n, sizeof(Coord)); //

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &cord[i].value);    //입력받은 값을 value에 저장
        cord[i].location = i;
    }

    qsort(cord, n, sizeof(Coord), compare);

    for(int i = 0; i < n - 1; i++)
    {
        if(cord[i].value == cord[i+1].value)
        {
            cord[i+1].compress = cord[i].compress;
        }
        else
        {
            cord[i+1].compress = cord[i].compress + 1;
        }
    }

    flag = 1;

    qsort(cord, n, sizeof(Coord), compare);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", cord[i].compress);
    }

    return 0;
}