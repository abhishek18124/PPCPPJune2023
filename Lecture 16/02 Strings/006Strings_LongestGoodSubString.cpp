#include<iostream>
#include<algorithm>

using namespace std;

bool isGoodString(string str) {

	for (char ch : str) {

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// str is not a good string
			return false;
		}

	}

	// str is a good string
	return true;

}


int main() {

	string str = "cbaeicdeiou";
	int n = str.size();


	int maxLen = 0; // or INT_MIN

	// time : O(n^3)

	// for (int i = 0; i < n; i++) {
	// 	for (int j = i; j < n; j++) {
	// 		string subString = str.substr(i, j - i + 1);
	// 		if (isGoodString(subString)) {
	// 			// track the length of the subString
	// 			// cout << subString << endl;
	// 			maxLen = max(maxLen, j - i + 1);
	// 		}

	// 	}
	// }

	// 2nd approach - sliding window

	int count = 0;

	for (char ch :  str) {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			count++;
			maxLen = max(maxLen, count);
		} else {
			count = 0;
		}
	}

	cout << maxLen << endl;

	return 0;
}