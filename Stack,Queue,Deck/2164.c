#include <stdio.h>
#include <stdlib.h>
#define SIZE 500000

typedef struct {
    int data[SIZE + 1];
    int front;
    int rear;
} Queue;

void init(Queue *Q)
{
    Q->rear = Q->front = 0;
}

int isFull(Queue *Q)
{
    return (Q->rear + 1) % (SIZE + 1) == Q->front;
}

int isEmpty(Queue *Q)
{
    return Q->rear == Q->front;
}

void enqueue(Queue *Q, int x)
{
    if(isFull(Q)) return;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % (SIZE + 1);
}

int dequeue(Queue *Q)
{
    if(isEmpty(Q)) return;
    int leave = Q->data[Q->front];
    Q->front = (Q->front + 1) % (SIZE + 1);
    return leave;
}

int main()
{
    int N;
    scanf("%d", &N);

    Queue q;
    init(&q);

    for(int i = 1; i <= N; i++)
    {
        enqueue(&q, i);
    }

    // 남은 원소 수가 1개여야하므로 q.front를 마지막 원소가 들어간 자리인 q.rear -1과 비교
    // 큐가 빈 경우와 꽉 찬 경우를 구분하기 위해 SIZE+1로 크기를 키움. (실제 원소 개수는 SIZE)

    while(q.front != (q.rear - 1 + SIZE + 1) % (SIZE + 1))
    {
        dequeue(&q);

        int temp = dequeue(&q);
        enqueue(&q, temp);
    }

    printf("%d\n", dequeue(&q));
    return 0;
}