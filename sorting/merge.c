#include <stdio.h>
#include <stdlib.h>

void merge(int* a, int low, int mid, int high){
    int* temp = createMemory(high - low + 1);
    int left = low;
    int right = mid + 1;
    int i = 0;
    while (left <= mid && right <= high){
        if (a[left] <= a[right]){
            temp[i] = a[left];
            left++;
        }
        else{
            temp[i] = a[right];
            right++;
        }
        i++;
    }
    while (left <= mid){
        temp[i] = a[left];
        left++;
        i++;
    }
    while (right <= high){
        temp[i] = a[right];
        right++;
        i++;
    }
    for (i = 0; i < high - low + 1; i++){
        a[low + i] = temp[i];
    }
    free(temp);
}

void mergeSort(int* a, int low, int high){
    if (low >= high){
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
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
    mergeSort(a, 0, n - 1);
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