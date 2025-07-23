#include <bits/stdc++.h>
using namespace std;

//r-1 c c-1
int ncr(int n, int r){
    int res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n-i);
        res = res / (i+1);   
    }
    return res;
}

//print el at r, c
int pascalTriangle(int r, int c){
    int element = ncr(r - 1, c - 1);
    return element;
}

//given row, print nth row
//BFA
int pascalTriangleBFA(int n){
    for(int i = 1; i <= n; i++){
        cout << ncr(n-1, i-1) << " ";
    }
}
//OA
int pascalTriangleOA(int n){
    long long ans = 1;
    cout << ans << " ";
    for(int i = 1; i < n; i++){
        ans = ans * (n-i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl; 
}

//print whole pascal triangle
//BFA
vector<vector<int>> pascalTrianglePrintBFA(int n){
    vector<vector<int>> ans;
    for(int i = 1; i <= n; i++){
        vector<int> temp;
        for(int j = 1; j <= i; j++){
            temp.push_back(ncr(i-1, j-1));
        }
        ans.push_back(temp);
    }
    return ans;
}
//OA
vector<int> generateRow(int i){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    
    for(int col = 1; col < i; col++){
        ans = ans * (i - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
} 
vector<vector<int>> pascalTrianglePrintOA(int n){
    vector<vector<int>> ans;
    for(int i = 1; i <= n; i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}

//3 Sum a[i] + a[j] + a[k] = 0
//no repetition of i or j or k
//unique triplet (we sort it)
//BFA Try out all triplets
vector<vector<int>> triplet(int n, vector<int> &nums){
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
//TC = n^3 + log(no.of unique triplets)
//SC = 2* no.of unique triplets
