#include<iostream>

using namespace std;

int main() {

    int arr[][4] = {
        {10, 15, 20, 25},
        {30, 35, 40, 45},
        {50, 55, 60, 65}
    };

    int m = 3;
    int n = 4;

    for (int i = 0; i < m; i++) {
        for (int  j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int brr[2][2] = {{10, 20}, {30, 40}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int crr[][3] = {{10, 20, 30}, {40}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << crr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int drr[3][4] = {};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << drr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int err[3][4];

    memset(err, 0, sizeof(err));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << err[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    return 0;
}