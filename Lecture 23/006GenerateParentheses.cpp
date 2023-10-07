// n <= 8

#include<iostream>

using namespace std;

void f(int n, char* out, int j, int openCount, int closeCount) {

	// base case

	if (openCount == n and closeCount == n) { // or j == 2*n
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// take a decision for the jth position

	// 1. use '('
	if (openCount < n) {
		out[j] = '(';
		f(n, out, j + 1, openCount + 1, closeCount);
	}

	// 2. use ')'
	if (closeCount < n) {
		out[j] = ')';
		f(n, out, j + 1, openCount, closeCount + 1);
	}

}

int main() {

	int n = 2;

	char out[20];

	f(n, out, 0, 0, 0);

	return 0;
}