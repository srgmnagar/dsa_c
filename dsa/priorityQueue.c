#include <stdio.h>
#include <malloc.h>
struct node
{
    int data, priority;
    struct node *next;
};
struct node *start = NULL;
void insert()
{
    struct node *newnode, *ptr;
    int data, priority;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter val and priority\n");
    scanf("%d %d", &data, &priority);
    newnode->data = data;
    newnode->priority = priority;
    if (start == NULL || newnode->priority < start->priority)
    {
        newnode->next = start;
        start = newnode;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL || ptr->next->priority < newnode->priority)
        {
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
    printf("value inserted");
}
void delete(){
    struct node *ptr;
    if(start==NULL){
        printf("Underflow");
    }
        else{
            ptr=start;
            printf("deleted elemnt is %d",ptr->data);
            start=start->next;
            free(ptr);
        }
}

void main(){
    insert();
    insert();
    delete();
}
