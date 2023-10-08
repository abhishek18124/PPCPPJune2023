#include<iostream>

using namespace std;

bool used[10] = {false}; // to track the digits used in the construction of the
// smallest number corresponding to the given pattern.

bool flag = false; // you are yet to find the lexicographically smallest num for the given pattern

void construct(string pattern, string& num, int i) {

	// base case

	if (num.size() == pattern.size() + 1) { // or i == n
		flag = true;
		cout << num << endl;
		return;
	}

	// recursive case

	if (num.size() == 0) {

		// decide the 1st digit of 'num'
		for (int d = 1; d <= 9; d++) {
			used[d] = true;
			num.push_back(d + '0'); // or // num.push_back(to_string(d));
			construct(pattern, num, i);

			if (flag == true) return;

			used[d] = false; // backtracking
			num.pop_back(); // backtracking
		}

		return;

	}

	int x = num.back() - '0'; // or num[num.size()-1] - '0'
	if (pattern[i] == 'I') {
		// next digit should be > x
		for (int d = x + 1; d <= 9; d++) {
			if (used[d] == false) {
				// you can choose digit 'd' as the next digit for 'num'
				used[d] = true;
				num.push_back(d + '0'); // or // num.push_back(to_string(d));
				construct(pattern, num, i + 1);

				if (flag == true) return;

				used[d] = false; // backtracking
				num.pop_back(); // backtracking
			}
		}
	} else { // pattern[i] == 'D'
		// next digit should be < x
		for (int d = 1; d <= x - 1; d++) {
			if (used[d] == false) {
				// you can choose digit 'd' as the next digit for 'num'
				used[d] = true;
				num.push_back(d + '0'); // or // num.push_back(to_string(d));
				construct(pattern, num, i + 1);

				if (flag == true) return;

				used[d] = false; // backtracking
				num.pop_back(); // backtracking
			}
		}
	}

}

int main() {

	string pattern = "DIID";
	string num = "";

	construct(pattern, num, 0);

	return 0;
}