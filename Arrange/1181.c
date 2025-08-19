#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(void* a, void* b)
{
    char* A = *(char**) a;      // void*를 char**(char* word[]의 형태)로 형변환 후 포인터를 통해 역참조해 word[]의 값을 꺼내쓴다다
    char* B = *(char**) b;

    int len_A = strlen(A);
    int len_B = strlen(B);

    if(len_A != len_B)  // 길이가 다를 때 (길이 순으로 먼저 정렬)
        return len_A - len_B;
    else
        return strcmp(A, B);    // 길이가 같을 때 (사전 순으로 정렬)
}

int main()
{
    int n;
    scanf("%d", &n);

    char* word[20000];
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        char temp[51];
        int duplicate = 0;

        scanf("%s", temp);      // 문자열에는 &를 안쓴다.
        
        for(int j = 0; j < count; j++)  // 지금까지 센 단어들과 비교
        {
            if(strcmp(word[j], temp) == 0)  // 만약 같으면 duplicate를 1로 설정해 아래 if문을 건너뛰도록 설정
            {
                duplicate = 1;
                break;
            }
        }

        if(!duplicate)  // 중복되지 않은 문자열이라면면
        {
            word[count] = (char*)malloc(strlen(temp)+1);    
            // temp 뒤에 널문자가 들어갈 자리를 마련하기 위해 strlen(temp)+1, malloc이 반환한 void*를 word[] 형태인 char*로 형변환
            strcpy(word[count], temp);  // 문자열은 strcpy로 복사
            count++;    // 실제 숫자 수 증가
        }
    }

    qsort(word, count, sizeof(char*), compare);

    for(int i = 0; i < count; i++)
    {
        printf("%s\n", word[i]);
        free(word[i]);
    }

    return 0;
}