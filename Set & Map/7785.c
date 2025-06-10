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
    
    /* 
        cmp 함수에서 a < b 이면 음수, a > b 이면 양수를 반환해야 한다. 
        이 문제의 경우 내림차순으로 정렬하길 원하므로 b가 사전적으로 후순위라면 b > a 이므로 양수를 반환해 b가 먼저 정렬된다.
        
        
        (Person*)b->name, (Person*)a->name 이라고 명시할 경우 a와 b가 (Person*)로 변환하기 전에 ->가 사용된다.

    */
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