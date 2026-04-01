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
    int tar = -nums[i];
    set<int> st;
    for(int j = i + 1; j < n; j++){
        int third = tar - nums[j];
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
            result.push_back({nums[i], nums[j], nums[k]});
            while(j<k && nums[j]==nums[j+1]) j++;
            while(j<k && nums[k]==nums[k-1]) k--;
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

//GFG Factorials of large numbers
void multiply(vector<int>& arr, int& size, int x){
    int carry = 0;
    for(int i = 0; i < size; i++){
        int res = arr[i] * x + carry;
        res = res % 10;
        carry = res / 10;
    }
    while(carry){
        arr[size] = carry % 10;
        size++;
        carry = carry / 10;
    }
}
vector<int> factorial(int n){
    vector<int> arr(10000, 0);
    int arr[0] = 0;
    int size = 1;
    for(int i = 1; i <= n; i++){
        multiply(arr, size , i);
    }
    vector<int> result;
    for(int i = n - 1; i >= 0; i--){
        result.push_back(arr[i]);
    }
    return result;
}

//31. Next Permutation
void nextPermutation(vector<int> &nums){
    int n = nums.size();
    int pivot = -1;
    for(int i = n-2; n >= 0; i--){
        if(nums[i] > nums[i+1]){
            pivot = i;
            break;
        }
    }
    if(pivot == -1){
        reverse(nums.begin(), nums.end());
        return;
    }
    for(int i = n-1; i > pivot; i--){
        if(nums[i] > nums[pivot]){
            swap(nums[i], nums[pivot]);
            break;
        }
    }
    int i = pivot + 1;
    int j = n - 1;
    while(i < j){
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

//48. Rotate Image
void rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[j][n-i-1] = matrix[i][j];
        }
    }
}

void rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    for(int i = 0; i <= n-2; i++){
        for(int j = i+1; j <= n-1; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end();
    }
}

//11. Container with most water
int maxArea(vector<int> &height){
    int n = height.size();
    int lp = 0;
    int rp = n - 1;
    int maxWater = 0;
    while(lp < rp){
        int ht = min(height[lp], height[rp]);
        int wt = rp - lp;
        int area = ht * wt;
        maxWater = max(area, maxWater);
        if(height[lp] < height[rp]){
            lp++;
        }
        else{
            rp--;
        }
    }
    return maxWater;
}
