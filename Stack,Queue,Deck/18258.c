#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 2000000

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

void push(Queue *q, int x)
{
    q->data[q->rear++] = x;
}

void pop(Queue *q)
{
    if(q->front == q->rear)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", q->data[q->front++]);
}

void size(Queue *q)
{
    printf("%d\n", q->rear - q->front);
}

void empty(Queue *q)
{
    if(q->front == q->rear)
        printf("1\n");
    else
        printf("0\n");
}

void front(Queue *q)
{
    if(q->front == q->rear)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", q->data[q->front]);
}

void back(Queue *q)
{
    if(q->front == q->rear)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", q->data[q->rear - 1]);
}

int main()
{
    int N;
    scanf("%d", &N);

    Queue Q;
    Q.front = Q.rear = 0;    // init

    while(N--)
    {
        char str[100];
        scanf("%s", str);

        // 정수가 아니기 때문에 switch문 불가능 => strcmp 사용

        if(strcmp(str, "push") == 0)
        {
            int input;
            scanf("%d", &input);
            push(&Q, input);
        }
        else if(strcmp(str, "pop") == 0)
            pop(&Q);
        else if(strcmp(str, "size") == 0)
            size(&Q);
        else if(strcmp(str, "empty") == 0)
            empty(&Q);
        else if(strcmp(str, "front") == 0)
            front(&Q);
        else if(strcmp(str, "back") == 0)
            back(&Q);
    }

    return 0;
}