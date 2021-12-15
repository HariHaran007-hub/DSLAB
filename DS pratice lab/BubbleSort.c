#include<stdio.h>
#define MAX 100
int n;
int array[MAX];
void print(){
    for(int i = 0 ; i < n ; i ++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
void main(){
    int n;
    
    printf("Enter no f elements to be inserted: ");
    scanf("%d",&n);

    for (int  i = 0; i < n; i++)
    {
        printf("Enter data {%d}: ",i+1);
        scanf("%d",&array[i]);
    }
     for(int i = 0 ; i < n ; i ++){
        printf("%d ",array[i]);
    }
    printf("\n");

    int temp;

    for(int i = 0 ; i < n ; i ++){
        for (int j = i+1; j < n ; j++)
        {
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for(int i = 0 ; i < n ; i ++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

