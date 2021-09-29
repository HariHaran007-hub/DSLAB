#include<stdio.h>
# define MAX 10
int arr[MAX];

int i;

void insert(int j , int data)
{
    if(arr[j] == NULL)
        arr[j] = data;
    else if(data < arr[j])
        insert((2*j+1),data);
    else
        insert((2*j+2),data);
}
void display()
{
    for(i = 0; i < MAX; i++)
    {
        if(arr[i] == NULL)
        {

        }
        printf("%d ",arr[i]);
    }
}

void main()
{
    int n,d;
    printf("Number of node to be inserted: ");
    scanf("%d",&n);
    for(i = 0; i < n ; i++)
    {
        if(i == 0)
        {
            printf("Enter parent data #%d : ",i+1);
            scanf("%d",&d);
            insert(0,d);
        }else
        {
            printf("Enter  data #%d : ",i+1);
            scanf("%d",&d);
            insert(0,d);

        }
    }
    display();


}
