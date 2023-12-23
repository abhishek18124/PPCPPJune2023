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

vector<string> v; // to track a single partition

int countPalindromicPartitioning(const string& str, int n, int i) {

	// base case

	if (i == n) {
		for (string s : v) {
			cout << s << " ";
		}
		cout << endl;
		return 1;
	}

	// recursive case

	// count the no. of palindromic partitioning of str[i...n-1]

	int cnt = 0;

	for (int j = i; j <= n - 1; j++) {

		// can you make a cut at the jth index

		// check if s[i...j] is a palindrome

		string subString = str.substr(i, j - i + 1);
		if (isPalindrome(subString)) {
			// you can make a cut at the jth index
			v.push_back(subString);
			cnt += countPalindromicPartitioning(str, n, j + 1);
			v.pop_back();
		}

	}

	return cnt;

}

int main() {

	string str = "abaaa";
	int n = str.size();

	cout << countPalindromicPartitioning(str, n, 0) << endl;

	return 0;
}