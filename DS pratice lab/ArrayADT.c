#include<stdio.h>
#define MAX 10

int n;
int array[MAX];

void create(){
    printf("Enter number of elements to be inserted: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data %d: ",i+1);
        scanf("%d",&array[i]);
    }
    
}

void print(){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    
}

void insert(int pos , int element){
    
    for(int i = n-1; i >= pos -1  ; i--){
        array[i+1] = array[i];
    }
    array[pos - 1] = element;
    n++;
    print();
}

void deleteion(int element){
    int pos = 0;
    for(int i = 0 ; i < n ; i ++){
        if (array[i] == element)
        {
            pos++;
            break;
        }
        pos++;
    }
   pos--;
    for (int  i = pos+1  ; i < n; i++)
    {
        array[i-1] = array[i];
    }
    n--;
    print();
}

void main(){
    create();
    print();
    insert(3,100);
    deleteion(100);
}