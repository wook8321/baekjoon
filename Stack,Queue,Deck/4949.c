#include <stdio.h>
#include <string.h>

int main()
{
    char string[105];

    while (1)
    {
        fgets(string, sizeof(string), stdin);

        if (strcmp(string, ".\n") == 0 || strcmp(string, ".") == 0)
            break;

        char stack[105];
        int top = -1;
        int ok = 1; // 아무것도 없는 상태는 yes

        for (int i = 0; string[i] != '\0'; i++)
        {
            char c = string[i];
            if (c == '(')
                stack[++top] = c; // push

            else if (c == ')')
            {
                if(stack[top] != '(' || top == -1)
                {
                    ok = 0;
                    break;
                }   
            
                top--;  // pop
            }

            else if (c == '[')
                stack[++top] = c;  // push
            
            else if (c == ']')
            {
                if(stack[top] != '[' || top == -1) 
                {
                    ok = 0;
                    break;
                }
                
                top--;  // pop
            }
        }

        if (ok && top == -1)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
