#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push() {
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to push: \n");
    scanf("%d", &newnode->data);
    
    if(top == NULL) {
        top = newnode;
    } else {
        newnode->next = top;
        top = newnode;
    }
}

void pop(){
   struct Node *temp;
   if(top==NULL){
    printf("stack empty");
   }
   else{
    temp = top;
    int x=temp->data;
    printf("deleted elemnt is %d",x);
    top=top->next;
    free(temp);
   }
}

void display(){
    struct Node *temp;
    temp = top;

    if(top == NULL) {
        printf("Stack Empty\n");
    } else {
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void peek() {
    if(top != NULL) {
        printf("Top element is %d\n", top -> data);
    } else {
        printf("Stack Empty!\n");
    }
}

int main(){
    int option  = 0;
    int running = 1;
    while(running) {
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\nEnter your option: ");
        scanf ("%d", &option);
        switch(option) {
            case 1 : push();    break;
            case 2 : pop();     break;
            case 3 : display(); break;
            case 4 : peek();    break;
            case 5 : running=0; break;
            default: printf("Enter valid option!"); break;
        }
    }
    return 0;
}