#include <stdio.h>
#define size 20

char palin[size], st[size];
int top = -1, len;

void push(char x)
{
    if (top == size - 1)
    {
        printf("Overflow");
    }

    else
    {
        top++;
        st[top] = x;
    }
}
char pop()
{
    char ele;
    if (top == -1)
    {
        printf("Underflow");
        return 'X';
    }

    else
    {
        ele = st[top];
        top--;
        return ele;
    }
}

void main()
{
    int i = 0, check;
    char str[size], x, rev[size];

    printf("Enter string: ");
    scanf("%s", str);

    x = str[i];
    while (x != '\0')
    {
        push(x);
        i++;
        x = str[i];
    }
    len = top;
    i = 0;

    while (top != -1)
    {
        rev[i] = pop();
        i++;
    }
    rev[i] = '\0';

    i = 0;

    for (i; i <= len; i++)
    {
        if (str[i] == rev[i])
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }

    if (check == 1)
    {
        printf("Yes, '%s' is a palindrome", str);
    }

    else
    {
        printf("No, '%s' is not a palindrome", str);
    }
}