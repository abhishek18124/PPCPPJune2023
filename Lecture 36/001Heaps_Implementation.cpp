/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class minHeap {

	vector<int> v; // internal representation of the minHeap

	// time : O(logn)
	// space : O(logn) due to function call stack

	void heapify(int i) {

		// fixes the heap property at the ith index

		int minIdx = i;

		int leftIdx = 2 * i + 1;

		if (leftIdx < v.size() and v[leftIdx] < v[minIdx]) {
			minIdx = leftIdx;
		}

		int rightIdx = 2 * i + 2;
		if (rightIdx < v.size() and v[rightIdx] < v[minIdx]) {
			minIdx = rightIdx;
		}

		if (minIdx != i) {
			swap(v[i], v[minIdx]);
			heapify(minIdx);
		}

	}

public :

	// time : O(logn)

	void push(int val) {
		v.push_back(val);

		int childIdx = v.size() - 1;
		int parentIdx = childIdx % 2 == 1 ? childIdx / 2 : childIdx / 2 - 1;

		while (childIdx > 0 and v[childIdx] < v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx = childIdx % 2 == 1 ? childIdx / 2 : childIdx / 2 - 1;
		}

	}

	// O(logn)

	void pop() {
		swap(v[0], v[v.size() - 1]); // O(1)
		v.pop_back(); // O(1)
		heapify(0); // O(logn)
	}

	int top() {
		return v[0];
	}

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty(); // or v.size() == 0
	}


};

int main() {

	minHeap m;

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl;

	while (!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}