/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<set>

using namespace std;

// set<string> s;

void f(char* inp, int n, int i) {

	// base case

	if (inp[i] == '\0') { // or i == n
		cout << inp << endl;
		// s.insert(string(inp));
		return;
	}

	// recursive case

	// take decisions for positions from i to n-1

	// or generate permutations for inp[i...n-1]

	// take a decision for the ith position

	for (int j = i; j <= n - 1; j++) {

		bool flag = true; // assume you can place the jth option at the ith position

		for (int k = j + 1; k <= n - 1; k++) {
			if (inp[k] == inp[j]) {
				flag = false;
				break;
			}
		}

		if (flag == true) {

			// I want to place the character at the jth index at the ith position

			swap(inp[i], inp[j]);

			// and now ask your friend to take decisions for the remaining positions starting from the (i+1)th position

			f(inp, n, i + 1);

			swap(inp[i], inp[j]); // backtracking
		}

	}

}

int main() {

	char inp[] = "aabc";
	int n = strlen(inp);

	f(inp, n, 0);

	// for (string p : s) {
	// 	cout << p << endl;
	// }

	return 0;
}
