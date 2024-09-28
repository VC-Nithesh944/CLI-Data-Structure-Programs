#include<stdio.h>
#include<string.h>
#define Max 100

char stack[Max],infix[Max],postfix[Max];
int top = -1;

void push(char);
char pop();
int isEmpty();
int space(char);
void print();
int precedence(char);
void IntoPost();

int main(){
    printf("Enter the infix expression: ");
    gets(infix);

    IntoPost();

    printf("\nThe postfix expression is: ");
    int i = 0;
    while (postfix[i]!= '\0'){
        printf("%c",postfix[i++]);
    }
}
void IntoPost(){
    int i, j=0;
    char symbol,next;
    for (i=0;i<strlen(infix);i++){
        symbol = infix[i];
        if (!space(symbol)){
            switch(symbol){
                case '(': push(symbol);
                break;
                case ')': while((next=pop()) != '('){
                    postfix[j++] = next;
                }
                break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^': while(!isEmpty() && precedence(stack[top]) >= precedence(symbol)){
                    postfix[j++] = pop() ;
                }
                push(symbol); break;
                default:
                postfix[j++] = symbol;
            }
        }
    }
    while(!isEmpty()){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
char pop(){
    if (isEmpty()){
        printf("Stack is Empty!!\n");
        exit(1);
    }
    return stack[top--];
}
void push(char data){
    top++;
    stack[top] = data;
}
int isEmpty(){
    if (top == -1)
    return 1;
    else 
    return 0;
}
int space(char s){
    if (s == ' ' || s== '\t')
    return 1;
    else 
    return 0;
}
int precedence(char symbol){
    switch (symbol){
        case '^': return 3;
        break;
        case '/':
        case '*':return 2;
        break;
        case '+':
        case '-':return 1;
        break;
        default: return 0;
    }
}
