/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {

public:
	string name;
	int age;

	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}

};

class ageComparator {

public :

	// assume 'b' to be the newly inserted node and 'a' to be its parent

	// return true when you need a swap otherwise return false

	bool operator()(customer a, customer b) {
		if (b.age < a.age) {
			// do a swap to build a minHeap based on age
			return true;
		}
		// don't do a swap to build a minHeap based on age
		return false;
	}

};


class nameComparator {

public :

	// assume 'b' to be the newly inserted node and 'a' to be its parent

	// return true when you need a swap otherwise return false

	bool operator()(customer a, customer b) {
		if (b.name < a.name) {
			// do a swap to build a minHeap based on name
			return true;
		}
		// don't do a swap to build a minHeap based on name
		return false;
	}

};
int main() {

	// priority_queue<customer, vector<customer>, ageComparator> m;
	priority_queue<customer, vector<customer>, nameComparator> m;

	m.push(customer("parth", 20));
	m.push(customer("sartak", 19));
	m.push(customer("anamika", 21));
	m.push(customer("tejasav", 18));

	cout << m.size() << endl;

	while (!m.empty()) {
		customer c = m.top();
		cout << c.name << " " << c.age << endl;
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}