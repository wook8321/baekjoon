#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substr_count = 0;
char substr[500500][1001];  // 최대 substr 개수 500500개

int cmp(void* a, void* b)
{
    return strcmp((char*) a, (char*) b);
}

int main()
{
    char str[1001];
    scanf("%s", str);

    int n = strlen(str);

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int len = j - i + 1;
            strncpy(substr[substr_count], str + i, len);
            // str + i : (i + 1)번째부터 시작하는 포인터
            // ex) str + 2 => 앞에서부터 3번째 자리에서 len 길이만큼의 글자를 복사

            substr[substr_count][len] = '\0';
            // strncpy는 널 문자를 끝에 붙여주지 않는다.

            substr_count++;
        }
    }

    qsort(substr, substr_count, sizeof(substr[0]), cmp);

    int unique_count = 1;

    for(int i = 1; i < substr_count; i++)
    {
        if(strcmp(substr[i - 1], substr[i]) != 0)
        {
            unique_count++;
        }
    }

    printf("%d\n", unique_count);

    return 0;
}