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
//[3, 5, 8, 15, 19] tar = 8 lb = 2 ub = 3
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
int searchInsert(vector<int>& a, int num){
    int start = 0;
    int end = a.size() - 1;
    int ans = a.size();
    while(start <= end){
        int mid = start + (end  - start)/2;
        if(a[mid] >= num){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid +1;
        }
    }
    return ans;
}
//floor and ceil
//floor is the largest element <=x
//ceil is the smallest element >=x
//[3, 4, 4, 7, 8, 10] x=5 ans = 4 7
int findFloor(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] <= x) {
			ans = arr[mid];
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ans;
}
int findCeil(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] >= x) {
			ans = arr[mid];
			high = mid - 1;
		}
		else {
			low = mid + 1;
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

//peak
int peak(vector<int>& a){
    if(a.size()==1) return 0;
    if(a[0] > a[1]) return 0;
    if(a[a.size()-1] > a[a.size()-2]) return a.size()-1;
    int st = 1;
    int end = a.size()-1;
    while(st<=end){
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
//peak in mountain
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

//single element in sorted array
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
//BS on answers
//max of min
//book allocation problem
//m no.of students
//mid is maximum allowed pages
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

//(max)min
//Painters partition problem
//m no.of painters
//mid is maximum allowed time
bool possible(vector<int>& a, int n, int m, int mid){
    int painter = 1;
    long long time = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] > mid){
            return false;
        }
        if(time+a[i] <= mid){
            time = time + a[i];
        }
        else{
            painter++;
            time = a[i];
        }
    }
    if(painter<=m){
        return true;
    }
    return false;
}
int painterPartition(vector<int>& a, int n, int m){
    if(m>n){
        return -1;
    }
    long long st = 0;
    long long end = 0;
    for(int i = 0; i < a.size(); i++){
        if(st < a[i]){
            st = a[i];
        }
        end = end + a[i];
    }
    int ans = -1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(possible(a, n, m, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return ans;
}

//Aggressive Cows => (min)max
//m no.of cows
//mid is minimum allowed distance
bool cowsPossible(vector<int>& a, int m, int mid){
    int cows = 1;
    int lastStallPos = a[0];
    for(int i = 1; i < a.size(); i++){
        if((a[i] - lastStallPos)>=mid){
            cows++;
            lastStallPos = a[i];
        }
        if(cows == m) return true;
    }
    return false;
}
int aggressiveCows(vector<int>& a, int m){
    sort(a.begin(), a.end());
    int st = 1;
    // int maxi=INT_MIN;
    // int mini=INT_MAX;
    // for(int i = 0; i < a.size(); i++){
    //     mini = min(a[i], mini);
    //     maxi = max(a[i], maxi);
    // }
    int end = a[a.size()-1] - a[0] ;
    int ans = -1;
    while(st<=end){
        int mid = st + (end - st)/2;
        if(cowsPossible(a, m, mid)){
            ans = mid;
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int sqrtOfN(int num){
    int st = 1;
    int end = num;
    int ans = -1;
    while(st <= end){
        long long mid = st + (end - st)/2;
        if(mid*mid <= num){
            ans = mid;
            st = mid + 1;
        }
        else{
            end = mid - 1; 
        }
    }
    return ans;//high
}

// int nthRootOfM(int n, int m){

// }

//koko eating bananas
//return the min integer k such that koko can eat all bananas within h hours
//input array of bananas and h hours
//k bananas/hr
//BFA
// for(int i = 1->max(arr)){
//     reqTime = func(arr, i);
//     if(reqTime <= h){
//         return i;
//     }
// }
// func(arr, hourly){
//     totalHrs = 0
//     for(int i = 0->n-1){
//         totalHrs += ceil(arr[i]/hourly;
//     }
//     return totalHrs;
// }
int findLargestElement(vector<int>& a){
    int n = a.size();
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    return max;
}
long long totalHrs(vector<int>& piles, int hourly){
    long long totalhrs = 0;
    int n = piles.size();
    for(int i = 0; i < n; i++){
        totalhrs += ceil((double)(piles[i]) / hourly);
    }
    return totalhrs;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = findLargestElement(piles);
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high-low)/2;
        long long totalhrs = totalHrs(piles, mid);
        if(totalhrs <= h){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans; //low
}

//Minimum no.of days to make M bouquets
//given bloom day array, m no.of bouquets, k adjacent flowers required
//BFA
// if(n < m*k) return -1;
// for(int i = mini->maxi){
//     if(possible(arr, i, m, k)){
//         return i;
//     }
// }
// return -1;
// possible(arr[], day, m, k){
//     cnt = 0;
//     no.ofB = 0
//     for(int i = 0 -> n-1){
//         if(arr[i]<=day){
//             cnt++;
//         }
//         else{
//             no.ofB += (cnt/k);
//             cnt = 0;
//         }
//     }
//     no.ofB += (cnt/k);
//     if(no.ofB >= m) return true;
//     return false;
// }
bool possible(vector<int>& arr, int day, int m, int k){
    int n = arr.size();
    int cnt = 0;
    int noOfB = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] <= day){
            cnt++;
        }
        else{
            noOfB += (cnt/k);
            cnt = 0;
        }
    }
    noOfB += (cnt/k);
    if(noOfB >= m) return true;
    return false;
}
int minDays(vector<int> &arr, int k, int m){;
    int n = arr.size();
    if(long(m*k) > n) return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    int st = mini, end = maxi;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(possible(arr, mid, m, k)){
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return st;
}