/*

Given a phone keypad as shown below, and an n digit number, print all words which are possible by
pressing the n digits on the keypad.

 1()     2(abc) 3(def)
 4(ghi)  5(jkl) 6(mno)
 7(pqrs) 8(tuv) 9(wxyz)

*/

#include<iostream>

using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void generateWords(char* inp, char* out, int i, int j) {

    // base case
    if (inp[i] == '\0') { // or i == n
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // recursive case

    // take decisions for the remaining digits from i to n-1

    // or generate words for inp[i...n-1]

    // take decision for the ith digit

    int di = inp[i] - '0';

    if (di == 0 || di == 1) {
        // skip ith digit
        generateWords(inp, out, i + 1, j);
        return;
    }

    string options = keypad[di];
    for (char ck : options) {
        out[j] = ck;
        generateWords(inp, out, i + 1, j + 1);
    }



}

int main() {

    char inp[] = "203";
    char out[10];

    generateWords(inp, out, 0, 0);

    return 0;
}