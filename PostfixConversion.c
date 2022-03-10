#include<stdio.h>
#include<string.h>
#define MAX 10
char stack[MAX];
int top = -1;

void push(char x){
    if (top == MAX)
    {
        printf("Stack overflow error!!");
    }else{
        stack[++top] = x;
    }

}
char pop(){
    char x;
    if (top == -1)
    {
        printf("Stack underflow error!!");

    }else{
        x = stack[top];
        top--;
    }
    return x;
}

int prority(char x){
    if(x == '('){
        return 0;
    }
    if(x == '+' || x == '-' ){
        return 1;
    }
    if(x == '*' || x == '/'){
        return 2;
    }
}

void main(){

    char expr[20],t;
    printf("Enter infix expression: ");
    scanf("%s",expr);

    for(int i = 0 ; i < strlen(expr); i++){
        if(isdigit(expr[i])){
            printf("%c ",expr[i]);
        }
        else if(expr[i] == '('){
            push(expr[i]);
        }
        else if(expr[i] == ')'){
            while(stack[top] != '('){
                printf("%c ",pop());
            }
        }


        else{

            while(prority(stack[top])>= prority(expr[i])){
                printf("%c ",pop());
                push(expr[i]);
            }
        }
        while(top != -1){
            printf("%c ",pop());
        }
    }

}
