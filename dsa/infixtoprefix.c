#include <stdio.h>
#include <string.h>
#define size 100
char stack[size];
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
    if(top==size-1){
        printf("Stack Overflow!");
    }
    else{
        stack[++top]=c;
    }
}
int pop(){
    if(top==-1){
        printf("Stack empty");
        return 0;
    }
    else{
        int x=stack[top--];
        return x;
    }
}
void infixToPrefix(char s[])
{
    char result[size];
    int resultIndex = 0;
    int len = strlen(s);
    

    for (int i = 0; i < len; i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result[resultIndex++] = c;
        }
        else if (c == ')')
        {
            push(c);
        }
        else if (c == '(')
        {
            while (top >= 0 && stack[top] != ')')
            {
                result[resultIndex++] = pop();
            }
            top--;
        }
        else
        {
            while (top >= 0 && (prec(c) < prec(stack[top])))
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
    strrev(result);
    printf("%s\n", result);
}
int main()
{
    char exp[] = "9-((3*4)+8)/4";

    infixToPrefix(strrev(exp));

    return 0;
}