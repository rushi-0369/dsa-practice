#include <stdio.h>
#include <stdlib.h>
//select minimum and swap
int selectionSort(int* a, int n){
    int i, j, min;
    for(i = 0; i <= n-2; i++){
        min = i;
        for(j = i; j <= n-1; j++){
            if(a[min] > a[j]){
                min = j;
            }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
        }
    }
}
void customPrint(const char* message){
    printf("%s", message);
}

int* createMemory(int n)
{   
    int* ptr;
    ptr = (int*)malloc(n*sizeof(int));
    if (ptr == NULL){
        printf("Memory allocation failed!");
        exit(1);
    }
    return ptr;
}

int inputArray(int* a, int n){
    int i;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    return 0;
}

int input(){
    int value;
    scanf("%d", &value);
    return value;
}
int procedure(){
    int* a;
    int n, i;
    customPrint("Enter size of array:\n");
    n = input();
    a = createMemory(n);
    customPrint("Enter array elements:\n");
    inputArray(a, n);
    selectionSort(a, n);
    customPrint("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    customPrint("\n");
    free(a);
    return 0;
}

int main(){
    procedure();
}



