// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:

    int helper(vector<int>& prices, int N, int i, int k) {

        // base case

        // if (i == N) {

        //     if (k >= 0) { // valid transactions were done
        //         return 0;
        //     }

        //     return INT_MIN; // you've done more than K transactions

        // }

        // if (i == N) { // k >= 0
        //     return 0;
        // }

        // if (k == 0) { // i < N i.e. we still have days left

        //     return 0;

        // }

        if (i == N || k == 0) {
            return 0;
        }

        // recursive case

        // find the maximum profit you can make by completing <=k transactions starting from the ith day

        // make a decision for the ith day

        // 1. do not buy the stock on the ith day
        int x = helper(prices, N, i + 1, k);

        // 2. buy the stock on the ith day

        // decide the day to sell the stock you bought on the ith day

        int maxSoFar = INT_MIN;

        for (int j = i + 1; j <= N - 1; j++) {

            // sell the stock on the jth day

            maxSoFar = max(maxSoFar, (prices[j] - prices[i]) +  helper(prices, N, j + 1, k - 1));

        }

        return max(x, maxSoFar);

    }

    int helperBottomUp(const vector<int>& prices, int N, int K) {

        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0)); // base case is handled by initialisation

        for (int i = N - 1; i >= 0; i--) {
            for (int k = 1; k <= K; k++) {
                // make a decision for the ith day

                // 1. do not buy the stock on the ith day
                int x = dp[i + 1][k];

                // 2. buy the stock on the ith day

                // decide the day to sell the stock you bought on the ith day

                int maxSoFar = INT_MIN;

                for (int j = i + 1; j <= N - 1; j++) {

                    // sell the stock on the jth day

                    maxSoFar = max(maxSoFar, (prices[j] - prices[i]) +  dp[j + 1][k - 1]);

                }

                dp[i][k] = max(x, maxSoFar);
            }
        }

        return dp[0][K];

    }

    int maxProfit(int K, vector<int>& prices) {
        int N = prices.size();

        // return helper(prices, N, 0, K);

        // vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));
        // return helperTopDown(prices, N, 0, K, dp);

        return helperBottomUp(prices, N, K);
    }
};