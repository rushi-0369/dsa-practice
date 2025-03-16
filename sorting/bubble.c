#include <stdio.h>
#include <stdlib.h>
//push the max to the last vy adjacent swaps
int bubbleSort(int* a, int n){
    int i, j;
    for(i = n-1; i >= 0; i--){
        int flag = 0;
        for(j = 0; j <= i-1; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
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
    bubbleSort(a, n);
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

