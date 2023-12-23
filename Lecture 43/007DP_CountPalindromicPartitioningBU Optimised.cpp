#include<iostream>
#include<vector>

using namespace std;

int helperBottomUpOptimised(string str, int n) {

	vector<vector<bool>> memo(n, vector<bool>(n));

	// todo ...

	vector<int> dp(n + 1);

	dp[n] = 1; // at the nth index of dp[], we store f(n)

	for (int i = n - 1; i >= 0; i--) {

		// count the no. of palindromic partitioning of str[i...n-1]

		// todo ...

	}

	return dp[0]; // at the 0th index of dp[], we store f(0)

}

int main() {

	string str = "abaaa";
	int n = str.size();

	cout << helperBottomUpOptimised(str, n) << endl;

	return 0;
}