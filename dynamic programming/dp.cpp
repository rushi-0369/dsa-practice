#include <bits/stdc++.h>
using namespace std;
//memoization
//top down approach
//define state
//bottom up approach
//constant space optimization

//fibonnaci number
//memoization
int solve(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}
int fib(int n){
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

//bottom up approach
int fib(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

//constant space optimization
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}



//climbing stairs
//memoization
int solve(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

//bottom up approach
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

//constant space optimization
int climbStairs(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int prev2 = 1;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}


//house robber
//memoization
int solve(int n, vector<int> &nums, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int pick = nums[n] + solve(n - 2, nums, dp);
    int notPick = 0 + solve(n - 1, nums, dp);
    return dp[n] = max(pick, notPick);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n - 1, nums, dp);
}

//bottom up approach
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int notPick = 0 + dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}

//constant space optimization
int rob(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int notPick = 0 + prev1;
        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}


//house robber 2
//circular array
//first house and last house are adjacent
//memoization
int solve(vector<int> &nums, int i, int n, vector<int> &dp)
{
    if (i > n)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int pick = nums[i] + solve(nums, i + 2, n, dp);
    int notPick = solve(nums, i + 1, n, dp);
    return dp[n] = max(pick, notPick);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    vector<int> dp1(n, -1);
    vector<int> dp2(n, -1);
    int ans1 = solve(nums, 0, n - 2, dp1);
    int ans2 = solve(nums, 1, n - 1, dp2);
    return max(ans1, ans2);
}


