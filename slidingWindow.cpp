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
        counter[txt[j]-'a']--;
        if(j-i+1 == pat.length()){
            if(allZero(counter)){
                cnt++;
            }
            counter[txt[i]-'a']++;
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
        counter[txt[j]-'a']--;
        if(j-i+1 == pat.length()){
            if(allZero(counter)){
                result.push_back(i);
            }
            counter[txt[i]-'a']++;
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
        while(sum >= target){
            minLen = min(minLen, j-i+1);
            sum-=nums[i];
            i++;
        }
        j++;
    }
    return minLen == INT_MAX ? 0 : minLen;
}

//gfg first negative integer in every window of size k
vector<long long> printFirstNegativeInteger(long long int nums[], long long int n, long long int k) {
    int i = 0;
    int j = 0;
    vector<long long> result;
    queue<long long> q;
    while(j < n){
        if(nums[j] < 0){
            q.push(nums[j]);
        }
        if(j-i+1 == k){
            if(q.empty()){
                result.push_back(0);
            }
            else{
                result.push_back(q.front());
                if(nums[i] == q.front()){
                    q.pop();
                }
            }
            i++;
        }
        j++;
    }
    return result;
}

//minimum window substring Leetcode 76
string minWindow(string s, string t){
    if(s.length()<t.length()) return "";
    unordered_map<char, int> mpp;
    for(char &ch : t){
        mpp[ch]++;
    }
    int windowSize = INT_MAX;
    int start = 0;
    int i = 0;
    int j = 0;
    int counter = t.length();
    while(j < s.length()){
        char ch = s[j];
        if(mpp[ch]>0){
            counter--;
        }
        mpp[ch]--;
        while(counter == 0){
            int currWindow = j - i + 1;
            if(currWindow < windowSize){
                start = i;
                windowSize = currWindow;
            }
            mpp[s[i]]++;
            if(mpp[s[i]]>0){
                counter++;
            }
            i++;
        }
        j++;
    }
    return (windowSize == INT_MAX)? "" : s.substr(start, windowSize);
}
//contains duplicate II Leetcode 219
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int i = 0;
    int j = 0;
    unordered_set<int> st;
    while(j < nums.size()){
        if(st.find(nums[j]) != st.end()){
            return true;
        }
        st.insert(nums[j]);
        if(j-i+1 == k){
            st.erase(nums[i]);
            i++;
        }
        j++;
    }
    return false;
}

//Count subarrays with fixed bounds Leetcode 2444
//smaller = min(minPosi, maxPosi)
//temp = smaller - culpritIdx
//if(temp<=0) ans += 0
//else ans += temp
//valid subarrays ending at i=max(0,min(minPosi,maxPosi)−culpritIdx)
long long countSubbarays(vector<int>&nums, int minK, int maxK){
    long long ans = 0;
    int minPosi = -1;
    int maxPosi = -1;
    int culpritIdx = -1;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i]==minK){
            minPosi = i;
        }
        if(nums[i]==maxK){
            maxPosi = i;
        }
        if(nums[i]<minK || nums[i]>maxK){
            culpritIdx = i;
        }
        long long smaller = min(minPosi, maxPosi);
        long long temp = smaller - culpritIdx;
        ans += (temp<=0)?0:temp; 
    }
    return ans;
}

//Maximum number vowels in a substring length Leetcode 1456
bool isVowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        return true;
    }
    return false;
}
int maxVowels(string s, int k){
    int i = 0;
    int j = 0;
    int count = 0;
    int maxV = 0;
    while(j < s.length()){
        if(isVowel(s[j])){
            count++;
        }
        if(j-i+1 == k){
            maxV = max(maxV, count);
            if(isVowel(s[i])){  
                count--;
            }
            i++;
        }
        j++;
    }
    return maxV;
}

//K Radius Subarray Averages lc 2090
//perfix sum/cummulative sum
vector<int> getAverages(vector<int>& nums, int k){
    int n = nums.size();
    if(k == 0){
        return nums;
    }
    vector<int>result(n, -1);
    if(n < 2*k+1){
        return result;
    }
    int l = 0;
    int r = 2*k;
    int i = k;
    long long window = 0;
    for(int j = l; j <= r; j++){
        window = window + nums[j];
    }
    int avg = window/(2*k+1);
    result[i] = avg;
    i++;
    r++;
    while(r < n){
        int out = nums[l];
        int in = nums[r];
        window = window+in-out;
        result[i] = window/2*k+1;
        i++;
        r++;
        l++;
    }
    return result;
}
//sliding window k radius subarray averages
vector<int> getAverages(vector<int>& nums, int k){
    int n = nums.size();
    if(k == 0){
        return nums;
    }
    vector<int>result(n, -1);
    if(n < 2*k+1){
        return result;
    }
    int i = 0;
    int j = 0;
    long long window = 0;
    while(j < n){
        window+=nums[j];
        if(j-i+1 == 2*k+1){
            result[i+k] = window/(2*k+1);
            window-=nums[i];
            i++;
        }
        j++;
    }
    return result;
}

//1493. Longest Subarray of 1's After Deleting One Element
//Example 1:
// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
// Example 2:
// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
// Example 3:
// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
int findMax(vector<int>&nums, int skip_idx){
    int n = nums.size();
    int currLen = 0;
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        if(i==skip_idx){
            continue;
        }
        if(nums[i] == 1){
            currLen++;
            maxLen = max(currLen, maxLen);
        }
        else{
            currLen = 0;
        }
    }
    return maxLen;
}
int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int result = 0;
    int countZero = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == 0){
            countZero++;
            result = max(result, findMax(nums, i));
        }
    }
    if(countZero == 0) return n-1;
    return result;
}

int longestSubarray(vector<int>& nums) {
    int i = 0;
    int j = 0;
    int zeroCount = 0;
    int ans = 0;
    while(j < nums.size()){
        if(nums[j] == 0) zeroCount++;
        while(zeroCount > 1){
            if(nums[i] == 0) zeroCount--;
            i++;
        }
        ans = max(ans, j-i);
        j++;
    }
    return ans;
}

int longestSubarray(vector<int>& nums) {
    int i = 0;
    int j = 0;
    int idx_pos = -1;
    int ans = 0;
    while(j < nums.size()){
        if(nums[j] == 0){
            i = idx_pos+1;
            idx_pos = j;
        }
        ans = max(ans, j-i);
        j++;
    }
    return ans;
}
