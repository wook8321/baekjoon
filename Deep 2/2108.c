#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int input[500001];  // input 배열이 지역변수에 있으면 스택 오버플로우될 수 있다.

void mean(int list[], int n)
{
    double sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += list[i];
    }

    // 1. %0.f를 통해 소숫점에서 반올림을 할 수 있지만, 음수/양수 섞인 케이스에서 오답이 남.
    // 2. 양수는 0.5를 더하고, 음수는 0.5를 빼서 꼼수로 반올림 가능.

    printf("%d\n", (int)round(sum / n));
}

int compare(void* first, void* second)
{
    int* a = (int*)first;
    int* b = (int*)second;

    if (*a < *b)
        return -1;
    else if (*a == *b)
        return 0;
    else
        return 1;
}

void median(int list[], int n)
{   
    if(n == 1)
    {
        printf("%d\n", list[0]);
    }
    else
    {
        printf("%d\n", list[n/2]);
    }
}

void frequent(int list[], int n)
{
    int fre[8001] = { 0 };    
    
    int max = 0;
    int cnt = 0;
    int idx;

    for(int i = 0; i < n; i++)
    {
        idx = list[i] + 4000;
        fre[idx]++;

        if(max < fre[idx])
        {
            max = fre[idx];
        }
    }

    for(int i = 0; i < 8001; i++)
    {
        if(fre[i] == max)
        {
            if(cnt == 0)
            {
                cnt++;
                idx = i;
            }
            else if(cnt == 1)
            {
                idx = i;
                break;
            }
        }   
    }

    printf("%d\n", idx - 4000);
} 

void range(int list[], int n)
{
    printf("%d\n", list[n-1] - list[0]);
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }
    
    qsort(input, n, sizeof(input[0]), compare);

    mean(input, n);
    median(input, n);
    frequent(input, n);
    range(input, n);

    return 0;
}