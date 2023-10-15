#include<iostream>
#include<vector>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool searchWord(vector<vector<char>>& board, string word, int m, int n, int i, int j, int k) {

	// base case

	if (k == word.size()) {
		// you've found the word
		return true;
	}

	if (i == -1 || i == m || j == -1 || j == n) {
		return false;
	}

	if (board[i][j] != word[k]) {
		return false;
	}

	// recursive case

	board[i][j] = '#'; // block the (i, j)th cell

	for (int l = 0; l < 4; l++) {
		int nx = i + dx[l];
		int ny = j + dy[l];
		if (searchWord(board, word, m, n, nx, ny, k + 1)) {
			return true;
		}
	}

	board[i][j] = word[k]; // backtrack

	return false;


}

bool exist(vector<vector<char>>& board, string word) {
	int m = board.size();
	int n = board[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == word[0]) {
				if (searchWord(board, word, m, n, i, j, 0)) {
					return true;
				}
			}
		}
	}

	return false;
}


int main() {

	vector<vector<char>> board = {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};

	string word = "ABCCEX";

	exist(board, word) ? cout << "true" << endl :
	                          cout << "false" << endl;

	return 0;
}