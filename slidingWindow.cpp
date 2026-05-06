#include<bits/stdc++.h>
using namespace std;

//count occurences of anagrams GFG
//txt = forxxorfxdofr pat = for  3
bool allZero(vector<int>&counter){
    for(int i = 0; i < counter.size(); i++){
        if(counter[i]!=0){
            return false;
        }
    }
    return true;
}
int search(string &pat, string &txt){
    int n = txt.size();
    vector<int> counter(26, 0);
    for(int i = 0; i < pat.length(); i++){
        counter[pat[i]-'a']++;
    }
    int i = 0;
    int j = 0;
    int cnt = 0;
    while(j < n){
        counter[txt[j]-'a']++;
        if(j-i+1 == pat.length()){
            if(allZero(counter)){
                cnt++;
            }
            counter[txt[i]-'a']--;
            i++;
        }
        j++;
    }
    return cnt;
}

//Find all anagrams in a string Leetcode 438
//s = "cbaebabacd", p = "abc"  [0,6]
bool allZero(vector<int>&counter){
    for(int i = 0; i < counter.size(); i++){
        if(counter[i]!=0){
            return false;
        }
    }
    return true;
}
vector<int> search1(string &pat, string &txt){
    int n = txt.size();
    vector<int> counter(26, 0);
    for(int i = 0; i < pat.length(); i++){
        counter[pat[i]-'a']++;
    }
    int i = 0;
    int j = 0;
    vector<int>result;
    while(j < n){
        counter[txt[j]-'a']++;
        if(j-i+1 == pat.length()){
            if(allZero(counter)){
                result.push_back(i);
            }
            counter[txt[i]-'a']--;
            i++;
        }
        j++;
    }
    return result;
}

//minimum size subarray sum Leetcode 209
int minSubArrayLen(vector<int>& nums, int target){
    int minLen = INT_MAX;
    int sum = 0;
    int i = 0;
    int j = 0;
    while(j < nums.size()){
        sum+=nums[j];
        j++;
        while(sum >= target){
            minLen = min(minLen, sum);
            sum-=nums[i];
            i++;
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}

