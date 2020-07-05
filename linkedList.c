#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;



// Create a linked list
void create(int *A , int n)
{
    struct node *newNode , *t;
    int i;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = A[0];
    if(head1==NULL){
        head1 = newNode;
        newNode->next = NULL;
    }


    for(i=1;i<n;i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        newNode->next = t;
        newNode = t;
    }
}
//
void create2(int *A , int n)
{
    struct node *newNode , *t;
    int i;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = A[0];
    if(head2==NULL){
        head2 = newNode;
        newNode->next = NULL;
    }


    for(i=1;i<n;i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        newNode->next = t;
        newNode = t;
    }
}

void Display(struct node *p)
{
    if(p==NULL){
        printf("Linked list is Empty\n");
        return ;
    }
    while(p!=NULL){
        printf("%d\n",p->data);
        p = p->next;
    }

}

//Display second linked list
/*
void Display(struct node *p)
{
    if(head2==NULL){
        printf("Linked list is Empty\n");
        return ;
    }
    while(p!=NULL){
        printf("%d\n",p->data);
        p = p->next;
    }

}
*/
// display reverse linked list using recursion
/*
void RDisplay(struct node *p)
{
    if(p!=NULL){
        Display(p->next);
        printf("%d ",p->data);
    }

}

// counting number of node in linked list
void countLLNode(struct node *p)
{
    int temp = 0;
    if(head==NULL){
        printf("Number of node in linked list is %d ",temp);
        return ;
    }
    while(p!=NULL){
        temp++;
        p = p->next;
    }
   printf("Number of node in linked list is %d ",temp);
}

// Sum of all element in linked list
void sumLL(struct node *p)
{
    int sum = 0;
    if(head==NULL){
        printf("Linked list is empty\n");
        return ;
    }

    while(p!=NULL){
        sum += p->data;
        p = p->next;
    }
    printf("the sum of element of linked is : %d",sum);
}

// maximum element in linked list

void maxElementLL(struct node *p)
{
    int max;
    if(head==NULL){
        printf("Linked list is empty\n");
        return ;
    }
    max = -9999;
    while(p!=NULL){
        if(max < p->data){
            max = p->data;

        }
        p= p->next;
    }
    printf("The maximum element is %d ",max);

}

// Searching an element in a linked list
struct node* searchElement( struct node *p , int k)
{
     if(head==NULL){
        printf("Linked list is empty\n");
        return ;
    }
    while(p!=NULL){
        if(p->data == k){
            //printf("Element is found");
            return(p);
        }
        p = p->next;
    }
    //printf("Element is not found\n");
    return NULL;
}
*/

// insert at beginning
/*
struct node* createNewNode(int item)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = NULL;
}
*/
/*
void insertAtBeginning(int item)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;

    if(head==NULL){
        head = newNode;
        newNode->next = NULL;
        return ;
    }
    newNode->next = head;
    head = newNode;


}

//insert at given position
void insertAtMiddle(int item , int pos)
{
    int i;
    struct node *newNode , *p;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;

    if(head==NULL){
        head = newNode;
        newNode->next = NULL;
        return ;
    }
    p = head;
    for(i=2;i<pos;i++){
            if(p==NULL){
                printf("Insertion is not possible at this position\n ");
                return ;
            }
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
}

//insert at end
void insertAtEnd(int item)
{
   struct node *newNode , *p;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;

    if(head==NULL){
        head = newNode;
        newNode->next = NULL;
        return ;
    }
    p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = newNode;
    newNode->next = NULL;
}

// insert an element in sorted linked list
void insertSort(int item)
{
    struct node *newNode , *p1,*p2;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;

    if(head==NULL){
        head = newNode;
        newNode->next = NULL;
        return ;
    }
    p1 = head;
    p2 = NULL;
    while(p1!=NULL){
        if(item < p1->data){
            break;
        }
        p2 = p1;
        p1 = p1->next;
    }
    p2->next = newNode;
    newNode->next = p1;
}

//deleting an element at beginning
int deleteAtBeginning()
{
    int value;
    if(head==NULL){
        printf("Deletion is not possible\n");
        return ;
    }
    value = head->data;
    head = head->next;
    free(head);
    return value;
}

// delete at Middle
int deleteAtMiddle(int pos)
{
    int i,value;
    struct node *p1,*p2;
    if(head==NULL){
        printf("Deletion is not possible\n");
        return 0 ;
    }
    p1 = head;
    p2 = NULL;
    for(i=2;i<pos;i++){
            if(p1==NULL){
                printf("Deletion is not possible at that position\n");
                return 0;
            }
        p2 = p1;
        p1 = p1->next;
    }
    value = p1->data;
    p2->next = p1->next;
    free(p1);
    return value;

}

// deletion at end
int deleteAtEnd()
{
    int value;
    struct node *p1,*p2;
    if(head==NULL){
        printf("Deletion is not possible\n");
        return 0 ;
    }
    p1 = head;
    p2 = NULL;
    while(p1->next!=NULL){
        p2 = p1;
        p1 = p1->next;
    }
    value = p1->data;
    p2->next = NULL;
    free(p1);
    return value;

}
*/

