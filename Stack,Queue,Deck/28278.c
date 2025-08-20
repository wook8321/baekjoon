#include <stdio.h>

int top = -1;
int stack[1000000];

void push(int a)
{
    stack[++top] = a;
}

void pop()
{
    if(top == -1)   
        printf("-1\n");
    else
        printf("%d\n", stack[top--]);
}

void print_num()
{
    printf("%d\n", top+1);
}

void empty()
{
    if(top == -1)
        printf("1\n");
    else
        printf("0\n");
}

void print_top()
{
    if(top == -1)
        printf("-1\n");
    else
        printf("%d\n", stack[top]);
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);

        switch(temp) {
            case 1 :
                int input;
                scanf("%d", &input);
                push(input);
                break;

            case 2 :
                pop();
                break;
            
            case 3 :
                print_num();
                break;
            
            case 4 :
                empty();
                break;

            case 5 :
                print_top();
                break;
        }
    }

    return 0;
}