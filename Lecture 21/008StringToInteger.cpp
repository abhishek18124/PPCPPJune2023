#include<iostream>

using namespace std;

int f(string s, int n) {

	// base case
	if (n == 0) { // s == "" or s.empty() or s.size() == 0
		return 0;
	}

	// if (n == 1) {
	// 	return s[n - 1] - '0';
	// }

	// recursive case

	string subString = s.substr(0, n - 1);
	int integerFromMyFriend = f(subString, n - 1);

	return integerFromMyFriend * 10 + (s[n - 1] - '0');

}

int main() {

	string str = "12345";
	int n = str.size();

	int x = f(str, n);

	cout << x << endl;

	cout << x + 1 << endl;

	return 0;
}