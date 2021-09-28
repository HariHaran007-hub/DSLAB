#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int exp;
    int coef;
    struct node *next;
};

struct node *newnode,*temp;
struct node *p1,*p2,*p3;

struct node * createList(struct node *p){

    int i,n;
    struct node *head;
    printf("Enter number of nodes to be inserted: ");
    scanf("%d",&n);

    for(i = 0; i < n ; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter coef and exp of #%d term: ",i+1);
            scanf("%d%d",&newnode->coef,&newnode->exp);
            newnode->next = NULL;

        if(i == 0)
        {
           head = newnode;
           temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void printList(struct node * list)
{
    while(list != NULL)
    {
        printf("%d x ^ %d ",list->coef,list->exp);
        list =list->next;
    }
    printf("\n");
}

struct node * add(struct node *a,struct node *b )
{
    struct node *result;
    int i = 0;//for assuming head for 3 node;
    while(a != NULL && b != NULL)
    {
       newnode = (struct node *)malloc(sizeof(struct node));
       newnode->next = NULL;

       if(a->exp > b->exp)
       {
           newnode = a;
           a = a->next;
       }
       else if(a->exp < b->exp)
       {
           newnode = b;
           b = b->next;
       }
       else
       {

           newnode->coef = a->coef + b->coef;
           newnode->exp = a->exp;
           a = a->next;
           b = b->next;

       }
       //for linking
       if(i == 0)
       {
            temp = newnode;
            result = newnode;
            i++;
       }
       else
       {
           temp->next = newnode;
           temp = newnode;
       }
       //In real case any one of the expression become NULL

       if(a != NULL)
       {
           temp->next = a;
       }
       if(b != NULL)
       {
           temp->next = b;
       }

    }
    return result;


}

void main()
{
    p1 = createList(p1);
    p2 = createList(p2);
    printList(p1);
    printList(p2);
    struct node *p3;
    p3 = add(p1,p2);
    printList(p3);
}





