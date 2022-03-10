#include<stdio.h>
#include<string.h>
#define MAX 10
int stack[MAX];
int top = -1;

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

void postfix_evaluation(){
	char expr[20];
	printf("Enter expression: ");
	scanf("%s",expr);

	int a , b ;
	for(int i = 0 ; i  < strlen(expr); i ++){

		if(isdigit(expr[i])){
			push(expr[i] - 48);
		}

		else{

		   b = pop();
		   a = pop();

		   switch(expr[i]){
			case '+':
				push(a  +  b);
				break;
			case '-':
				push(a  -  b);
				break;
			case '*':
				push(a  *  b);
				break;
			case '/':
				push(a  /  b);
				break;

		   }

		}

	}
	printf("values is %d",pop());
}
void main(){
	postfix_evaluation();
}
