#include<stdio.h>
#define MAX 100
void main(){
    int n,x;
    int array[MAX];
    printf("Enter no f elements to be inserted: ");
    scanf("%d",&n);

    printf("Enter elements in sorted order: ");
    for (int  i = 0; i < n; i++)
    {
        printf("Enter data {%d}: ");
        scanf("%d",&array[i]);
    }

    printf("Enter elements to be searched: ");
    scanf("%d",&x);
    
    
    int min_index = 0;
    int max_index = n-1;
    int middle_index ;
    middle_index = (min_index + max_index)/2;

    while (min_index <= max_index)
    {
       if(array[middle_index] < x){
           min_index = middle_index +1;
       }else if (array[middle_index] == x)
       {
           printf("Elment is found at %d position",middle_index+1);
           break;
       }else {
           
           max_index = middle_index - 1;
       }
       middle_index = (min_index + max_index)/2;

    }

    if(min_index > max_index ){
        printf("Element not found");
    }
    

    
    
    

}