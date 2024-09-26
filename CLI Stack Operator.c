#include<stdio.h>
#define MAX 5   //dont use semicolon here
int stack_arr[MAX];
int top = -1;

int isFull(){
    if (top == MAX - 1)
        return 1;
    else 
        return 0;
}

int isEmpty(){
    if (top == -1)
    return 1;
    else 
    return 0;
}

void push(int data){
    if(isFull()){
        printf("Stack Overflow!! %d cant be pushed \n",data);
        return;
    }
    top++;
    stack_arr[top] = data;
}

int pop(){
    if (isEmpty()){
        printf("Stack is Empty!!\n");
        exit(1);
    }
    int value = stack_arr[top];
    top--;
    return value;
}

int peek(){
    if (isEmpty()){
        printf("Stack is Empty!!\n");
        exit(1);
    }
    int value = stack_arr[top];
    return value;
}

void print(){
    if (isEmpty()){
        printf("Stack is Empty!\n");
        return;
    }
    printf("The elements of the stack are: ");
    for (int i=top;i>=0;i--){
        printf("%d ",stack_arr[i]);
    }
}

int main(){
    int choice, data;
    while(1){
    printf("\n");
    printf("1. Push an element \n2. Pop an element \n3. Print the top element\n4. Print all the elements \n5. Quit\n");
    printf("Enter the Your choice: ");
    scanf("%d",&choice);
    printf("\n");
    switch(choice){
        case 1: printf("Enter the element to be pushed: ");
        scanf("%d",&data);
        push(data);
        break;
        case 2: printf("The Deleted element is %d",pop());
        break;
        case 3: printf("The Top element of the Stack is: %d",peek());
        break;
        case 4:print();
        break;
        case 5: exit(1);
        break;
        default: printf("INVALID ENTRY!! Try again!");
    }
    }
    return 0;
}