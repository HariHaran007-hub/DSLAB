#include<stdio.h>
#include<string.h>
#define MAX 10
int stack[MAX];
int top = -1;
char expr[20];
int i;

void push(int x){
    if (top == MAX)
    {
        printf("Stack overflow error!!");
    }else{
        stack[++top] = x;
    }

}
int pop(){
    int x;
    if (top == -1)
    {
        printf("Stack underflow error!!");

    }else{
        x = stack[top];
        top--;
    }
    return x;
}
void balancing_parathesis(){
	printf("\nEnter the Expresssion : \n");
	scanf("%s",expr);
	for(int i = 0 ; i<strlen(expr);i++){

		if(expr[i] == '(' || expr[i] == '{' || expr[i] == '['){
				push(expr[i]);
		}
		else if(expr[i] == ')' || expr[i]==']' || expr[i] == '}'){
			if(expr[i] == ')'){
				if(stack[top] == '('){
						pop();
					}
				else{
					printf("\nUnbalanced \n");
					break;
				}
			}
			if(expr[i] == '}'){
				if(stack[top] == '{'){
						pop();
					}
				else{
					printf("\nUnbalanced \n");
					break;
				}
			}
			if(expr[i] == ']'){
				if(stack[top] == '['){
						pop();
					}
				else{
					printf("\nUnbalanced \n");
					break;
				}
			}

		}

	}
	if(top == -1){
		printf("Balanced");
	}
}
void main(){
	balancing_parathesis();
}

