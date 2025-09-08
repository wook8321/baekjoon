#include <stdio.h>
#define SIZE 1000005

typedef struct {
    int data[SIZE + 1];
    int front;
    int rear;
} Deck;

int isEmpty(Deck *d)
{
    return d->front == d->rear;
}

int isFull(Deck *d)
{
    return (d->rear + 1) % SIZE == d->front;
}

void add_front(Deck *d, int x)
{
    if(isFull(d)) return;
    d->front = (d->front - 1 + SIZE) % SIZE;
    d->data[d->front] = x;
}

void add_rear(Deck *d, int x)
{
    if(isFull(d)) return;
    d->data[d->rear] = x;
    d->rear = (d->rear + 1) % SIZE;
}

int pop_front(Deck *d)
{
    if(isEmpty(d)) return -1;
    int val = d->data[d->front];
    d->front = (d->front + 1) % SIZE;
    return val;
}

int pop_rear(Deck *d)
{
    if(isEmpty(d)) return -1;
    d->rear = (d->rear - 1 + SIZE) % SIZE;
    return d->data[d->rear];
}

int count(Deck *d)
{
    return (d->rear - d->front + SIZE) % SIZE;
}

int empty(Deck *d)
{
    if(isEmpty(d)) return 1;
    else    return 0;
}

int print_front(Deck *d)
{
    if(isEmpty(d)) return -1;
    
    return d->data[d->front];
}

int print_rear(Deck *d)
{
    if(isEmpty(d)) return -1;

    return d->data[(d->rear - 1 + SIZE) % SIZE];
}

int main()
{
    int N;
    scanf("%d", &N);
    Deck D;
    
    D.front = D.rear = 0;

    for (int i = 0; i < N; ++i) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) {
            int x; scanf("%d", &x); add_front(&D, x);
        } else if (cmd == 2) {
            int x; scanf("%d", &x); add_rear(&D, x);
        } else if (cmd == 3) {
            printf("%d\n", pop_front(&D));
        } else if (cmd == 4) {
            printf("%d\n", pop_rear(&D));
        } else if (cmd == 5) {
            printf("%d\n", count(&D));
        } else if (cmd == 6) {
            printf("%d\n", empty(&D));
        } else if (cmd == 7) {
            printf("%d\n", print_front(&D));
        } else if (cmd == 8) {
            printf("%d\n", print_rear(&D));
        }
    }

    return 0;
}