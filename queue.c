#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int frontInd;
    int backInd;
    int *a;
};

int isFull(struct queue *ptr){
    if(ptr->backInd == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue *ptr){
    if(ptr->frontInd == ptr->backInd){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue *ptr,int value){
    if(isFull(ptr)){
        printf("Queue Overflow");
    }
    else{
        ptr->backInd++;
        ptr->a[ptr->backInd] = value;
    }
}

int dequeue(struct queue *ptr){
    if(isEmpty(ptr)){
        printf("No element to dequeue");
    }
    else{
        int value = ptr->a[ptr->frontInd+1];
        ptr->frontInd++;
        return value;
    }
}
int peek(struct queue *ptr, int i){
    if(ptr->backInd-i+1 < 0){
        printf("Not a valid position");
        return -1;
    }
    else{
        return ptr->a[ptr->backInd-i+1];
    }
}

int size(struct queue *ptr){
    return ptr->backInd+1;
}

int queueTop(struct queue *ptr){
    return ptr->a[ptr->backInd];
}

int queueBottom(struct queue *ptr){
    return ptr->a[0];
}
int main(){
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 10;
    q->frontInd = -1;
    q->backInd = -1;
    q->a = (int*)malloc(q->size*sizeof(int));

}