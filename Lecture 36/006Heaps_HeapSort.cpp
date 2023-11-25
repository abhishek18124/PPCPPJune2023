/*

	Given an array of n integers, sort the array using heap sort algorithm.

*/

#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& v, int n, int i) {

	// fixes the heap property at the ith index

	int maxIdx = i;

	int leftIdx = 2 * i + 1;

	if (leftIdx < n and v[leftIdx] > v[maxIdx]) {
		maxIdx = leftIdx;
	}

	int rightIdx = 2 * i + 2;
	if (rightIdx < n and v[rightIdx] > v[maxIdx]) {
		maxIdx = rightIdx;
	}

	if (maxIdx != i) {
		swap(v[i], v[maxIdx]);
		heapify(v, n, maxIdx);
	}

}


int main() {

	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();

	// n steps

	for (int i = n - 1; i >= 0; i--) {
		heapify(v, n, i);
	}

	// nlogn steps

	int heapsize = n;
	while (heapsize > 1) {
		swap(v[0], v[heapsize - 1]);
		heapsize--;
		heapify(v, heapsize, 0); // logn since we are doing heapify on the root node
	}

	// time : O(nlogn)
	// space : O(logn) due to heapify function call stack // If you implement heapify using an iterative algo. it will take O(1) space (h.w.)

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}
