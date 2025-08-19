#include <stdio.h>
#include <string.h>

typedef struct {
    char name[101];                 // 회원의 이름
    struct Member* next;
} Member;

Member* member_list[201] = {NULL};     // 최대 200살
Member* tail[201] = {NULL};

void insert(int age, char* name)
{
    Member* newMember = (Member*)malloc(sizeof(Member));
    strcpy(newMember->name, name);
    newMember->next = NULL;

    if(member_list[age] == NULL)
    {
        member_list[age] = newMember;
        tail[age] = newMember;
    }
    else
    {
        tail[age]->next = newMember;
        tail[age] = newMember;
    }
}

void PrintAndFree()
{
    for(int age = 1; age <= 200; age++)
    {
        Member* cur = member_list[age];
    
        while(cur != NULL)
        {
            printf("%d %s\n", age, cur->name);
            Member* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int age;
    char name[101];

    for(int i = 0; i < N; i++)
    {
        scanf("%d %s", &age, name);
        insert(age, name);
    }

    PrintAndFree();

    return 0;
}