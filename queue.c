#include <stdio.h>
#include<conio.h>
#define TRUE 1 
#define FALSE 0
#define max 100

int queue[max];
int frant=-1;
int rear =-1;

 int isFull()
 {
    if(rear==max-1)
      return TRUE;
    else
      return FALSE;
      
 }
 
 int isEmpty()
 {
     if(frant==-1)
       return TRUE;
     else
       return FALSE;
       
 }
 
 void insert(int value)
 {
     if(isFull()==TRUE)
     {
         printf("Queue is full \n");
         return;
     }
     
     if(isEmpty()==TRUE){
         frant=0;
     }
     
     rear+=1;
     queue[rear]=value;
 }
 
 int delete()
 {
     int value;
     if(isEmpty()==TRUE)
     {
         printf("queue is empty \n");
         return ;
         
     }
     value=queue[frant];
     frant+=1;
     return value;
 }
 
 int main()
 {
     insert(3);
     insert(4);
     insert(5); 
     insert(6);
     insert(7);
     insert(8);
     printf("%d\t",delete());
     printf("%d\t",delete());
     printf("%d \t",delete());
     return 0;
 }