/*

    https://leetcode.com/problems/wildcard-matching/

*/

class Solution {
public:

    // bool helper(const string& s, const string& p, int m, int n, int i, int j) {

    //     // base case

    //     if (i == m) {

    //         bool flag = true; // assume p[j...n-1] contains only stars
    //         for (int k = j; k <= n - 1; k++) {
    //             if (p[k] != '*') {
    //                 flag = false;
    //                 break;
    //             }
    //         }

    //         return flag;

    //     }

    //     if (j == n) { // i != m i.e. 0<=i<=m-1 i.e. s[] is non-empty
    //         return false;
    //     }

    //     // recursive case

    //     // does p[j...n-1] match s[i...m-1]

    //     if (s[i] == p[j]) {

    //         // recursively, check p[j+1...n-1] matches s[i+1...m-1]
    //         return helper(s, p, m, n, i + 1, j + 1);

    //     } else {

    //         if (p[j] == '?') {
    //             // recursively, check p[j+1...n-1] matches s[i+1...m-1]
    //             return helper(s, p, m, n, i + 1, j + 1);
    //         } else if (p[j] == '*') {
    //             // use '*' zero time

    //             // use '*' multiple times
    //             return helper(s, p, m, n, i, j + 1)  or helper(s, p, m, n, i + 1, j);
    //         } else {
    //             // p[j] is not a wildcard
    //             return false;
    //         }

    //     }

    // }

    bool helper(const string& s, const string& p, int m, int n, int i, int j) {

        // base case

        if (i == m) {

            bool flag = true; // assume p[j...n-1] contains only stars
            for (int k = j; k <= n - 1; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            return flag;

        }

        if (j == n) { // i != m i.e. 0<=i<=m-1 i.e. s[] is non-empty
            return false;
        }

        // recursive case

        // does p[j...n-1] match s[i...m-1]

        if (s[i] == p[j] || p[j] == '?') {

            // recursively, check p[j+1...n-1] matches s[i+1...m-1]
            return helper(s, p, m, n, i + 1, j + 1);

        } else if (p[j] == '*') {
            // use '*' zero time

            // use '*' multiple times
            return helper(s, p, m, n, i, j + 1)  or helper(s, p, m, n, i + 1, j);
        } else {
            // p[j] is not a wildcard
            return false;
        }
    }

    bool helperBottomUp(const string& s, const string& p, int m, int n) {

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

        for (int i = 0; i < m; i++) {
            dp[i][n] = false;
        }

        // dp[m][n] = true; // s[] is empty, p[] is empty, handled in the next loop

        for (int j = 0; j <= n; j++) { // nth column is already assigned true value
            // check p[j...n-1] matches s[m...m-1] i.e. empty
            bool flag = true; // assume p[j...n-1] contains only stars
            for (int k = j; k <= n - 1; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[m][j] = flag;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // dp[i][j] = f(i, j) = check P[j...n-1] matches S[i...m-1]
                if (s[i] == p[j] || p[j] == '?') {
                    // recursively, check p[j+1...n-1] matches s[i+1...m-1]
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (p[j] == '*') {
                    // use '*' zero time
                    // use '*' multiple times
                    dp[i][j] = dp[i][j + 1]  or dp[i + 1][j];
                } else {
                    // p[j] is not a wildcard
                    dp[i][j] = false;
                }
            }
        }

        return dp[0][0];

    }

    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();

        // return helper(s, p, m, n, 0, 0);

        return helperBottomUp(s, p, m, n);

    }
};