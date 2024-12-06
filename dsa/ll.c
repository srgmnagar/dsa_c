#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node *next;
} *start;
void create(int n)
{
	int data, i;
	struct node *newnode, *temp;
	for (i = 0; i < n; i++)
	{
		if (start == NULL)
		{
			newnode = (struct node *)malloc(sizeof(struct node));
			printf("Enter data:");
			scanf("%d", &data);
			newnode->data = data;
			start = newnode;
		}
		else
		{
			newnode = (struct node *)malloc(sizeof(struct node));
			printf("Enter data:");
			scanf("%d", &data);
			newnode->data = data;
			temp = start;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}
}

void traverse()
{
	struct node *temp = start; 

	if (start == NULL)
	{
		printf("The list is empty.\n");
		return;
	}

	printf("Linked list elements: ");
	while (temp != NULL)
	{
		printf("%d -> ", temp->data); 
		temp = temp->next;           
	}
	printf("NULL\n"); 
}
void insert_before()
{
	int data, x;
	struct node *newnode, *temp, *p;
	printf("enter val before which u want to insert\n");
	scanf("%d", &x);
	printf("enter val\n");
	scanf("%d", &data);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;
	temp = start;
	while (temp->data != x)
	{
		p = temp;
		temp = temp->next;
	}
	if (temp == start)
	{
		newnode->next = temp;
		start = newnode;
	}
	else
	{
		p->next = newnode;
		newnode->next = temp;
	}
}
void insert_after()
{
	int data, x;
	struct node *newnode, *temp;
	printf("enter val after which u want to insert\n");
	scanf("%d", &x);
	printf("enter val\n");
	scanf("%d", &data);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;
	temp = start;
	while (temp->data != x)
	{
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}
void delete() {
	int x;
	struct node *p, *temp;
	printf("enter val u want to delete\n");
	scanf("%d", &x);
	temp=start;
	while (temp->data != x)
	{
		p=temp;
		temp = temp->next;
	}
	if(temp==NULL) {
		printf("value not found");
	}
	else if(temp==start) {
		start=start->next;
		free(temp);
	}
	else {
		p->next=temp->next;
		free(temp);
	}
}
void main()
{
	int choice, running = 1;
    create(5);

    while(running) {
        printf("1. Insert Before\n");
        printf("2. Insert After \n");
        printf("3. Delete       \n");
        printf("4. Display      \n");
        printf("5. Quit         \n");
        printf("Enter choice: ");
        scanf("%d", &choice);
       
        switch(choice){
            case 1 : insert_before(); break;
            case 2 : insert_after();  break;
            case 3 : delete();   break;
            case 4 : traverse();       break;
            case 5 : running = 0;     break;
            default: printf("Enter correct choice!");
        }
    }
	}