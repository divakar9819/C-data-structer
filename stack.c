#include <stdio.h>
#define max 100
#define TRUE 1
#define FALSE 0


int stack[max];
int top;
int isFull()
{
    if(top==max)
        return TRUE;
    else 
    return FALSE;
}

int isEmpty()
{
    if(top==-1)
       return TRUE;
    else 
       return FALSE;
}

void push(int value)
{
    if(isFull()==TRUE)
    {
        printf("stack is full");
        return;
        
    }
    
    top+=1;
    stack[top]=value;
}

int pop()
{
    int value;
    if(isEmpty()==TRUE)
    {
        printf("stack is empty\n");
        return;
        
    }
    value=stack[top];
    top-=1;
    return value;
}

int peak()
{
    if(isEmpty()==TRUE)
    {
        printf("stack is empty\n");
        return ;
        
    }
    
    return stack[top];
}

int main()
{
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    printf("%d\t",pop());
    printf("%d\t",pop());
    printf("%d\t",peak());
    return 0;
}
    