#include <stdio.h>
#define max 5
int val, front = -1, rear = -1;
int queue[max];
void enqueue()
{
    if (front == (rear + 1) % max)
    {
        printf("Queue full");
    }
    else
    {
        printf("enter element");
        scanf("%d", &val);
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[rear] = val;
        }
        else
        {
            rear = (rear + 1) % max;
            queue[rear] = val;
        }
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("queue empty");
    }
    else
    {
        val = queue[front];
        if (front == rear)
        {
            printf("%d", val);
            front = rear = -1;
        }
        else
        {
            printf("%d", val);
            front = (front + 1) % max;
        }
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("queue empty");
    }
    else
    {
        int i = front;
        while (i != rear)
        {
            printf("%d\t", queue[i]);
            i = (i + 1) % max;
        }
        printf("%d", queue[rear]);
    }
}
void main()
{
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    enqueue();
    display();
}