// check weather a linked list is sorted or not
/*
int checkSorted(struct node *p)
{
    int x=-65536;
    if(head==NULL){
        printf("Linked list is empty\n");
        return 0;
    }

     while(p!=NULL)
     {
         if(p->data < x)
            return 0;
        x=p->data;
        p=p->next;
    }
     return 1;
}

// delete duplicate from linked list

void deleteDuplicate(struct node *p1)
{
    struct node *p , *q;
    if(head==NULL){
        printf("Linked list is empty\n");
        return 0;
    }

    p = p1;
    q = p->next;
    while(q!=NULL){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }


}
*/

// Reverse a linked list
/*
void reverseLL(struct node *first)
{
    struct node *p , *q , *r;
    if(head==NULL){
        printf("Linked is empty\n");
        return ;
    }
    p = first;
    q = NULL;
    r = NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;

}

// Reverse linked list using Recursion
void reverseLLR(struct node *q , struct node *p)
{
    if(head==NULL){
        printf("Linked is empty\n");
        return ;
    }
    if(p!=NULL){
        reverseLLR(p,p->next);
        p->next = q;
    }
    else {
        head = q;
    }
}
*/

//concanate two linked list
void concanateLL(struct node *p , struct node *q)
{
    struct node *last;
    if(p==NULL && q==NULL){
        printf("Both linked list are empty\n");
        return ;
    }
    last = p;
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = q;
}

//Merging of Linked list
void mergingLL(struct node *p , struct node *q)
{
    struct node *last;
    if(p==NULL && q==NULL){
        printf("Both linked list are empty\n");
        return ;
    }

    if(p->data < q->data){
        head3 = last = p;
        p = p->next;
        last->next = NULL;
    }
    else {
        head3 = last = q;
        q = q->next;
        last->next = NULL;
    }

    while(p!=NULL && q!=NULL){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;

        }
        else {
                last->next = q;
                last = q;
                q = q->next;
                last->next = NULL;


        }

    }
    if(p!=NULL)
        last->next = p;
    else
        last->next = q;

}
// main function

int main()
{
    struct node *temp = NULL;
    int A[] = {3,5,15,18,19,20};
    int B[] = {4,6,14,17,21,23};
    int n = sizeof(A)/sizeof(A[0]);
    int m = sizeof(B)/sizeof(B[0]);
    //createEmptyLL();
    create(A,n);
    create2(B,m);
    Display(head1);
    //reverseLL(head);
    //reverseLLR(temp,head);
    printf("\n");
    Display(head2);
    //concanateLL(head1 , head2);
    //printf("Concatnation of two string\n");
    mergingLL(head1,head2);
    printf("merging linked list\n");
    Display(head3);


    return 0;
}
