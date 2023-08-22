// recursive code
#include <bits/stdc++.h>

int f(int ind, vector<int> &nums){
    if(ind==0) return nums[ind];
    if(ind<0) return 0;
    
    int pick = nums[ind] + f(ind-2, nums);
    int notpick = 0 + f(ind-1, nums);
    return max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    return f(n-1, nums);
}

// memorization dp

int f(int ind, vector<int> &nums, vector<int> &dp){
    if(ind==0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int pick = nums[ind] + f(ind-2, nums, dp);
    int notpick = 0 + f(ind-1, nums, dp);
    return dp[ind] = max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,-1);
    return f(n-1, nums, dp);
}

// tabulation dp + space optimized

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for(int i=1; i<n; i++){
        int take = nums[i];
        if(i>1) take += prev2;
        int nottake = 0 + prev;

        int curri = max(take, nottake);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

