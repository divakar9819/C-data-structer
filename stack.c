#include<stdio.h>
#include<stdlib.h>

// implementation stack using array
/*
struct stack
{
    int size;
    int top;
    int *s;
};

//create a stack

void create(struct stack *st)
{
    int i;
    printf("Enter the size of stack\n");
    scanf("%d",&st->size);
    st->top = -1;
    st->s = (int*)malloc(st->size*(sizeof(int)));
}

//Display
void Display(struct stack st)
{
    int i;
    if(isEmpty(st)==1){
        printf("Stack underflow\n");
        return ;
    }
    for(i = st.top; i>=0;i--){
        printf("%d\n",st.s[i]);
    }
}


//check if the stack is full or not
int isFull(struct stack st)
{
    if(st.top == st.size-1){
        return 1;
    }
    else {
        return 0;
    }
}

//check if the stack is empty or not
int isEmpty(struct stack st)
{
    if(st.top==-1){
        return 1;
    }
    else {
        return 0;
    }
}



//push element in the stack
void push(struct stack *st , int value)
{
    if(isFull(*st)==1){
            printf("Stack is overflow\n");
          return ;
    }
    st->top ++;
    st->s[st->top] = value;
}

//pop the element from the stack
int pop(struct stack *st)
{
    int value;
    if(isEmpty(*st)==1){
            printf("Stack is underflow\n");
            return ;
    }
    value = st->s[st->top];
    st->top--;
    return value;
}

//peek element

int peek(struct stack *st , int pos)
{
    int value;
    if(isEmpty(*st)==1){
        printf("Stack is underflow\n");
        return 0;
    }
    if(st->top - pos + 1 < 0){
        printf("Invalied position\n");
        return 0;
    }
    value = st->s[st->top - pos + 1];
    return value;

}

int main()
{
    struct stack st;
    create(&st);
    push(&st , 4);
    push(&st , 3);
    push(&st , 2);
    push(&st , 1);
    Display(st);
    printf("\n");
    printf("%d",pop(&st));
    printf("\n");
    printf("%d",peek(&st , 2));

    return 0;
}
*/

// Implementation of stack using linked list

struct node
{
    int data ;
    struct node *next;
};

struct node *head;

void createEmptyStack()
{
    head =NULL;
}

int isFull()
{
    return 0;
}

int isEmpty()
{
    if(head==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

// push element in stack
void push(int value)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    if(isEmpty() == 1){
        newNode->next = NULL;
        head = newNode;
        return ;
    }
    newNode->next = head;
    head = newNode;
}

// pop element from the stack
int pop()
{
    struct node *p;
    int value;
    if(isEmpty() == 1){
        printf("Stack is Empty\n");
        return 0;
    }
    if(head->next == NULL){
            value =head->data;
            free(head);
            head = NULL;
            return value;

    }
    p = head;
    value = p->data;
    head = head->next;
    free(p);
    return value;

}

//peak value
int peak()
{
    int value;
    if(isEmpty()==1){
        printf("Stack is underflow\n");
        return 0;
    }

}

// main function
int main()
{
    createEmptyStack();
    push(4);
    push(3);
    push(2);
    push(1);
    printf("%d\n",pop(head));
    printf("%d\n",pop(head));
    return 0;
}

