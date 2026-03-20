#include<bits/stdc++.h>
using namespace std;

//1. two sum
vector<int> twoSum(vector<int> &nums, int target){
int n = nums.size();
unordered_map<int, int> mpp;
for(int i = 0; i < n; i++){
    int num = nums[i];
    int remSum = target - num;
    if(mpp.find(remSum)!=mpp.end()){
        return {mpp[remSum], i};
    }
    mpp[num] = i;
}
return {-1, -1};
}

//167. two sum 2
vector<int> twoSum(vector<int> &nums, int target){
sort(nums.begin(), nums.end());
int n = nums.size();
int i = 0;
int j = n-1;
while(i < j){
    if(nums[i]+nums[j]>target){
        j--;
    }
    else if(nums[i]+nums[j]<target){
        i++;
    }
    else{
        return {i+1, j+1};
    }
}
return {};
}

//15. three sum
vector<vector<int>> threeSum(vector<int>& nums) {
int n = nums.size();
set<vector<int>> st;
for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
        for(int k = j+1; k < n; k++){
            if(nums[i] + nums[j] + nums[k] == 0){
                vector<int> trip = {nums[i], nums[j], nums[k]};
                sort(trip.begin(), trip.end());
                st.insert(trip);
            }
        }
    }
}
vector<vector<int>> ans(st.begin(), st.end());
return ans;
}


vector<vector<int>> threeSum(vector<int>& nums) {
int n = nums.size();
set<vector<int>> uniqueTriplets;
for(int i = 0; i < n; i++){
    set<int> st;
    for(int j = i + 1; j < n; j++){
        int third = -(nums[i] + nums[j]);
        if(st.find(third)!=st.end()){
            vector<int> trip = {nums[i], nums[j], third};
            sort(trip.begin(), trip.end());
            uniqueTriplets.insert(trip);
        }
        st.insert(nums[j]);
    }
}
vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
return ans;
}


vector<vector<int>> threeSum(vector<int>& nums) {
int n = nums.size();
vector<vector<int>> result;
sort(nums.begin(), nums.end());
if(n<3) return {};
for(int i = 0; i < n-2; i++){
    //duplicates
    if(i>0 && nums[i]==nums[i-1]) continue;
    int target = -nums[i];
    int j = i+1;
    int k = n-1;
    while(j < k){
        if(nums[j]+nums[k]>target){
            k--;
        }
        else if(nums[j]+nums[k]<target){
            j++;
        }
        else{
            //duplicates
            while(j<k && nums[j]==nums[j+1]) j++;
            while(j<k && nums[k]==nums[k-1]) k--;
            result.push_back({nums[i], nums[j], nums[k]});
            j++;
            k--;
        }
    }
}
return result;
}

//42. Trapping rain water
//h = min(left, right) - h[i]
vector<int> getLeftMax(vector<int>&height, int n){
    vector<int> leftMax(n);
    leftMax[0] = height[0];
    for(int i = 1 ; i < n; i++){
        leftMax[i] = max(leftMax[i-1], height[i]);
    }
    return leftMax;
}
vector<int> getRightMax(vector<int>&height, int n){
    vector<int> rightMax(n);
    rightMax[n-1] = height[n-1];
    for(int i = n-2; i >= 0; i--){
        rightMax[i] = max(rightMax[i+1], height[i]);
    }
    return rightMax;
}
int trap(vector<int>& height) {
    int n = height.size();
    vector<int> leftMax = getLeftMax(height, n);
    vector<int> rightMax = getRightMax(height, n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        int h = min(leftMax[i], rightMax[i])-height[i];
        sum += h;
    }
    return sum;
}

//16. 3 sum closest
int threeSumClosest(vector<int> &nums, int target){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int closestSum = nums[0] + nums[1] + nums[2];
    for(int k = 0; k <= n-3; k++){
        int i = k + 1;
        int j = n - 1;
        while(i < j){
            int sum = nums[i] + nums[j] + nums[k];
            if(abs(target - sum) < abs(target-closestSum)){
                closestSum = sum;
            }
            if(sum < target){
                i++;
            }
            else if(sum > target){
                j--;
            }
            else{
                return sum;
            }
        }
    }
    return closestSum;
}

//Factorial of large numbers GFG
void multiply(vector<int>&arr, int &size, int j){
    int carry = 0;
    for(int i = 0; i < size; i++){
        int res =  j * arr[i];
        res = res + carry;
        arr[i] = res % 10;
        carry = res / 10;
    }
    while(carry>0){
        arr[size] = carry%10;
        size++;
        carry = carry/10;
    }
}
vector<int> factorial(int N){
    vector<int> arr(10000, 0);
    arr[0] = 1;
    int size = 1;
    for(int i = 2; i <= N; i++){
        multiply(arr, size, i);
    }
    vector<int> result;
    for(int i = size-1; i>=0; i++){
        result.push_back(arr[i]);
    }
    return result;
}
