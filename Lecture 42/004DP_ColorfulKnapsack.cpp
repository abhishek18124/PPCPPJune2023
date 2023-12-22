#include <iostream>
#include<climits>
#include <unordered_map>
#include <map>

using namespace std;

unordered_map<int, vector<int>> cmap; // to store a mapping b/w a color and object weights of that color

int helper(int m, int x, int i) {

    // base case

    if (i == m + 1) {
        return x;
    }

    if (x == 0) { // 1<=i<=m
        return INT_MAX;
    }

    // recursive case

    // make a decision for the ith color

    vector<int> options = cmap[i];
    int ans = INT_MAX;
    for (int xij : options) {
        if (xij <= x) {
            ans = min(ans, helper(m, x - xij, i + 1));
        }
    }

    return ans;

}

int helperTopDown(int m, int x, int i, vector<vector<int>>& dp) {

    if (dp[i][x] != -1) {
        return dp[i][x];
    }

    // base case

    if (i == m + 1) {
        return dp[i][x] = x;
    }

    if (x == 0) { // 1<=i<=m
        return dp[i][x] = INT_MAX;
    }

    // recursive case

    // make a decision for the ith color

    vector<int> options = cmap[i];
    int ans = INT_MAX;
    for (int xij : options) {
        if (xij <= x) {
            ans = min(ans, helperTopDown(m, x - xij, i + 1, dp));
        }
    }

    return dp[i][x] = ans;

}


int colorfulKnapsack(int w[], int c[], int n, int m, int x) {

    for (int i = 0; i < n; i++) {

        cmap[c[i]].push_back(w[i]);

    }

    // for (pair<int, vector<int>> p : cmap) {
    //     int color = p.first;
    //     vector<int> weights = p.second;
    //     cout << color << " :";
    //     for (int wgt : weights) {
    //         cout << wgt << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // return helper(m, x, 1);

    vector<vector<int>> dp(m + 2, vector<int>(x + 1, -1));
    int finalAns =  helperTopDown(m, x, 1, dp);
    return finalAns == INT_MAX ? -1 : finalAns;

}

int main() {

    // int w[] = {2, 3, 4, 2, 4, 5, 2, 3};
    // int c[] = {1, 1, 1, 2, 2, 2, 3, 3};

    // int n = 8;
    // int m = 3;

    // int x = 13;

    int w[] = {2, 3};
    int c[] = {1, 2};

    int n = 3;
    int m = 2;

    int x = 4;

    cout << colorfulKnapsack(w, c, n, m, x) << endl;

    return 0;

}