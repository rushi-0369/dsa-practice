#include<bits/stdc++.h>
using namespace std;

int binarySearchIterative(vector<int>& a, int tar){
    int n = a.size();
    int st = 0;
    int end = n-1;
    while(st <= end){
        int mid = st + (end-st)/2;
        if(tar > a[mid]){
            st = mid+1;
        }
        else if(tar < a[mid]){
            end = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int binarySearchRecursive(vector<int>& a, int tar, int st, int end){
    if(st <= end){
        int mid = st + (end - st)/2;
        if(tar > a[mid]){
            binarySearchRecursive(a, tar, mid+1, end);
        }
        else if(tar < a[mid]){
            binarySearchRecursive(a, tar, st, mid-1);
        }
        else{
            return mid;
        }
    }
    return -1;
}

//Lower Bound lb = lower_bound(a.begin(), a.end(), tar)-a.begin();
int lowerBound(vector<int>& a, int tar){
    int start = 0;
    int end = a.size() - 1;
    int ans = a.size();
    while(start <= end){
        int mid = start + (end  - start)/2;
        if(a[mid] >= tar){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid +1;
        }
    }
    return ans;
}
//upper bound
int upperBound(vector<int>& a, int tar){
    int start = 0;
    int end = a.size() - 1;
    int ans = a.size();
    while(start <= end){
        int mid = start + (end  - start)/2;
        if(a[mid] > tar){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid +1;
        }
    }
    return ans;
}
//Search insert position
int searchInsert(vector<int>& a, int tar){
    int start = 0;
    int end = a.size() - 1;
    int ans = a.size();
    while(start <= end){
        int mid = start + (end  - start)/2;
        if(a[mid] >= tar){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid +1;
        }
    }
    return ans;
}
//first and last occurence
vector<int> searchRange1(vector<int>& nums, int target) {
    int n = nums.size();
    int lb = lowerBound(nums, target);
    if(lb == n || nums[lb] != target){
        return {-1, -1};
    }
    return {lb, upperBound(nums, target)-1};
}
//2
int firstfun(vector<int>& a, int n, int target){
    int start = 0;
    int end = n - 1;
    int first = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(a[mid] == target){
            first = mid;
            end = mid - 1; 
        }
        else if(a[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return first;
}
int lastfun(vector<int>& a, int n, int target){
    int start = 0;
    int end = n - 1;
    int last = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(a[mid] == target){
            last = mid;
            start = mid + 1; 
        }
        else if(a[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return last;
}
vector<int> searchRange2(vector<int>& nums, int target) {
    int n = nums.size();
    int f = firstfun(nums, n, target);
    if(f == -1) return {-1, -1};
    int l = lastfun(nums, n, target);
    return {f, l};
}
//count
int count(vector<int>& a, int n, int target){
    vector<int> ans = searchRange2(a, target);
    if(ans[0] == -1) return -1;
    return ans[1] - ans[0] + 1;
}

//Search in Rotated Sorted Array [3, 4, 5, 6, 7, 0, 1, 2] tar = 0
int searchRotatedSorted(vector<int>& a, int tar){
    int st = 0;
    int end = a.size() - 1;
    while(st <= end){
        int mid = st + (end-st)/2;
        if(a[mid] == tar){
            return mid;
        }
        if(a[st] <= a[mid]){ //left sorted
            if(a[st] <= tar && tar <= a[mid]){ //left bs
                end = mid-1;
            }
            else{
                st = mid + 1; //right bs
            }
        } 
        else{
            if(a[mid] <= tar && tar <= a[end]){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    return -1;
}
//duplicates
int searchRotatedSorted(vector<int>& a, int tar){
    int st = 0;
    int end = a.size() - 1;
    while(st <= end){
        int mid = st + (end-st)/2;
        if(a[mid] == tar){
            return true;
        }
        if(a[st] == a[mid] && a[mid] == a[end]){
            st++;
            end--;
            continue;
        }
        else if(a[st] <= a[mid]){ //left sorted
            if(a[st] <= tar && tar < a[mid]){ //left bs
                end = mid-1;
            }
            else{
                st = mid + 1; //right bs
            }
        } 
        else{
            if(a[mid] <= tar && tar < a[end]){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    return false;
}
//minimum in rotated sorted array
int findMin(vector<int>& a){
    int start = 0, end = a.size() - 1;
    int ans = INT_MAX;
    while(start <= end){
        if(a[start] <= a[end]){
            ans = min(ans, a[start]);
            break;
        }
        int mid = start + (end - start)/2;
        if(a[start] <= a[mid]){
            ans = min(ans, a[start]);
            start = mid + 1; 
        }
        else{
            ans = min(ans, a[mid]);
            end = mid - 1;
        }
    }
    return ans;
}
int findKRotation(vector<int>& a){
    int start = 0, end = a.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while(start <= end){
        if(a[start] <= a[end]){
            if(a[start] < ans){
                index = start;
                ans = a[start];
            }
            break;
        }
        int mid = start + (end - start)/2;
        if(a[start] <= a[mid]){
            if(a[start] < ans){
                index = start;
                ans = a[start];
            }
            start = mid + 1; 
        }
        else{
            if(a[mid] < ans){
                index = mid;
                ans = a[mid];
            }
            end = mid - 1;
        }
    }
    return index;
}
//single element in sorted array
//peak
int peakInMountain(vector<int>& a){
    int st = 1;
    int end = a.size()-2;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(a[mid-1] < a[mid] && a[mid] > a[mid+1]){
            return mid;
        }
        if(a[mid-1] < a[mid]){
            st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}

int singleElementBFA1(vector<int> &a){
    if(a.size()==1) return a[0];
    for(int i = 0; i < a.size(); i++){
        if(i==0){
            if(a[i] != a[i+1]){
                return a[i];
            }
        }
        else if(i == a.size()-1){
            if(a[i] != a[i-1]){
                return a[i];
            }
        }
        else{
            if(a[i] != a[i+1] && a[i] != a[i-1]){
                return a[i];
            }
        }
    }
    return -1;
}

int singleElement(vector<int> &a){
    int st = 0;
    int end = a.size() - 1;
    if(a.size() == 1) return a[0];
    while(st <= end){
        int mid = st + (end-st)/2;
        if(mid == 0 && a[0] != a[1]) return a[mid];
        if(mid == a.size()-1 && a[a.size()-1] != a[a.size()-2]) return a[mid];
        if(a[mid-1]!=a[mid] && a[mid]!=a[mid+1]){
            return a[mid];
        }
        if(mid%2 == 0){
            if(a[mid-1]==a[mid]){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        else{
            if(a[mid-1]==a[mid]){
                st = mid + 1; 
            }
            else{
                end = mid - 1;
            }
        }
    }
    return -1;
}

int bookAllocation(vector<int>& a, int n, int m){
    if(m>n){
        return -1;
    }
    int st = 0;
    int end = 0;
    for(int i = 0; i < n; i++){
        end = end + a[i];
    }
    int ans = -1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(isValid(a, n, m, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            st = mid+1;
        }
    }
    return ans;
}
bool isValid(vector<int>& a, int n, int m, int mid){
    int stu = 1;
    int pages = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > mid){
            return false;
        }
        if(pages + a[i] <= mid){
            pages += a[i];
        }
        else{
            stu++;
            pages = a[i];
        }
    }
    if(stu > m){
        return false;
    }
    else{
        return true;
    }
}