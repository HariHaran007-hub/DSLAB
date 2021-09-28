#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*head;
int n;

void enque()
{
    //adding at group
    printf("Enter not of element to be queued: ");
    scanf("%d",&n);
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data 1: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    temp = newnode;
    head = newnode;
    for(int i= 1 ; i < n; i++  ){
         newnode = (struct node *)malloc(sizeof(struct node));
         printf("Enter data %d: ",i+1);
         scanf("%d",&newnode->data);
         temp->next = newnode;
         temp = newnode;
    }
}
void enque2()
{
    //Adding at last single by single
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element to be queue: ");
    scanf("%d",&newnode->data);
    for(int i =0 ; i < n -1; i++){
       temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = NULL;
    n++;
}

void display()
{
    printf("\n");
    temp = head;
    for(int i = 0 ; i < n; i++)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void deque()
{
    temp = head;

    head=temp->next;
    temp = head;
    n--;

}
void priority()
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter element to be attache at most priority:  ");
    scanf("%d",&newnode->data);
    newnode->next = temp;
    head = newnode;
    n++;
}

void main()
{

    enque();
    enque2();
    display();

}
