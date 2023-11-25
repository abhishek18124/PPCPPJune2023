/*

    There are given n ropes of different lengths, we need to connect these ropes into one rope.
    The cost to connect two ropes is equal to the sum of their lengths. We need to connect the
    ropes with minimum cost.

    Example :

    Input : {4, 3, 2, 6}
    Output: 29

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

    cout << ((5 > 4 > 3) ^ 1);

    vector<int> ropeLengths = {4, 3, 2, 6};

    priority_queue<int, vector<int>, greater<int>> minHeap(ropeLengths.begin(), ropeLengths.end());

    // for (int i = 0; i < ropeLengths.size(); i++) {
    //     minHeap.push(ropeLengths[i]);
    // }

    int total = 0;

    // n-1 merge ops

    // time : (n-1).logn ~ O(nlogn)
    // space : O(n)

    while (minHeap.size() > 1) {

        int firstMin = minHeap.top();
        minHeap.pop(); // logn

        int secondMin = minHeap.top();
        minHeap.pop(); // logn

        total += (firstMin + secondMin);

        minHeap.push(firstMin + secondMin); // logn

    }

    cout << total << endl;

    return 0;
}
