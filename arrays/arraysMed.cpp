#include <bits/stdc++.h>
using namespace std;
//BFA->can be used for both varients
vector<int> twoSumBFA(vector<int>& a, int n, int target){
    vector<int> result;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i]+a[j]==target){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return {-1, -1};
}
//BA->hashmap X
//OA->only for varient which return true, false
int twoSumOA(vector<int>& a, int n, int target){
    sort(a.begin(), a.end());
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
void sortArrayBA(vector<int>& a, int n){
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
void sortArrayOA(vector<int>& a, int n){
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
int majorityElementBFA(vector<int>& a, int n){
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
int majorityElementBA(vector<int>& a, int n){
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
int majorityElementOA(vector<int>& a, int n){
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
//maximum subarray sum
int maximumSubarraySumBFA(vector<int>& a, int n){
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum = sum + a[k];
                maxi = max(sum, maxi);
            }
        }
    }
    return maxi;
}

int maximumSubarraySumBA(vector<int>& a, int n){
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
//Kadane's Algorithm
int maximumSubarraySumOA(vector<int>& a, int n){
    int sum = 0;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        sum = sum + a[i];
        if(sum<0){
            sum = 0;
        }
        if(sum>maxi){
            maxi = sum;
        }
    }
    if(maxi<0) maxi = 0;
    return maxi;
}
//varient 2
void maximumSubarraySumVarientOA(vector<int>& a, int n){
    int sum = 0;
    int maxi = INT_MIN;
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    for(int i = 0; i < n; i++){
        if(sum==0) start = i;
        sum = sum + a[i];
        if(sum<0){
            sum = 0;
        }
        if(sum>maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
    }
    for(int i = ansStart; i < ansEnd; i++){
        cout << a[i] <<" ";
    }
}
//Rearrange the array in alternating positive and negative items
vector<int> rearragePosNegBFA(vector<int>& a, int n){
    vector<int> pos(n/2);
    vector<int> neg(n/2);
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            pos.push_back(a[i]);
        }
        else{
            neg.push_back(a[i]);
        }
    }
    for(int i = 0; i < n/2; i++){
        a[2*i] = pos[i];
        a[2*i+1] = neg[i];
    }
    return a;
}

vector<int> rearragePosNegOA(vector<int>& a, int n){
    vector<int> ans(n);
    int pos = 0;
    int neg = 1;
    for(int i = 0; i < n; i++){
        if(a[i]>0){
            ans[pos] = a[i];
            pos = pos+2;
        }
        else{
            ans[neg] = a[i];
            neg = neg + 2;
        }
    }
    return ans;
}
//Leaders in an array
vector<int> leadersBFA(vector<int>& a){
    int n = a.size();
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int leader = true;
        for(int j = i + 1; j < n; j++){
            if(a[j] > a[i]){
                leader = false;
                break;
            }
        }
        if(leader==true){
            ans.push_back(a[i]);
        }
    }
    return ans;
}

vector<int> leadersOA(vector<int>& a){
    int n = a.size();
    int maxi = INT_MIN;
    vector<int> ans;
    for(int i = n-1; i > 0; i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
        }
        maxi = max(a[i], maxi);
    }
    return ans;
}

//Container with Most Water
int maxAreaBFA(vector<int>& height) {
    int n = height.size();
    int maxWater = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int w = j - i;
            int ht = min(height[i], height[j]);
            int area = w*ht;
            maxWater = max(area,maxWater);
        }
    }
    return maxWater;
}

int maxAreaOA(vector<int>& height){
    int lp = 0;
    int rp = height.size() - 1;
    int maxWater = 0;
    while(lp < rp){
        int w = rp - lp;
        int ht = min(height[lp], height[rp]);
        int area = w*ht;
        maxWater = max(area,maxWater);
        if(height[lp] < height[rp]){
            lp++;
        }
        else{
            rp--;
        }
    }
    return maxWater;
}
