/*
#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);

    char name[100000][21];
    int count = 0, total = 0;

    for(int i = 0; i < N; i++)
    {   
        char tmp[21];
        scanf("%s", tmp);
        
        if(strcmp(tmp, "ENTER") == 0)
        {
            total += count;
            count = 0;
        }
        else
        {
            int duplicate = 0;
            for(int j = 0; j < count; j++)
            {
                // ENTER 이후에 입력된 만큼만 중복 확인
                if(strcmp(tmp, name[j]) == 0)
                {
                    duplicate = 1;
                    break;
                }
            }

            // 중복이 아니면 name에 복사
            if(!duplicate)
            {
                strcpy(name[count], tmp);
                count++;
            }
        }
    }

    total += count; // 마지막 그룹 처리

    printf("%d\n", total);
    return 0;
}

=> 일반적인 이중 for문은 시간 초과가 남.

*/

#include <stdio.h>
#include <string.h>

char unsorted[100000][21];
char sorted[100000][21];

void merge_sort(char a[][21], int left, int mid, int right)
{
    int i = left, j = mid + 1;
    int k = left;

    while(i <= mid && j <= right)
    {
        if(strcmp(a[i], a[j]) <= 0)
        {
           strcpy(sorted[k], a[i]);
           i++;
        }

        else
        {
            strcpy(sorted[k], a[j]);
            j++;
        }

        k++;
    }

    if(i > mid)
    {
        for(int l = j; l <= right; l++)
        {
            strcpy(sorted[k], a[l]);
            k++;
        }
    }

    else
    {
        for(int l = i; l <= mid; l++)
        {
            strcpy(sorted[k], a[l]);
            k++;
        }
    }

    // 정렬된 배열을 unsorted 배열에 다시 입력해야 비교 가능.
    for(int t = left; t <= right; t++)
    {
        strcpy(a[t], sorted[t]);
    }

    return ;
}

void merge(char a[][21], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        merge(a, left, mid);
        merge(a, mid + 1, right);
        merge_sort(a, left, mid, right);
    }

    return ;
}

int main()
{
    int N;
    scanf("%d", &N);

    char str[21];    // 입력받은 문자열
    int count = 0;  // 총 곰곰티콘이 사용된 횟수
    int num = 0;    // 일시적으로 unsorted에 들어간 문자열들과 같은 사람인 자 비교하기 위한 값

    scanf("%s", str); // 처음 ENTER 입력 받기
    for(int i = 1; i < N; i++)
    {
        scanf("%s", str);

        if(strcmp(str, "ENTER") != 0)   
        {
            // ENTER를 입력받은 게 아닌 경우, unsorted에 복사 및 일시적인 값 num++  
            strcpy(unsorted[num], str);
            num++;
        }

        if(i == N-1 || strcmp(str, "ENTER") == 0)
        {
            // ENTER가 입력되었거나 마지막 입력일 경우, merge 및 num만큼 저장된 문자열들을 비교해 count++
            merge(unsorted, 0, num - 1); // 마지막 인덱스가 들어가야하므로, num이 아닌 num - 1
            for(int j = 0; j < num; j++)
            {
                if(strcmp(unsorted[j], unsorted[j + 1]) != 0 || j == num - 1)
                    count++;
                    // 총 곰곰티콘 사용된 횟수
            }
            num = 0;
            // 같은 사람이 들어왔는 지 비교하기 위한 일시적인 값 num 초기화
        }
    }

    printf("%d\n", count);

    return 0;
}