#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// time  : O(n)
// space : O(n)

void f(int* A, int n) {

	stack<int> s;

	vector<int> v;

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest greater element to the right of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// cout << -1 << " ";
			v.push_back(-1);
		} else {
			// cout << s.top() << " ";
			v.push_back(s.top());
		}

		s.push(A[i]);

	}

	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

}

int main() {

	int A[] = {5, 3, 6, 7, 2, 1, 4};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}