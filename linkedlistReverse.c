#include <stdio.h>

#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

int main()
{
    insertNodeAtBegining(2);
    insertNodeAtBegining(3);
    insertNodeAtBegining(4);
    insertNodeAtBegining(5);
    insertNodeAtBegining(6);
    insertNodeAtBegining(7);
    traverse();
    reverse();
    traverse();
    
    
    
    return 0;
    
    
}

 void insertNodeAtBegining(int value){
     struct node *newNode;
     newNode =malloc(sizeof(struct node));
     newNode->data=value;
     if(head==NULL){
         head=newNode;
         newNode->next=NULL;
         return;
     }
     
     newNode->next=head;
     head=newNode;
     
 }
 
 void traverse()
{
    struct node *t;
    if(head==NULL)
    {
        printf("Error!");
        return;
    }
    t=head;
    while(t->next!=NULL){
        printf("%d \t",t->data);
        t=t->next;
    }
}

void reverse(){
    struct node *t1,*t2,*t3;
    if(head->next==NULL){
        return;
    }
    t1=head;
    t2=t1->next;
    t3= t2->next;
    t1->next=NULL;
    t2->next=t1;
     while(t3!=NULL){
         t1=t2;
         t2=t3;
         t2->next=t1;
     }
    head=t2;
    
}
