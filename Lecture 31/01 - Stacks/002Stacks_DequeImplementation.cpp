#include<iostream>
#include<deque>

using namespace std;

template <typename T>
class stack {

	deque<T> d; // assume back-end of the deqeue works as the top of the stack

public :

	void push(T val) {
		d.push_back(val);
	}

	void pop() {
		if (d.empty()) {
			return;
		}

		d.pop_back();
	}

	int size() {
		return d.size();
	}

	T top() {
		return d.back(); // or d[d.size()-1]
	}

	bool empty() {
		return d.empty(); // or d.size() == 0
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