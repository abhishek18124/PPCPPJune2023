#include<iostream>

using namespace std;

string spellingMap[] = { "zero", "one", "two", "three",
                         "four", "five", "six", "seven",
                         "eight", "nine"
                       };


void f(int n) {

	// base case
	if (n == 0) {
		return;
	}

	// recursive case

	// 1. ask your friend to print the spelling of n/10

	f(n / 10);

	// 2. print the spelling of digit at the ones place

	// int d = n % 10;
	// cout << spellingMap[d] << endl;

	cout << spellingMap[n % 10] << " ";


}
int main() {

	int n = 826;

	f(n);

	return 0;
}