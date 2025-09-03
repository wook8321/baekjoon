#include <stdio.h>

#define SIZE 1000

typedef struct {
    int data[SIZE + 1];
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->front = q->rear = 0;
}

int isFull(Queue *q)
{
    return (q->rear + 1) % (SIZE + 1) == q->front;
} 

int isEmpty(Queue *q)
{
    return q->rear == q->front;
}

void enqueue(Queue *q, int x)
{
    if(isFull(q)) return;
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % (SIZE + 1);   
}

int dequeue(Queue *q)
{
    if(isEmpty(q)) return -1;
    int leave = q->data[q->front];
    q->front = (q->front + 1) % (SIZE + 1);
    return leave;
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    Queue Q;
    init(&Q);

    for(int i = 1; i <= N; i++)
    {
        enqueue(&Q, i);
    }

    printf("<");
    for(int i = 0; i < N-1; i++)
    {
        for(int j = 0; j < K-1; j++)
        {
            /*
            Q.front = (Q.front + 1) % (SIZE + 1);
            Q.rear = (Q.rear + 1) % (SIZE + 1);
        
            이렇게 직접 건드리면 안된다. => enqueue, dequeue로 회전
            */
            int temp = dequeue(&Q);
            enqueue(&Q, temp);
        }
        
        printf("%d, ", dequeue(&Q));
    }
    printf("%d>", dequeue(&Q));

    return 0;
}