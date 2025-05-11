#include<stdio.h>

int stack[100],choice,top,n,x,i;

void push(void);
void pop(void);
void display(void);

void main(){
    top = -1;
    printf("\n Enter the size of the Stack [MAX=100] : ");
    scanf("%d",&n);
    printf("\n STACK OPERATIONS USING ARRAY");
    printf("\n-----------------------------");
    printf("\n 1.Push \n 2.Pop \n 3.Display \n 4. Exit");
    do{
        printf("\n Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n Exit Point");
                break;
            default:
                printf("\n Enter a valid choice [1/2/3/4]");
        }
    }while(choice != 4);
}

void push(){
    if(top>n-1){
        printf("\n Stack OverFlow");
    }
    else{
        printf("\n Enter a value to be pushed: ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}

void pop(){
    if(top<=-1){
        printf("\n Stack UnderFlow");
    }
    else{
        printf("\n The popped element is %d",stack[top]);
        top--;
    }
}

void display(){
    if(top>=0){
        printf("\n The elements in the Stack are:");
        for(i=top;i>=0;i--){
            printf("\n %d",stack[i]);
        }
        printf("\n Enter the next choice");
    }
    else{
        printf("\n The Stack is empty!!!");
    }
}