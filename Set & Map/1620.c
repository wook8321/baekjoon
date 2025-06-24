#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[21];
    int num;
} Pokemon;

// 퀵정렬을 위한 이름 기준 비교 함수
int cmp(void* a, void* b)
{
    Pokemon* first = *(Pokemon**)a;
    Pokemon* second = *(Pokemon**)b;

    return strcmp(first->name, second->name);
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    // 번호 -> 이름
    Pokemon* pokemon_list = (Pokemon*)malloc(N * sizeof(Pokemon));
    // 이름 -> 번호 : 포인터 배열
    Pokemon** sorted_list = (Pokemon**)malloc(N * sizeof(Pokemon));

    for(int i = 0; i < N; i++)
    {
        scanf("%s", pokemon_list[i].name);
        pokemon_list[i].num = i + 1;
        sorted_list[i] = &pokemon_list[i];  // 포인터로 연결
    }

    // 이름 기준 정렬
    qsort(sorted_list, N, sizeof(Pokemon*), cmp);

    char temp[21];

    for(int i = 0; i < M; i++)
    {
        scanf("%s", temp);

        // 숫자 입력이면
        if(temp[0] >= '0' && temp[0] <= '9')
        {
            int index = atoi(temp); // 문자열 -> 정수
            printf("%s\n", pokemon_list[index-1].name);
        }
        // 문자 입력이면 이름으로 번호 찾기
        else
        {
            Pokemon key = {0};
            strcpy(key.name, temp);
            Pokemon* key_ptr = &key;

            Pokemon** found = (Pokemon**)bsearch(&key_ptr, sorted_list, N, sizeof(Pokemon*), cmp);
            // bsearch는 구조체 포인터를 반환 => found는 구조체를 가리키는 주소다.

            if(found)
                printf("%d\n", (*found)->num);
        }
    }

    free(sorted_list);
    free(pokemon_list);

    return 0;
}