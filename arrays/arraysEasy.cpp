#include <bits/stdc++.h>
using namespace std;
//Largest element
//BFA->sort and arr[n-1]
int findLargestElement(vector <int>&a, int n){
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    return max;
}

// second Largest
//BFA->sort
int findSecondLargestElementBFA(vector <int>&a, int n){
    sort(a.begin(), a.end());
    int largest = findLargestElement(a,n);
    int secondLargest = -1;
    for(int i = n-2; i >= 0; i++){
        if(a[i] != largest){
            secondLargest = a[i];
            break;
        }
    }
    return secondLargest;
}
//BA
int findSecondLargestElementBA(vector <int>&a, int n){
    int largest = findLargestElement(a,n);
    int slargest = -1;
    for(int i = 0; i < n; i++){
        if(a[i]>slargest && a[i]!=largest){
            slargest = a[i];
        }
    }
    return slargest;
}
//OA
int findSecondLargestElementOA(vector <int>&a, int n){
    int largest = a[0];
    int slargest = -1;
    for(int i = 1; i < n; i++){
        if(a[i] > largest){
            slargest = largest;
            largest = a[i];
        }
        else if(a[i] != largest && a[i] > slargest){
            slargest = a[i];
        }
    }
    return slargest;
}
int findSecondSmallestElementOA(vector <int>&a, int n){
    int smallest = a[0];
    int ssmallest = __INT_MAX__;
    for(int i = 1; i < n; i++){
        if(a[i] < smallest){
            ssmallest = smallest;
            smallest = a[i];
        }
        else if(a[i] != smallest && a[i] < ssmallest){
            ssmallest = a[i];
        }
    }
    return ssmallest;
}

//check is an array is sorted
//OA
int isSortedOA(vector <int>&a, int n){
    for(int i = 1; i < n; i++){
        if(a[i] >= a[i-1]){

        }
        else{
            return 0;
        }
    }
    return 1;
}

//remove duplicates from and array and return no.of non duplicate elements
//BFA-> set data structure set.insert, set.size
//OA
int removeDuplicates(vector <int>&a, int n){
    int i = 0;
    for(int j = 1; j < n; j++){
        if(a[i] != a[j]){
            a[i+1] = a[j];
            i++;
        }
    }
    return i+1;
}

//Left Rotate the Array by One
//BFA->create another array and move by one place
//OA
int leftRotateByOne(vector <int>&a, int n){
    int temp = a[0];
    for(int i = 1; i < n-1; i++){
       a[i-1] = a[i];
    }
    a[n-1] = temp;
}

//Rotate array by d elements
//BFA
int leftRotateByd(vector <int>&a, int n, int d){
    if(n==0) return;
    d = d % n;
    if(d>n) return;
    int temp[d];
    for(int i = 0; i < d; i++){
        temp[i] = a[i];
    }
    for(int i = d; i < n; i++){
        a[i-d] = a[i];
    }
    // int j = 0;
    // for(int i = n-d; i < n; i++){
    //     a[i] = temp[j];
    //     j++;
    // }
    for(int i = n-d; i < n; i++){
        a[i] = temp[i-(n-d)];
    }
}
int rightRotateByd(vector <int>&a, int n, int d){
    if(n==0) return;
    d = d % n;
    if(d>n) return;
    int temp[d];
    for(int i = n-d ;i < n; i++){
        temp[i - (n - d)] = a[i];
    }
    for(int i = n-d-1; i>=0; i++){
        a[i+d] = a[i];
    }
    for(int i = 0; i < d; i++){
        a[i] = temp[i];
    }
}
//OA
void reverse(vector <int>&a, int start, int end){
    while(start <= end){
        swap(a[start],a[end]);
        start++;
        end--;
    }
}
void leftRotateBydOA(vector <int>&a, int n, int d){
    reverse(a, 0, d-1);
    reverse(a, d , n-1);
    reverse(a, 0, n-1);
}
void rightRotateBydOA(vector <int>&a, int n, int d){
    reverse(a, 0, n-d-1);
    reverse(a, n-d, n-1);
    reverse(a, 0, n-1);
}

