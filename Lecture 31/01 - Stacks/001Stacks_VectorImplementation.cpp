#include<iostream>
#include<vector>

using namespace std;


// class stack {

// 	vector<int> v; // internal repr. of the dynamic stack

// 	void push(int val) {
// 		v.push_back(val);
// 	}

// 	void pop() {
// 		if(v.size() == 0) {
// 			// stack is empty
// 			return;
// 		}
// 		v.pop_back();
// 	}

// 	int top() {
// 		return v.back(); // or v[v.size()-1];
// 	}

// 	int size() {
// 		return v.size();
// 	}

// 	bool empty() {
// 		return v.empty(); // or v.size() == 0
// 	}

// };

template <typename T>
class stack {

	vector<T> v; // internal repr. of the dynamic stack

public :

	void push(T val) {
		v.push_back(val);
	}

	void pop() {
		if (v.size() == 0) {
			// stack is empty
			return;
		}
		v.pop_back();
	}

	T top() {
		return v.back(); // or v[v.size()-1];
	}

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty(); // or v.size() == 0
	}

};

int main() {

	stack<int> s;

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "isEmpty ? " << s.empty() << endl;

	return 0;
}