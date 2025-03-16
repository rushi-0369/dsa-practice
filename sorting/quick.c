#include<stdio.h>
#include<stdlib.h>

//pick a pivot and place it in its correct place in the sorted array
//smaller on the left and larger on the right
int partition(int *a, int low, int high){
    int pivot = a[low];
    int i = low;
    int j = high;
    while(i < j){
        while(a[i] <= pivot && i <= high-1){
            i++;
        }
        while(a[j] > pivot && j >= low+1){
            j--;
        }
        if(i<j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int* a, int low, int high){
    if(low<high){
        int partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex-1);
        quickSort(a, partitionIndex+1, high);
    }
}

void customPrint(const char* message){
    printf("%s", message);
}

int* createMemory(int n){   
    int* ptr;
    ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL){
        printf("Memory allocation failed!");
        exit(1);
    }
    return ptr;
}

void inputArray(int* a, int n){
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
}

int input(){
    int value;
    scanf("%d", &value);
    return value;
}

int procedure(){
    int* a;
    int n;
    customPrint("Enter size of array:\n");
    n = input();
    a = createMemory(n);
    customPrint("Enter array elements:\n");
    inputArray(a, n);
    quickSort(a, 0, n - 1);
    customPrint("Sorted array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    customPrint("\n");
    free(a);
    return 0;
}

int main(){
    procedure();
    return 0;
}