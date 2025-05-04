#include <stdio.h>
#include<stdlib.h>
struct queue{
    int f;
    int r;
    int size;
    int *arr;
};
int isFull(struct queue* q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct queue* q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue *q,int val){
   if(isFull(q)){
    printf("overflow");
   } 
   else{
    q->r++;
    q->arr[q->r]=val;
   }
}
int dequeue(struct queue* q){
    int a=-1;
    if(isEmpty(q)){
        printf("underflow case");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}
int main()
{
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->size=100;
    q->f=q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));
    enqueue(q,12);
    enqueue(q,15);
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    return 0;
}