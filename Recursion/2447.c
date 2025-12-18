#include <stdio.h>

char star[7000][7000];

void cantor(int x, int y, int length)
{
    if(length == 1) return;

    int one_third = length / 3;

    for(int i = x + one_third; i < x + 2 * one_third; i++)
    {
        for(int j = y + one_third; j < y + 2 * one_third; j++)
        {
            // 3*3 좌표의 중앙을 빈칸 처리
            star[i][j] = ' ';
        }
    }

    for(int i = x; i < x + length; i += one_third)
    {
        for(int j = y; j < y + length; j += one_third)
        {
            if(!(i == x + one_third && j == y + one_third))
            // 3*3 좌표에서 중앙을 제외한 8곳에서 재귀
                cantor(i, j, one_third);
        }
    }

    /*
    for(int dx = 0; dx < 3; dx++)
    {
        for(int dy = 0; dy < 3; dy++)
        {
            if(!(dx == 1 && dy == 1))
                cantor(x + dx * one_third, y + dy * one_third, one_third);
        }
    }

    => 이렇게 짜는 게 더 편한 듯
    */
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            star[i][j] = '*';
        }
    }

    cantor(0, 0, N);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%c", star[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}