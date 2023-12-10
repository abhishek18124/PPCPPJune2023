class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, bool> startMap;

        // time : n steps

        for (int num : nums) {

            if (startMap.find(num - 1) == startMap.end()) {

                // you've not seen num-1 so far

                startMap[num] = true;

            } else {

                // you cannot num as the starting point

                startMap[num] = false;

            }

            if (startMap.find(num + 1) != startMap.end()) {

                // you've seen num+1 previously

                startMap[num + 1] = false;

            }

        }

        // for(pair<int, bool> p : startMap) {
        //     cout << p.first << " " << p.second << endl;
        // }

        // time : n steps

        int maxSoFar = 0;

        for (pair<int, bool> p : startMap) {
            int key = p.first;
            bool canStart = p.second;
            if (canStart) {

                int cnt = 0;

                while (startMap.find(key) != startMap.end()) {
                    cnt++;
                    key++;
                }

                maxSoFar = max(maxSoFar, cnt);

            }
        }

        // total steps = n + n = 2n ~ O(n)
        // space = O(n) due to startMap

        return maxSoFar;

    }
};