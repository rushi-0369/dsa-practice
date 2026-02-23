#include <bits/stdc++.h>
using namespace std;

// Find the Score Difference in a Game
int scoreDifference(vector<int>& nums) {
    int score1 = 0;
    int score2 = 0;
    int active = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i]%2 == 1){
            active = active ^ 1;
        }
        if(i % 6 == 5){
            active = active ^ 1;
        }
        if(active == 0){
            score1+=nums[i];
        }
        else{
            score2+=nums[i];
        }
    }
    return score1 - score2;
}

