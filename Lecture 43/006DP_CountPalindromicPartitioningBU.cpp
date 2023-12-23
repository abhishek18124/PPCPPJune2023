#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(string s) {
	int i = 0;
	int j = s.size() - 1;

	while (i < j) {
		if (s[i] != s[j]) {
			// 's' is not a palindrome
			return false;
		}
		i++;
		j--;
	}

	// 's' is a palindrome
	return true;
}

int helperBottomUp(string str, int n) {

	vector<int> dp(n + 1);

	dp[n] = 1; // at the nth index of dp[], we store f(n)

	for (int i = n - 1; i >= 0; i--) {

		// count the no. of palindromic partitioning of str[i...n-1]

		int cnt = 0;

		for (int j = i; j <= n - 1; j++) {

			// can you make a cut at the jth index

			// check if s[i...j] is a palindrome

			string subString = str.substr(i, j - i + 1);
			if (isPalindrome(subString)) {
				// you can make a cut at the jth index
				cnt += dp[j + 1];
			}

		}

		dp[i] = cnt;

	}

	return dp[0]; // at the 0th index of dp[], we store f(0)

}

int main() {

	string str = "abaa";
	int n = str.size();

	cout << helperBottomUp(str, n) << endl;

	return 0;
}