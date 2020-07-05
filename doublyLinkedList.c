#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head=NULL;

// create a doubly linked lit
void createDLL(int A[] , int n)
{
    struct node *newNode , *p;
    int i;
    if(head==NULL){
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = A[0];
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;

    }
    p = head;
    for(i=1;i<n;i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = A[i];
        p->next = newNode;
        newNode->prev = p;
        newNode->next = NULL;
        p = newNode;


    }
}

void Display(struct node *p)
{
    struct node *q;
    if(head==NULL){
        printf("Linked list is empty\n");
        return ;
    }

    while(p!=NULL){
        printf("%d\n",p->data);
        p = p->next;
    }
}

//Insertion operation
/*
//insert an element in DLL in beginning
void insertAtBeginning(int item)
{
    struct node *newNode ;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    if(head==NULL){
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
        return ;

    }
    newNode->next = head;
    head->prev = newNode;
    newNode->prev = NULL;
    head = newNode;
}

//insert at End
void insertAtEnd(int item)
{
    struct node *newNode , *p;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    if(head==NULL){
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;

    }
    p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = newNode;
    newNode->prev = p;
    newNode->next = NULL;
    p = newNode;

}

//insert at given position
void insertAtMiddle(int item , int pos)
{
    struct node *newNode , *p,*q;
    int i;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    if(head==NULL && pos == 1){
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;

    }

    if(head==NULL && pos != 1){
        printf("insertion is not possible\n");
        return ;

    }
    if(head!=NULL && pos==1){
        insertAtBeginning(item);
        return ;
    }
    p = head;
    q = NULL;
    for(i=2;i<=pos;i++){
            q = p;
            p = p->next;
            if(q->next==NULL){
                printf("Insertion is not possible\n");
                return ;
            }

    }
    q->next = newNode;
    newNode->prev = q;
    newNode->next = p;
    p->prev = newNode;

}
*/

// Deletion operation
/*
// delete at beginning

int deleteAtBeginning(struct node *first)
{
    int value;
    struct node *p , *q;
    if(head==NULL){
        printf("Deletion is not possible\n");
        return 0;
    }
    p = first;
    value = p->data;
    head = head->next;
    head->prev = NULL;
    free(p);
    return value;
}

//delete at end

int deleteAtEnd(struct node *first)
{
    int value;
    struct node *p , *q;
    if(head==NULL){
        printf("Deletion is not possible\n");
        return 0;
    }
    p = first;
    q = NULL;
    while(p->next!=NULL){
        q = p;
        p = p->next;
    }
    value = p->data;
    q->next = NULL;
    free(p);
    return value;

}

//delete at middle
int deleteAtMiddle(struct node *first , int pos)
{
    int value , i;
    struct node *p , *q;
    if(head==NULL && pos !=1){
        printf("Deletion is not possible\n");
        return 0;
    }
    if(head!=NULL && pos == 1){
        value = deleteAtBeginning(first);
        return value;
    }

    p = first;
    for(i=2;i<pos-1;i++){
        //q = p;
        p = p->next;
        if(p==NULL){
            printf("Deletion is not possible at this position\n ");
            return 0;
        }
    }
    value = p->data;
    p->prev->next = p->next->prev;
    p->next->prev = p->prev->next;
    free(p);
    return value;

}
*/

// reverse the doubly linked list
void reverseDLL(struct node *first)
{
    struct node *p , *temp;
    if(head==NULL){
        printf("Linked list is empty\n");
        return ;
    }
    p = first;
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p!=NULL && p->next ==NULL){
            head= p;
        }
    }
}

//main function
int main()
{
    int A[] = {3,6,7,9,10,12,15};
    int n = sizeof(A)/sizeof(A[0]);
    createDLL(A,n);
    Display(head);
    printf("\n");
    reverseDLL(head);
    Display(head);



    return 0;
}


