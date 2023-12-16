#include<iostream>
#include<vector>

using namespace std;

// recursive implementation

int helper(vector<int>& nums, int n, int i) {

    // base case

    if (i == n || i == n + 1) {
        return 0;
    }

    // recursive case

    // find the maximum amount of money you can rob given a sequence of n-i houses [i...n-1] w/o alerting the police

    // decide for the ith house

    // 1. rob the ith house

    int x = helper(nums, n, i + 2);

    // 2. do not rob the ith house

    int y = helper(nums, n, i + 1);

    return max(nums[i] + x, y);

}

int helperTopDown(vector<int>& nums, int n, int i, vector<int>& dp) {

    // lookup

    if (dp[i] != -1) {
        return dp[i];
    }

    // base case

    if (i == n || i == n + 1) {
        return dp[i] = 0;
    }

    // recursive case

    // find the maximum amount of money you can rob given a sequence of n-i houses [i...n-1] w/o alerting the police

    // decide for the ith house

    // 1. rob the ith house

    int x = helperTopDown(nums, n, i + 2, dp);

    // 2. do not rob the ith house

    int y = helperTopDown(nums, n, i + 1, dp);

    return dp[i] = max(nums[i] + x, y);

}

int helperBottom(vector<int> nums, int n) {

    vector<int> dp(n + 2);

    dp[n + 1] = 0; // at the (n+1)th index we store f(n+1)
    dp[n] = 0; // at the nth index we store f(n)

    for (int i = n - 1; i >= 0; i--) {

        // dp[i] = f(i) = max. profit from house[i...n-1]

        // decide for the ith house

        // 1. rob the ith house

        int x = dp[i + 2];

        // 2. don't rob the ith house

        int y = dp[i + 1];

        dp[i] = max(nums[i] + x, y);

    }

    return dp[0]; // at the 0th index of dp[], we store f(0)

}

int rob(vector<int>& nums) {

    int n = nums.size();

    // return helper(nums, n, 0);

    // vector<int> dp(n + 2, -1);

    // return helperTopDown(nums, n, 0, dp);

    return  helperBottom(nums, n);

}

int main() {

    vector<int> nums = {100, 50, 400, 200, 100};

    cout << rob(nums) << endl;

    return 0;
}