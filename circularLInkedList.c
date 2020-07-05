#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} ;
struct node *head ;

void createEmptyCLL()
{
    head = NULL;
}


// create circular linked list
void createCLL(int A[] , int n)
{
    struct node *newNode , *p;
    int i;
    if(head==NULL){
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = A[0];
        head = newNode;
        newNode->next = head;


    }
    p = head;
    for(i=1;i<n;i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = A[i];
        p->next = newNode;
        newNode->next = head;
        p = newNode;

    }


}

// Display a circular linked list
void Display(struct node *head)
{
    struct node *p;
    if(head==NULL){
        printf("Linked list is empty\n");
        return ;
    }
    p = head;
    do {
        printf("%d\n",p->data);
        p = p->next;
    }while(p!=head);
}

// Display circular linked list using recursion
/*
void DisplayR(struct node *p)
{
    static int temp = 0;
    //struct node *p;
    if(head==NULL){
        printf("Linked list is empty\n");
        return ;
    }
    if(p!=head || temp == 0){
        temp = 1;
        printf("%d\n",p->data);
        DisplayR(p->next);
    }
    temp = 0;
}
*/

// insert at the beginning in circular linked list
/*
void insertAtBeginning(int item)
{
    struct node *newNode , *p;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    if(head==NULL){

        head = newNode;
        newNode->next = NULL;
        head->next = head;
        return ;

    }
    p = head;
    do{
        p = p->next;
    }while(p->next!=head);

    newNode->next = head;
    p->next = newNode;
    head = newNode;

}

// insert at middle
void insertAtMiddle(int item , int pos)
{
    struct node *newNode , *p;
    int i;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    if(head==NULL ){

        head = newNode;
        newNode->next = NULL;
        head->next = head;
        return ;

    }
    if(head!=NULL && pos==1){
        insertAtBeginning(item);
        return ;
    }
    p = head;
    for(i=2;i<pos;i++){
        p = p->next;
        if(p==head){
            printf("Insertion is not possible\n");
            return ;
        }
    }
    newNode->next = p->next;
    p->next = newNode;

}
*/

// Deletion in circular linked list
// At the beginning
int deleteAtBeginning(struct node *p)
{
    int value;
    struct node *t , *q;
    if(head==NULL){
        printf("Deletion is not possible because linked list is empty\n");
        return 0;
    }
    t = p;
    q = p;
    while(t!=head){
        t = t->next;
    }
    value = q->data;
    p = p->next;
    t->next = p;
    free(q);
    return value;

}

//delete at end
int deleteAtEnd(struct node *p)
{
    int value;
    struct node *t , *q;
    if(head==NULL){
        printf("Deletion is not possible because linked list is empty\n");
        return 0;
    }
    t = p;
    q = NULL;

    do{
        q = t;
         t = t->next;
    }while(t->next!=p);

    value = t->data;
    q->next = p;
    free(t);
    return value;


}

// delete at middle
int deleteAtMiddle(struct node *p , int pos)
{
    int value , i;
    struct node *t , *q;
    if(head==NULL){
        printf("Deletion is not possible because linked list is empty\n");
        return 0;
    }
    if(head!=NULL && pos == 1){
        value = deleteAtBeginning(p);
        return value;

    }
    t = p;
    q = NULL;
    for(i=2;i<=pos;i++){
        q = t;
        t = t->next;
        if(q->next==p){
            printf("deletion is not possible\n");
            return 0;
        }
    }
    value = t->data;
    q->next = t->next;
    q = t->next;
    free(t);
    return value;
}
//main function
int main()
{
    int A[] = {3,8,9,12};
    int n = sizeof(A)/sizeof(A[0]);
    createEmptyCLL();
    createCLL(A,n);
    Display(head);

    printf("\n");
    printf("%d\n",deleteAtMiddle(head,4));

    return 0;
}
