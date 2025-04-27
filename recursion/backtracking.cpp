#include <bits/stdc++.h>
using namespace std;
//Permutations
void getPerms(int idx, vector<int>& a, vector<vector<int>>& result){
    if(a.size()==idx){
        result.push_back(a);
        return;
    }
    for(int i = idx ; i < a.size(); i++){
        swap(a[idx], a[i]);
        getPerms(idx+1, a, result);
        swap(a[idx], a[i]);
    }
}
vector<vector<int>> permutate(vector<int>& a, int n){
    vector<vector<int>> result(n);
    getPerms(0, a, result);
    return result;
}

//subsets without duplicates
void getSubsetsWithoutDup(vector<int>& nums, vector<int>& ans, vector<vector<int>>& subsets, int i){
    if(i==nums.size()){
        subsets.push_back({ans});
        return;
    }
    ans.push_back(nums[i]);
    getSubsetsWithoutDup(nums, ans, subsets, i+1);
    ans.pop_back();
    getSubsetsWithoutDup(nums, ans, subsets, i+1);
}
vector<vector<int>> subsetsWithoutDup(vector<int>& nums) {
    vector<int> ans(nums.size());
    vector<vector<int>> subsets;
    getSubsetsWithoutDup(nums, ans, subsets, 0);
    return subsets;
}

//subsets with duplicates
void getSubsetsWithDup(vector<int>& nums, vector<int>& ans, vector<vector<int>>& subsets,int i){
    if(i==nums.size()){
        subsets.push_back({ans});
        return;
    }
    ans.push_back(nums[i]);
    getSubsetsWithDup(nums, ans, subsets, i+1);
    ans.pop_back();
    if(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
    getSubsetsWithDup(nums, ans, subsets, i+1);
}
vector<vector<int>> subsetsWithoutDup(vector<int>& nums) {
    vector<int> ans(nums.size());
    vector<vector<int>> subsets;
    getSubsetsWithDup(nums, ans, subsets, 0);
    return subsets;
}