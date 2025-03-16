#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;
    int frontInd;
    int backInd;
    int *a;
};

int isFull(struct circularQueue *ptr){
    if((ptr->backInd + 1)%ptr->size == ptr->frontInd){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct circularQueue *ptr){
    if(ptr->backInd == ptr->frontInd){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct circularQueue *ptr, int value){
    if(isFull(ptr)){
        printf("Queue Overflow");
    }
    else{
        ptr->backInd = (ptr->backInd + 1)%ptr->size;
        ptr->a[ptr->backInd] = value;
    }
}

int dequeue(struct circularQueue *ptr){
    int value = -1;
    if(isEmpty(ptr)){
        printf("Empty queue");
    }
    else{
        ptr->frontInd = (ptr->frontInd+1)%ptr->size;
        value = ptr->a[ptr->frontInd];
    }
    return value;
}
int peek(struct circularQueue *ptr, int i){
    if(ptr->backInd-i+1 < 0){
        printf("Not a valid position");
        return -1;
    }
    else{
        return ptr->a[ptr->backInd-i+1];
    }
}

int size(struct circularQueue *ptr){
    return ptr->backInd+1;
}

int queueTop(struct circularQueue *ptr){
    return ptr->a[ptr->backInd];
}

int queueBottom(struct circularQueue *ptr){
    return ptr->a[0];
}

int main(){
    struct circularQueue *q = (struct circularQueue*)malloc(sizeof(struct circularQueue));
    q->size = 10;
    q->frontInd = q->backInd = 0;
    q->a = (int*)malloc(q->size * sizeof(int));
}