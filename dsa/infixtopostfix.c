#include <stdio.h>
#include <string.h>
char stack[100];
    int top = -1;
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
void push(char c){
    stack[++top]=c;
}
int pop(){
    return stack[top--];
}
void infixToPostfix(char s[])
{
    char result[1000];
    int resultIndex = 0;
    int len = strlen(s);
    

    for (int i = 0; i < len; i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result[resultIndex++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                result[resultIndex++] = pop();
            }
            top--;
        }
        else
        {
            while (top >= 0 && (prec(s[i]) < prec(stack[top]) ||
                                       prec(s[i]) == prec(stack[top])))
            {
                result[resultIndex++] = pop();
            }
            push(c);
        }
    }
    while (top >= 0)
    {
        result[resultIndex++] = pop();
    }

    result[resultIndex] = '\0';
    printf("%s\n", result);
}
int main()
{
    char exp[] = "9-((3*4)+8)/4";

    infixToPostfix(exp);

    return 0;
}
