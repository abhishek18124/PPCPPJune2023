
#include<iostream>
#include<queue>

using namespace std;

string reorganizeString(string s) {

    int freqMap[26] = {};

    for (char ch : s) {
        freqMap[ch - 'a']++;
    }

    priority_queue<pair<int, char>> maxHeap;

    for (int i = 0; i < 26; i++) {

        if (freqMap[i] > 0) {

            maxHeap.push({freqMap[i], i + 'a'});

        }

    }

    // while (!maxHeap.empty()) {

    //     pair<int, char> maxPair = maxHeap.top();
    //     maxHeap.pop();

    //     cout << maxPair.first << " " << maxPair.second << endl;

    // }

    // cout << endl;

    string out = "";

    while (!maxHeap.empty()) {

        if (maxHeap.size() == 1) {

            pair<int, char> maxPair = maxHeap.top();
            maxHeap.pop();

            if (maxPair.first > 1) {

                // s cannot be reorganised

                out = "";

            } else {

                // s can be reorganised

                out += maxPair.second;

            }

        } else {

            pair<int, char> firstMaxPair = maxHeap.top();
            maxHeap.pop();

            pair<int, char> secondMaxPair = maxHeap.top();
            maxHeap.pop();

            out += firstMaxPair.second;
            firstMaxPair.first--;

            out += secondMaxPair.second;
            secondMaxPair.first--;

            if (firstMaxPair.first > 0) {
                maxHeap.push(firstMaxPair);
            }

            if (secondMaxPair.first > 0) {
                maxHeap.push(secondMaxPair);
            }

        }


    }

    return out;

}

int main() {

    string str = "aaaaabbbbcccdd";

    cout << reorganizeString(str) << endl;

    return 0;
}