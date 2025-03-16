#include <bits/stdc++.h>
using namespace std;
//BFA->can be used for both varients
int* twoSumBFA(int* a, int n, int target){
    int* result = (int*)malloc(2 * sizeof(int));
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i]+a[j]==target){
                result[1] = j;
                result[0] = i;
                return result;
            }
        }
    }
    result[0] = -1;
    result[1] = -1;
    return result;
}
//BA->hashmap X
int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
//OA->only for varient which return true, false
int twoSumOA(int *a, int n, int target){
    qsort(a, n, sizeof(a[0]), comp);
    int left = 0;
    int right = n-1;
    while(left<right){
        int sum = a[left] + a[right];
        if(sum==target){
            return 1;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    return 0;
}
//Sort an array of 0's, 1's and 2's
//BFA->sort tc=>nlogn sc=>n
//BA
void sortArrayBA(int *a, int n){
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(a[i]==0){
            cnt0++;
        }
        else if(a[i]==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    for(int i = 0; i < cnt0;i++){
        a[i] = 0;
    }
    for(int i = cnt0; i < cnt0+cnt1;i++){
        a[i] = 1;
    }
    for(int i = cnt0+cnt1; i < n;i++){
        a[i] = 2;
    }
}

//OA->Dutch Nationalflag algorithm
void sortArrayOA(int *a, int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(a[mid] == 0){
            int temp = a[low];
            a[low] = a[mid];
            a[mid] = temp;
            low++;
            mid++;
        }
        else if(a[mid]==1){
            mid++;
        } 
        else{
            int temp = a[high];
            a[high] = a[mid];
            a[mid] = temp;
            high--;
        }
    }
}
//TC=>n sc=>1
//Majority element(>n/2 times)
int majorityElementBFA(int* a, int n){
    int cnt = 0;
    for(int i = 0; i < n;i++){
        for(int j = 0;j < n;j++){
            if(a[i] == a[j]){
                cnt++;
            }
        }
        if(cnt>n/2){
            return a[i];
        }
    }
    return -1;
}
//using map
int majorityElementBA(int *a, int n){
    map<int, int> mpp;
    for(int i = 0; i < n;i++){
        mpp[a[i]]++;
    }
    for(auto it : mpp){
        if(it.second > n/2){
            return it.first;
        }
    }
    return -1;
}
//OA->Moore's Voting Algorithm
int majorityElementOA(int *a, int n){
    int cnt = 0;
    int el;
    for(int i = 0; i < n; i++){
        if(cnt==0){
            cnt++;
            el = a[i];
        }
        else if(a[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(a[i]==el){
            cnt1++;
        }
    }
    if(cnt1>n/2){
        return el;
    }
    return -1;
}

int maximumSubarraySumBFA(int* a, int n, int target){
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; i++){
            sum = sum + a[j];
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}