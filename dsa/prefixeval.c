#include <stdio.h>
#include <string.h>
#include <ctype.h>
float stack[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}
int pop()
{
    if (top == -1)
    {
        printf("Stack empty");
    }
    else
    {
        return stack[top--];
    }
}
int postfixeval(char s[])
{

    float op1 = 0, op2 = 0, val;
    int len = strlen(s);

    for (int i = len-1; i>=0; i--)
    {
        char c = s[i];

        if (isdigit(c))
        {
            push((float)(c-'0'));
        }
        else
        {
            op1 = pop();
            op2 = pop();
            switch (c)
            {
            case '+':
                val = op1 + op2;
                break;
            case '-':
                val = op1 - op2;
                break;
            case '*':
                val = op1 * op2;
                break;
            case '/':
                val = op1 / op2;
                break;
            case '%':
                val = (int)op1 % (int)op2;
                break;
            }
            push(val);
        }
    }
   return(pop());
}
int main()
{
    char exp[] = "-9/+*3484";

    float res=postfixeval(exp);
    printf("%.3f",res);

    return 0;
}