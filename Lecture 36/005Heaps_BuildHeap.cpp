/*

	Given an array of n integers, design a O(n) algorirthm to build a max_heap in-place.

*/

#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& v, int n, int i) {

	// fixes the heap property at the ith index

	int minIdx = i;

	int leftIdx = 2 * i + 1;

	if (leftIdx < n and v[leftIdx] < v[minIdx]) {
		minIdx = leftIdx;
	}

	int rightIdx = 2 * i + 2;
	if (rightIdx < n and v[rightIdx] < v[minIdx]) {
		minIdx = rightIdx;
	}

	if (minIdx != i) {
		swap(v[i], v[minIdx]);
		heapify(v, n, minIdx);
	}

}


int main() {

	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();

	// viz v[] as a CBT and to make it a minHeap, invoke heapify on all the indices starting from leaf (n-1) to the root node (0)

	for (int i = n - 1; i >= 0; i--) {
		heapify(v, n, i);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}





