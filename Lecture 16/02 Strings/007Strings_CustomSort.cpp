#include<iostream>
#include<algorithm>

using namespace std;

/*

	return true when swap is not needed

	return false when swap is needed

	assume 'a' is currenly present at a position in arr[] which is less than position of b

*/

bool myStringGreaterComparator(string a, string b) {
	if (a > b) {
		// you don't need to do a swap to the sort the arr[] in dec. order
		return true;
	}
	// you need to do a swap to the sort the arr[] in dec. order
	return false;
}

bool myIntegerGreaterComparator(int a, int b) {
	if (a > b) {
		// you don't need to do a swap to the sort the arr[] in dec. order
		return true;
	}
	// you need to do a swap to the sort the arr[] in dec. order
	return false;
}

int main() {

	string arr[] = {"abc", "ghi", "jkl", "def"};
	int n = 4;

	// sort(arr, arr + n);

	// sort(arr, arr + n, greater<string>());

	sort(arr, arr + n, myStringGreaterComparator);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	int brr[] = {10, 40, 30, 20, 50};

	int m = 5;

	// sort(brr, brr + m);

	// sort(brr, brr + m, greater<int>());

	sort(brr, brr + m, myIntegerGreaterComparator);

	for (int i = 0; i < m; i++) {
		cout << brr[i] << " ";
	}

	cout << endl;

	return 0;
}