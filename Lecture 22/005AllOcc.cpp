#include<iostream>
#include<vector>

using namespace std;

bool flag = false; // assume 't' is not present in the x[]
vector<int> v;

void f(int* x, int n, int t, int i) {

	// base case


	if (i == n) {
		if (flag == false) {
			cout << -1;
		}
		return;

	}

	// recursive case

	// find the idx of the 1st occ of the 't' in x[i...n-1]

	if (x[i] == t) {
		v.push_back(i);
		flag = true;
		// cout << i << " ";
	}

	// recursively, find the idx of the 1st occ of the 't' in x[i+1...n-1]

	f(x, n, t, i + 1);

}



int main() {

	int x[] = {10, 20, 30, 20, 30};
	int n = sizeof(x) / sizeof(int);
	int t = 20;

	f(x, n, t, 0);

	for (int index : v) {
		cout << index << " ";
	}

	return 0;
}