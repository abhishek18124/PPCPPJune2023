#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(int t, vector<int> c, vector<int>& perm) {

	// base case

	if (t == 0) {

		for (int x : perm) {
			cout << x << " ";
		}

		cout << endl;

		return;

	}

	// recursion case

	// generate permutations of 'c' that sums up to 't' or choose candidates that sum up to 't'

	// decide the next candidate

	int n = c.size();
	for (int j = 0; j < n; j++) {

		// can c[j] be the next candidate

		if (c[j] <= t) {

			// you can choose c[j] as the next candidate

			perm.push_back(c[j]);
			// t = t - c[j];
			generatePermutations(t - c[j], c, perm);
			// t = t + c[j];
			perm.pop_back(); // backtracking

		}

	}

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> perm; // to track the permutation that sums up to 't'

	generatePermutations(t, c, perm);

	return 0;
}