#include<iostream>

using namespace std;

class Solution {
public:

	int helper(vector<int>& nums, int n, int k, int i) {

		// base case

		// todo ...

		// recursive case

		// find the minimized largest sum upon partitioning nums[i...n-1] into k non-empty subarrays

		int ans = INT_MAX; // to track the minimized largest sum
		int sum = 0;       // to track the sum of nums[i...j]

		// decide where to make the next cut

		for (int j = i; j < n; j++) {

			// make the next cut at the jth index and recursively find the
			// minimized largest sum upon partitioning nums[j+1...n-1] into k-1 non-empty subarrays

			sum += nums[j];
			ans = min(ans, max(sum, helper(nums, n, k - 1, j + 1)));

		}

		return ans;

	}

	int splitArray(vector<int>& nums, int K) {
		int n = nums.size();
		return helper(nums, n, K, 0);
	}
};

int main() {

	vector<int> nums = {7, 2, 5, 10, 8};
	int K = 2;

	Solution s;

	cout << s.splitArray(nums, K) << endl;

	return 0;
}