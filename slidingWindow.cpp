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
        j++;
        while(sum >= target){
            minLen = min(minLen, sum);
            sum-=nums[i];
            i++;
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
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


//Count subarrays with fixed bounds Leetcode 2444
//smaller = min(minPosi, maxPosi)
//temp = smaller - culpritIdx
//if(temp<=0) ans += 0
//else ans += temp
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