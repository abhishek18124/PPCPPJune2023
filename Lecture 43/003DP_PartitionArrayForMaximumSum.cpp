#include<iostream>
#include<vector>

using namespace std;

int helper(vector<int>& arr, int n, int k, int i) {

	// base case

	if (i == n) { // you've built a valid partitioning
		return 0;
	}

	// recursive case

	// compute the largest sum upon partitioning arr[i...n-1] such that each subarray if of length <= k

	// decide the next cut

	int maxValue = INT_MIN; // to track the largest value in arr[i...j]
	int maxSoFar = INT_MIN; // to track the largest sum upon partitioning arr[i...n-1]

	for (int j = i; j <= i + k - 1 and j < n; j++) {

		maxValue = max(maxValue, arr[j]);

		// make a cut at the jth index

		maxSoFar = max(maxSoFar, maxValue * (j - i + 1) + helper(arr, n, k, j + 1));


	}

	return maxSoFar;

}

int helperBottomUp(vector<int>& arr, int n, int k) {

	vector<int> dp(n + 1);

	dp[n] = 0; // at the nth index of dp[], we store f(n) i.e. our base case

	for (int i = n - 1; i >= 0; i--) {

		// compute the largest sum upon partitioning arr[i...n-1] such that each subarray if of length <= k

		// decide the next cut

		int maxValue = INT_MIN; // to track the largest value in arr[i...j]
		int maxSoFar = INT_MIN; // to track the largest sum upon partitioning arr[i...n-1]

		for (int j = i; j <= i + k - 1 and j < n; j++) {

			maxValue = max(maxValue, arr[j]);

			// make a cut at the jth index

			maxSoFar = max(maxSoFar, maxValue * (j - i + 1) + dp[j + 1]);


		}

		dp[i] = maxSoFar;

	}

	return dp[0]; // at the 0th index of dp[], we store f(0) i.e. our org. problem

}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
	int n = arr.size();
	// return helper(arr, n, k, 0);
	return helperBottomUp(arr, n, k);
}

int main() {
	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3;
	cout << maxSumAfterPartitioning(arr, k) << endl;
	return 0;
}