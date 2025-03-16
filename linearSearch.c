#include<stdio.h>
#include<stdlib.h>

int* allocateMemory(int n){
    int *ptr = NULL;
    ptr=(int*)malloc(n*sizeof(int));
    return ptr;
}

int input(){
    int n=-1;
    scanf("%d", &n);
    return n;
}

void inputArray(int* a, int n){
    for(int i=0;i<n;i++){
        printf("Enter the value at %d:\n",i+1);
        scanf("%d", &a[i]);
    }
}

int customPrint(const char* message){
    printf("%s", message);
}

int linearSearch(int* a, int n, int key){
    for(int i=0;i<n;i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}

int procedure(){
    int* a;
    int n,key,res;
    customPrint("Enter the size of array:\n");
    n=input();
    a=allocateMemory(n);
    inputArray(a,n);
    customPrint("Enter the key to search:\n");
    key=input();
    res=linearSearch(a,n,key);
    printf("%d is found at index %d.",key,res);
}

int main(){
    procedure();
}