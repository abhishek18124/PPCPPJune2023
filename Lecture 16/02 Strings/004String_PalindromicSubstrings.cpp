#include<iostream>

using namespace std;

bool isPalindrome(string str) {

	int i = 0;
	int j = str.size() - 1;

	while (i < j) {

		if (str[i] != str[j]) {
			return false;
		}

		i++;
		j--;

	}

	return true;

}

// time : O(n^3)

int countPalindromicSubstrings(string s) {

	int n = s.size();

	int count = 0; // to track the no. of palindromic substrings in the given string

	for (int i = 0; i < n; i++) {

		for (int j = i; j < n; j++) {

			string subString = s.substr(i, j - i + 1);
			if (isPalindrome(subString)) {
				count++;
			}

		}

	}

	return count;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstrings(s) << endl;

	return 0;
}