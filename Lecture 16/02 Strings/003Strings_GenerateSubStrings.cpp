#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	string str = "abcde";
	int n = str.size();

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			string subString = str.substr(i, j - i + 1);
			cout << subString << endl;

		}

		cout << endl;

	}

	return 0;
}