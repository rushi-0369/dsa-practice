#include <bits/stdc++.h>
using namespace std;

//762. Prime Number of Set Bits in Binary Representation => 21-02-2026
bool prime(int n){
    if(n<2) return false;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int countPrimeSetBits(int left, int right) {
    int cntP = 0;
    for(int i = left; i <= right; i++){
        int setBits = __builtin_popcount(i);
        if(prime(setBits)){
            cntP++;
        }
    }
    return cntP;
}

//868. Binary Gap => 22-02-2026
int binaryGap(int n) {
    int last = -1;
    int pos = 0;
    int maxDist = 0;
    while(n > 0){
        if(n & 1){
            if(last != -1){
                maxDist = max(maxDist, pos-last);
            }
            last = pos;
        }
        n = n>>1;
        pos++;

    }
    return maxDist;
}

//1461. Check If a String Contains All Binary Codes of Size K => 23-02-2026
bool hasAllCodes(string s, int k) {
    int n = s.length();
    if(k>n) return false;
    unordered_set<string> st;
    for(int i = 0; i <= n-k; i++){
        st.insert(s.substr(i, k));
    }
    return st.size()==(1<<k);
}