//move zeroes to end
//BFA
void moveZeroesToEndBFA(vector <int>&a, int n){
    int temp[n];
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i]!=0){
            temp[count] = a[i];
            count++; 
        }
    }
    for(int i = count; i < n; i++){
        temp[i] = 0;
    }
    for(int i = 0; i < n; i++){
        a[i] = temp[i];
    }
}

void moveZeroesToEndOA(vector <int>&a, int n){
    int j = -1;
    for(int i = 0; i < n; i++){
        if(a[i]==0){
            j = i;
            break;
        }
    }
    for(int i = j+1; i < n; i++){
        if(a[i] != 0){
            swap(a[i], a[j]);
            j++;
        }
    }
}

int linearSearch(vector <int>&a, int n, int key){
    for(int i = 0; i < n; i++){
        if(a[i] == key){
            return i;
        }
    }
    return -1;
}

//union,intersection  XX
//Missing number
//BFA-> using linear search
int missingNumberBFA(vector <int>&a, int n){
    int N = n+1;
    for(int i = 1; i <= N; i++){
        int flag = 0;
        for(int j = 0; j < n; j++){
            if(a[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }
    return -1;
}

int missingNumberBA(vector <int>&a, int n){
    int N = n+1;
    int hash[N+1]= {0};
    for(int i = 0; i < n; i++){
        hash[a[i]]++;
    }
    for(int i = 1; i <= N; i++){
        if(hash[i] == 0){
            return i;
        }
    }
    return -1;
}

int missingNumberOA1(vector <int>&a, int n){
    int N = n+1;
    int expectedSum = (N*(N+1)) / 2;
    int actualSum = 0;
    for(int i = 0; i < n; i++){
        actualSum += a[i];
    }
    return expectedSum - actualSum;
}

int missingNumberOA2(vector <int>&a, int n){
    int N = n+1;
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 1; i <= N; i++){
        xor1 = xor1 ^ i;
    }
    for(int i = 0; i < n; i++){
        xor2 = xor2 ^ a[i];
    }
    return xor1 ^ xor2;
}
int missingNumberOA3(vector <int>&a, int n){
    int N = n+1;
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0; i < n; i++){
        xor2 = xor2^a[i];
        xor1 = xor1^i+1;
    }
    xor1 = xor1^N;
    return xor1^xor2;
}


//Maximum Consecutive Ones
int findMaximumConsecutiveOnes(vector <int>&a, int n){
    int count = 0;
    int maxi = 0;
    for(int i = 0; i < n; i++){
        if(a[i]==1){
            count++;
            if(count > maxi){
                maxi = count;
            }
        }
        else{
            count = 0;
        }
    }
    return maxi;
}

//number that appears once, and other numbers twice.
//BFA
int singleNumberBFA(vector <int>&a, int n){
    for(int i = 0; i < n; i++){
        int num = a[i];
        int count = 0;
        for(int j = 0; j < n; j++){
            if(a[j] == num){
                count++;
            }
        }
        if(count==1){
            return num;
        }
    }
    return -1;
}
//BA
int singleNumberBA(vector <int>&a, int n){
    int max = findLargestElement(a,n);
    int hash[max+1] = {0};
    for(int i = 0; i < n; i++){
        hash[a[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(hash[a[i]]==1){
            return a[i];
        }
    }
    return -1;
}
//OA
int singleNumberOA(vector <int>&a, int n){
    int xorr = 0;
    for(int i = 0; i < n; i++){
        xorr = xorr ^ a[i];
    }
    return xorr;
}

//Longest subarray with sum k
//contiguous part of the array with sum k
//return the longest length
int longestSubarrayWithSumK(vector <int>&a, int n, int k){
    int len = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum = sum + a[j];
            if(sum==k){
                if(len<j-i+1){
                    len = j-i+1;
                }
            }
        }
    }
    return len;
}
//BA and OA XX