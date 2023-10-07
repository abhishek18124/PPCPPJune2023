// n <= 10

#include<iostream>

using namespace std;

void f(int n, char* out, int i, int j) {

	// base case
	if (i == n) { // or j == n
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// take a decision for the ith coin

	// 1. ith coin shows "head"
	if (j == 0 || out[j - 1] != 'H') {
		out[j] = 'H';
		f(n, out, i + 1, j + 1);
	}

	// 2. ith coin shows "tail"
	out[j] = 'T';
	f(n, out, i + 1, j + 1);

}

int main() {

	int n = 3;

	char out[10];

	f(n, out, 0, 0);

	return 0;
}