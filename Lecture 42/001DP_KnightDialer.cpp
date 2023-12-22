/*
    https://leetcode.com/problems/knight-dialer/
*/

class Solution {
public:

    vector<int> dx = { -2, -2, 2, 2, -1, 1, -1, 1};
    vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};

    int f(int i, int j, int m) {

        // base case

        // todo ...

        // recursive case

        // count # phone numbers the knight can dial by making 'm' moves starting from the (i, j)th cell

        int count = 0;

        // decide the next move

        // todo ...
    }


    int knightDialer(int n) {
        int total = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                // count # distinct phone numbers of length 'n' the knight can dial starting from the (i, j)th cell
                total += f(i, j, n - 1);
            }
        }
        return total;
    }
};