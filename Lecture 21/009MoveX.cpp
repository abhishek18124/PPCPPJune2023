/*

Given a string str, design a recursive algorithm to move all the occurrence of letter x
to the end of the string str.

Example
	Input : str = "axbcxdxfx"
	Output: str = "abcdfxxxx"

	Input : str = "xabcxdxfx"
	Output: str = "abcdfxxxx"

*/

#include<iostream>

using namespace std;

string f(string s) {

	// base case
	if (s == "") { // s.empty() or s.size() == 0
		return s; // return "";
	}

	// recursive case

	string subString = s.substr(1);
	string stringFromMyFriend = f(subString);

	char ch = s[0];

	if (ch == 'x') {
		return stringFromMyFriend + ch; // stringFromMyFriend + string(1, ch)
	} else {
		return ch + stringFromMyFriend; // string(1, ch) + stringFromMyFriend
	}

}

int main() {

	string s = "bxcxx";

	cout << f(s) << endl;

	return 0;
}