#include <stdio.h>
#define TRUE 1 
#define FALSE 0
#define max 100

int cQueue[max];
int frant=-1;
int rear=-1;

int isFull()
{
   if((rear+1)%max==frant)
     return TRUE;
   else
     return FALSE; 
}

int isEmpty()
{
    if(frant==-1)
    {
        return TRUE;
    }
    else{
        return FALSE;
    }
}

 void insert(int value)
 {
     if(isFull()==TRUE){
         printf("Circular queue is full\n");
         return ;
     }
     
     if(isEmpty()==TRUE){
         frant=0;
     }
     rear=(rear+1)%max;
     cQueue[rear]=value;
     
 }
 
 void display()
 {
     int i;
     if(isEmpty()==TRUE){
         printf("circular queue is empty\n");
         return;
     }
     
     for(i=frant;i!=rear;i=(i+1)%max){
         printf("%d\t",cQueue[i]);
     }
 }
 
 int delete()
 {
     int value;
     if(isEmpty()==TRUE){
         printf("circular queue is empty\n");
         return ;
     }
     else if(frant==rear){
         value=cQueue[frant];
         rear=frant=-1;
     }
     value=cQueue[frant];
     frant=(frant+1)%max;
     return value;
 }
 
 int main()
 {
     insert(4);
     insert(5);
     insert(6);
     insert(7);
     
     printf("\n");
     printf("%d\t",delete());
     printf("%d\t",delete());
     printf("\n");
     display();
     insert(88);
     insert(33);
     printf("\n");
     display();
     return 0;
 }