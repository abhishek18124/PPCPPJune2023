#include<iostream>
#include<stack>

using namespace std;

// void f(int* A, int n) {

// 	stack<pair<int, int>> s; // <value, index>

// 	vector<int> v;

// 	for (int i = 0; i <= n - 1; i++) {

// 		// find the nearest greater element to the left of A[i]

// 		while (!s.empty() and s.top().first <= A[i]) {
// 			s.pop();
// 		}

// 		int j;

// 		if (s.empty()) {
// 			j = -1;
// 		} else {
// 			j = s.top().second;
// 		}

// 		v.push_back(i - j);

// 		s.push({A[i], i}); // or s.push(make_pair(A[i], i));

// 	}

// 	for (int i = 0; i < v.size(); i++) {
// 		cout << v[i] << " ";
// 	}

// 	cout << endl;

// }


void f(int* A, int n) {

	stack<int> s; // <index>

	vector<int> v;

	for (int i = 0; i <= n - 1; i++) {

		// find the nearest greater element to the left of A[i]

		while (!s.empty() and A[s.top()] <= A[i]) {
			s.pop();
		}

		int j;

		if (s.empty()) {
			j = -1;
		} else {
			j = s.top();
		}

		v.push_back(i - j);

		s.push(i);

	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

}


int main() {

	int A[] = {100, 80, 60, 70, 60, 75, 185};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}