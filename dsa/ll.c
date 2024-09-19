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
	struct node *temp = start; // Start from the head node

	if (start == NULL)
	{
		printf("The list is empty.\n");
		return;
	}

	printf("Linked list elements: ");
	while (temp != NULL)
	{
		printf("%d -> ", temp->data); // Print the data of the current node
		temp = temp->next;            // Move to the next node
	}
	printf("NULL\n"); // Indicate the end of the list
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
	create(3);
	traverse();
	insert_after();
	traverse();
	delete();
	traverse();
}