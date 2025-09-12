#include <stdio.h>
#define SIZE 1005

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

// 풍선 값이 음수일 수도 있으니까, push와 pop이 앞과 뒤에서 이루어지도록 함수 설정

void push_front(Queue *q, int x)
{
    if(q->front == (q->rear + 1) % SIZE) return;
    q->front = (q->front - 1 + SIZE) % SIZE;    // 먼저 front값 조정
    q->data[q->front] = x;
}

void push_rear(Queue *q, int x)
{
    if(q->front == (q->rear + 1) % SIZE) return;
    q->data[q->rear] = x;       // 덱에서 rear는 마지막 원소가 들어갈 자리(빈 공간)를 나타낸다.
    q->rear = (q->rear + 1) % SIZE;
}

int pop_front(Queue *q)
{
    if(q->rear == q->front) return -1;
    int leave = q->data[q->front];
    q->front = (q->front + 1) % SIZE;
    return leave;
}

int pop_rear(Queue *q)
{
    if(q->rear == q->front) return -1;
    int leave = q->data[(q->rear - 1 + SIZE) % SIZE];
    q->rear = (q->rear - 1 + SIZE) % SIZE;
    return leave;
}

int main()
{
    int N;
    scanf("%d", &N);

    Queue Q;
    Q.front = Q.rear = 0;
    
    int balloon[SIZE];      // 선언 까먹지 말기

    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &balloon[i]);
        push_rear(&Q, i);
    }

    int k = 1;

    printf("%d ", pop_front(&Q)); // 처음 풍선 터뜨리고 출력
    int move = balloon[1];  // 풍선 안의 값이  음수일 때와 양수일 때를 나눠서

    for(int i = 1; i < N; i++)
    {
        if(move > 0)
        {
            for(int j = 0; j < move - 1; j++)
            {
                // 양수일 때는 (풍선 안의 값 - 1)만큼 숫자를 뒤로 옮기기
                int val = pop_front(&Q);
                push_rear(&Q, val);
            }
        }

        else
        {
            for(int j = 0; j > move; j--)
            {
                // 음수일 때는 |풍선 안의 값| 만큼 숫자를 뒤에서 앞으로
                int val = pop_rear(&Q);
                push_front(&Q, val);
            }
        }
        int idx = pop_front(&Q);
        printf("%d ", idx);
        move = balloon[idx];
    }

    return 0;
}