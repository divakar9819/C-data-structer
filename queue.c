#include<stdio.h>
#include<stdlib.h>

//implementation of queue using array
/*
struct queue
{
    int size;
    int rear;
    int frant;
    int *Q;
};

//create a queue
void create(struct queue *q , int size)
{
    q->size = size;
    q->Q=(int *)malloc(q->size*sizeof(int));
    q->rear = -1;
    q->frant = -1;
}

//
int isEmptyQueue(struct queue q)
{
    if(q.rear== -1|| q.frant > q.rear){
        return 1;
    }
    else{
        return 0;
    }
}

//
int isFullQueue(struct queue q)
{
    if(q.rear== q.size-1){
        return 1;
    }
    else {
        return 0;
    }
}

//Display function
void Display(struct queue q)
{
    int i;
    if(isEmptyQueue(q)==1){
        printf("Queue is empty\n");
        return ;
    }
    for(i=q.frant +1; i<q.rear + 1;i++){
        printf("%d\n",q.Q[i]);
    }
}

//push or dequeue operation

void enqueue(struct queue *q , int item)
{
    if(isFullQueue(*q) == 1){
        printf("Queue is full\n");
        return ;
    }
    q->rear++;
    q->Q[q->rear] = item;

}

//pop or dequeue operation

int dequeue(struct queue *q)
{
    int value = -1;
    if(isEmptyQueue(*q)==1){
        printf("Queue is empty\n");
        return 0;
    }
    q->frant++;
    value = q->Q[q->frant];
    return value;
}

//main function
int main()
{
   struct queue q;
 create(&q , 4);

 enqueue(&q,10);
 enqueue(&q,20);
 enqueue(&q,30);
 Display(q);
 printf("\n");
 printf("%d ",dequeue(&q));
 printf("%d ",dequeue(&q));

    return 0;
}
*/

//Implementation of circular queue using array

struct cQueue
{
    int size;
    int front;
    int rear;
    int *Q;
};

//create a circular queue
void createCircularQueue(struct cQueue *q , int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int*)malloc(q->size*(sizeof(int)));
}

int isEmpty(struct cQueue *q)
{
    if( q->front == q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct cQueue *q)
{
    if((q->rear+1)%q->size == q->front){
        return 1;
    }
    else {
        return 0;
    }
}

void Display(struct cQueue *q)
{
    int i;
    if(isEmpty(q)==1){
        printf("Queue is empty\n");
        return ;
    }
    i = q->front + 1;
    do{
        printf("%d\n",q->Q[i]);
        i = (i+1)%q->size;
    }while(i!=(q->rear+1)%q->size);
}

//push or enqueue operation
void enqueue(struct cQueue *q , int item)
{
    if(isFull(q)==1){
        printf("Queue is full\n");
        return ;
    }

    q->rear = (q->rear + 1)%q->size;
    q->Q[q->rear] = item;
}

//pop or dequeue operation
int dequeue(struct cQueue *q)
{
    int value;
    if(isEmpty(q)==1){
        printf("Circular Queue is empty\n");
        return 0 ;
    }
    q->front = (q->front + 1)%q->size;
    value = q->Q[q->front];
    return value;
}

//main function
int main()
{
    struct cQueue *q;
    createCircularQueue(&q , 5);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
    Display(&q);
    printf("\n");
   printf("%d\n",dequeue(&q));
   printf("%d\n",dequeue(&q));
   printf("\n");
   enqueue(&q,1);
   enqueue(&q,1);
   Display(&q);

    return 0;
}






