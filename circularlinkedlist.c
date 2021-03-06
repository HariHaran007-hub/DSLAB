#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *temp,*head,*newnode;
int n;//No of elements

void create(){
    printf("Enter no of elements to be inserted: " );
    scanf("%d",&n);
    newnode =(struct node *) malloc(sizeof(struct node));
    printf("Enter data #1: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    head = newnode;//dont touch head for manupulation

    temp = newnode;

    for(int i = 1 ; i < n; i++){
        newnode =(struct node *) malloc(sizeof(struct node));
        printf("Enter data #%d: ",i+1);
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        temp->next = newnode;

        temp = newnode;

    }
    temp->next = head;//For circular

}

void insert(){
    int position ;
    printf("\nEnter the position : ");
    scanf("%d",&position);
    newnode =(struct node *) malloc(sizeof(struct node));
    printf("\nEnter the element to be inserted : ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
   ;
    temp = head ;

    if(position == 0)
    {
       for(int i =0 ; i < n-1 ; i++){
        temp = temp->next;
       }

       temp->next = newnode;
       newnode->next = head ;
       head = newnode ;
       n++;


    }else if(position  > 0 && position < n - 1 )
    {
        for(int i = 1; i <position -1 ; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next= newnode;
        n++;
    }
    else{
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next  = head;
            n++;
    }
}

void delete()
{
    int position = -1,x;

    printf("\nEnter element to be deleted: ");
    scanf("%d",&x);
    temp = head;//for searching
     for(int i = 0 ; i < n   ; i ++){
        if(temp->data == x){
            position ++;
            break;
        }
        temp = temp->next;
        position ++;
     }
     printf("\n%d\n",position);


    temp = head;//for changing


    if(position == 0)
    {
        struct node *temp2;
        temp2 = head;
        head = temp->next ;
        do{
            temp2 = temp2->next;
        }while(temp2->next != temp);
        temp2->next = head;
        n--;

    }
    else if(position > 0 && position < n -1)
    {
         for(int i = 1; i <position  ; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        n--;
    }
    else if(position == n - 1){
         for(int i = 0; i < n -2 ; i++){
            temp = temp->next;
         }
        temp->next = head;
    }
}


void search(){
    int x,position = 0;
    printf("\nEnter element to be search: ");
    scanf("%d",&x);

    temp = head;

    if(head == NULL){
        printf("Empty list!!");
    }
    else {
        do
        {
            if(temp->data == x){
                position++;
                printf("Element is found at %d",position);
                break;
            }
            position++;
            temp = temp->next;
        }while(temp != head);
    }

}


void display(){

    temp = head;
    do{
        printf("%d -> ",temp->data);
        temp = temp->next;
    }while(temp!= head);
    printf("continue");
}

void main(){
    int choice , ch ;
    do{
   printf("\n\t\t\tCircular Linked List\n");
   printf("1. Create\n2. Display\n3. Insert\n4. Delete\n5. Search\n");
   printf("Enter your choice : ");
   scanf("%d",&choice);
   switch(choice){
   case 1 :
       {
           create();
           break;
       }
       case 2 :
       {
           display();
           break;
       }
       case 3 :
       {
           insert();
           break;
       }
       case 4 :
       {
           delete();
           break;
       }
       case 5 :
       {
           search();
           break;
       }
       default :
        {
            printf("Invalid Choice \n");
        }
   }
    printf("\nEnter 1 to Continue or 0 to Exit\n");
    scanf("%d",&ch);
}while(ch == 1);

}