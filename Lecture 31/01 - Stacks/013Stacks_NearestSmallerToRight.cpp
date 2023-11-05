#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;


// time  : O(n)
// space : O(n)

// void f(int* A, int n) {

// 	stack<int> s; // we are tracking values

// 	vector<int> v;

// 	for (int i = n - 1; i >= 0; i--) {

// 		// find the index of nearest smaller element to the right of A[i]

// 		while (!s.empty() and s.top() >= A[i]) {
// 			s.pop();
// 		}

// 		if (s.empty()) {
// 			v.push_back(n);
// 		} else {
// 			v.push_back(s.top());
// 		}

// 		s.push(A[i]);

// 	}

// 	reverse(v.begin(), v.end());

// 	for (int i = 0; i < v.size(); i++) {
// 		cout << v[i] << " ";
// 	}

// 	cout << endl;

// }



void f(int* A, int n) {

	stack<int> s; // we are tracking indices

	vector<int> v;

	for (int i = n - 1; i >= 0; i--) {

		// find the index of nearest smaller element to the right of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			v.push_back(n);
		} else {
			v.push_back(s.top());
		}

		s.push(i);

	}

	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

}



int main() {

	int A[] = {2, 5, 1, 3, 6, 4, 0};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}