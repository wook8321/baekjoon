/*

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[6];
} Person;

Person people[1000001];

int count = 0;

int cmp(void* a, void* b)
{
    return strcmp((Person*)b->name, (Person*)a->name);  
    
    // cmp 함수에서 a < b 이면 음수, a > b 이면 양수를 반환해야 한다. 
    // 이 문제의 경우 내림차순으로 정렬하길 원하므로 b가 사전적으로 후순위라면 b > a 이므로 양수를 반환해 b가 먼저 정렬된다. 
    // (Person*)b->name, (Person*)a->name 이라고 명시할 경우 a와 b가 (Person*)로 변환하기 전에 ->가 사용된다.
}

void enter(char* name)
{
    strcpy(people[count++].name, name);
}

void leave(char* name)
{
    for(int i = 0; i < count; i++)
    {
        if(strcmp(people[i].name, name) == 0)
        {
            strcpy(people[i].name, people[count-1].name);
            count--;
        }
    }
}

int main()
{
    int N;
    scanf("%s", &N);

    char name[6];
    char action[6];

    for(int i = 0; i < N; i++)
    {
        scanf("%s %s", name, action);

        if(strcmp(action, "enter") == 0)
        {
            enter(name);
        }
        else
        {
            leave(name);
        }
    }

    qsort(people, count, sizeof(Person), cmp);

    for(int i = 0; i < count; i++)
    {
        printf("%s\n", people[i].name);
    }

    return 0;
}

*/

#include <stdio.h>
#include <string.h>
#define HASH_SIZE 1000000   // 출입 기록 수가 10^6 이하이므로 1000000으로 설정

typedef struct Node {
    char name[6];           // 출입한 사람 이름
    int present;            // 현재 회사에 있는 지 여부 (1이면 회사에 있다.)
    struct Node* next;      // 체이닝 포인터 (충돌 처리)
} Node;

Node* hash_table[HASH_SIZE];    // 해쉬 테이블

// 해시 함수 (djb2 변형)
// 문자열을 정수로 변환, 충돌 확률이 낮은 해쉬 알고리즘
unsigned int hash(const char* str) {
    unsigned long hash = 5381;
    int c;
    while((c = *str++))     // 문자열 순회
        hash = ((hash << 5) + hash) + c;    //hash * 33 + c;
    return hash % HASH_SIZE;    // 해쉬 사이즈로 나눈 나머지 반환
}

Node* find(char* name)
{
    unsigned int h = hash(name);    // 이름에 대한 해쉬값 계산
    Node* curr = hash_table[h];     // 해당 인덱스(해쉬값)의 리스트 값

    while(curr) // 리스트 순회
    {
        if(strcmp(curr->name, name) == 0)   // 찾는 이름과 같으면 반환
            return curr;
        curr = curr->next;
    }

    return NULL;    // 못 찾으면 NULL 반환
}

void insert_update(char* name, int present)
{
    Node* curr = find(name);    // 이름이 존재하는지 확인

    if(curr)    // 이미 존재하면 출근 상태만 갱신
    {
        curr->present = present;
        return;
    }

    // 존재하지 않으면 새 노드 동적 할당
    Node* new = (Node*)malloc(sizeof(Node));
    strcpy(new->name, name);        // 이름 복사
    new->present = present;         // 상태 설정
    unsigned int h = hash(name);    // 해쉬값 계산
    new->next = hash_table[h];      // 기존 링크드 리스트에 추가
    hash_table[h] = new;            
}

char* names[HASH_SIZE];     // 회사 사람들 이름 포인터 배열
int name_count = 0;         // 현재 회사에 있는 사람 수

int cmp(void* a, void* b)   // qsort용 cmp 함수
{
    return strcmp(*(char**)b, *(char**)a);  // 내림차순을 위해 b먼저, char형 포인터 배열이므로 char**로 
}

int main()
{
    int n;
    scanf("%d", &n);

    char name[6], action[6];    // 입력 받을 이름과 행동 문자열

    for(int i = 0; i < n; i++)
    {
        scanf("%s %s", name, action);

        if(strcmp(action, "enter") == 0)
            insert_update(name, 1);     // enter이면 회사에 들어옴
        else
            insert_update(name, 0);     // leave면 회사에서 나감
    }

    for(int i = 0; i < HASH_SIZE; i++)
    {
        Node* curr = hash_table[i];     // 각 버킷의 리스트 순회
        
        while(curr)
        {
            if(curr->present)           // 회사에 있는 사람만
            {
                names[name_count] = curr->name;     // 이름 저장
                name_count++;           // 사람 수 증가
            }
            curr = curr->next;
        }
    }

    qsort(names, name_count, sizeof(char*), cmp);   // 내림차순 정렬 (사전 역순)

    for(int i = 0; i < name_count; i++)
    {
        printf("%s\n", names[i]);
    }

    return 0;
}