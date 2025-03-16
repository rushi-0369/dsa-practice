#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *a;
};

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
} 

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr, int value){
    if(isFull(ptr)){
        printf("Stack Overflow! CAnnot push %d to the stack\n", value);
    }
    else{
        ptr->top++;
        ptr->a[ptr->top] = value;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int value = ptr->a[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(struct stack *ptr, int i){
    if(ptr->top-i+1 < 0){
        printf("Not a valid position");
        return -1;
    }
    else{
        return ptr->a[ptr->top-i+1];
    }
}

int size(struct stack *ptr){
    return ptr->top+1;
}

int stackTop(struct stack *ptr){
    return ptr->a[ptr->top];
}

int stackBottom(struct stack *ptr){
    return ptr->a[0];
}

int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->a = (int*)malloc(sp->size*sizeof(int));
    push(sp,6);
    printf("%d",size(sp));
}