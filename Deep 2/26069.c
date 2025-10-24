#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);

    char dance[1000][21];    // 춤추는 사람 이름 배열
    strcpy(dance[0], "ChongChong");
    char person1[21], person2[21];  // 입력받을 배열
    int count = 1;  // 사람 수 (이미 총총이 포함)

    for(int i = 0; i < N; i++)
    {
        int dance_1 = 0, dance_2 = 0;   
        // 입력받은 사람이 춤을 추고 있는 지에 대한 값, 1은 춤을 추는 상태 0은 춤을 추지 않는 상태

        scanf("%s %s", person1, person2);

        for(int j = 0; j < count; j++)  // 춤추는 사람 수만큼 배열과 비교
        {
            if(strcmp(person1, dance[j]) == 0)
                dance_1 = 1;
            if(strcmp(person2, dance[j]) == 0)
                dance_2 = 1;
        }

        // 입력받은 두 사람 중 한 사람만 춤을 출 때 dance 배열에 추가 및 count 증가
        if(dance_1 == 1 && dance_2 == 0)
        {
            strcpy(dance[count++], person2);
        }

        if(dance_1 == 0 && dance_2 == 1)
        {
            strcpy(dance[count++], person1);
        }
    }

    printf("%d\n", count);

    return 0;
}