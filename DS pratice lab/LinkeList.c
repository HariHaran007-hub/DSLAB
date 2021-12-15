#include<stdio.h>
#include<stdlib.h>

 struct Node {
    int data;
   struct Node *next;
};
int n;
struct Node *head,*newnode,*temp;
void create(){
    printf("Enter no of elements: ");
    scanf("%d",&n);

    for(int i = 0 ; i<n ; i ++){
        newnode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data [%d] : ",i+1);
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if(i == 0){
            head = newnode;
            temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }
}
void insert(){
    int pos;
    
    newnode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data to be inserted : ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    printf("Enter position to be inserted: ");
    scanf("%d",&pos);

    temp = head;
    pos = pos - 1;

    for(int i = 0 ; i < pos -1; i ++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    n++;
    print();
}

void deletion(){
    int x,pos;
    temp = head;
    printf("Enter node to be deleted: ");
    scanf("%d",&x);
    while (temp != NULL)
    {
        if(temp->data == x){
            pos++;
            break;
        }
        pos++;
        temp = temp->next;
    }
    pos = pos - 1;
    temp = head;
    for( int i = 0 ; i < pos -1; i ++){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    n--;
    print();
    

    
}

void print(){
    temp = head;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    
}
void main(){
    create();
    print();
   deletion();
}
