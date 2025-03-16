#include <stdio.h>
#include <stdlib.h>
//take an element and place it in its correct order 
int insertionSort(int* a, int n){
    int i, j, temp;
    for(i = 0;i <= n-1; i++){
        j = i;
        while(j > 0 && a[j-1] > a[j]){
            temp = a[j-1];
            a[j-1] = a[j];
            a[j] = temp;
            j--;
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
    insertionSort(a, n);
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