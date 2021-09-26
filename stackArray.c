#include<stdio.h>
#include<conio.h>
#define size 5
int stack[size];
int top = -1;
void push()
{
    int x;
        printf("Enter element to be inserted: \n");
        scanf("%d",&x);
    if(top == size-1)
    {
     printf("Stack overflow Error\n");
    }

    else
    {
        top = top + 1;
        stack[top] = x;

    }
}
void display()
{

    for (int i = top; i >= 0 ; i--)
    {
            if(i == top ){
                printf("Top --> %d\n",stack[i]);
            }
            else
            {
                printf("        %d\n",stack[i]);
            }
    }
}


void pop()
{
    if(top == -1)
        printf("Empty stack\n");
    else
    {
        int item = stack[top];
        printf("Data item %d is popped.\n",item);
        top = top - 1;
        display();
    }
}
void main()
{
    for(int i = 1 ; i <=size; i++){
        push();
    }
    display();
    pop();


}
