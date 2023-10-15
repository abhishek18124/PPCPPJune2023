/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to

	> generate all the paths from src to dst

such at each step the rat can only move in the right or down direction.

Constraint

 1 <= m, n < 10

Example
	Input :

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}

	Output :

	       {"1100", {"1000", {"1000",
            "0100",	 "1100",  "1000",
            "0110",  "0110",  "1110",
            "0011"}  "0011"}  "0011"}

*/

#include<iostream>

using namespace std;

void printPath(char path[][10], int m, int n) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

}

// void f(char maze[][10], char path[][10], int m, int n, int i, int j) {

// 	// base case

// 	if (i == -1 || i == m || j == n || j == -1) { // rat has gone outside the maze
// 		return;
// 	}

// 	if (i == m - 1 and j == n - 1) {
// 		// print path
// 		path[i][j] = '1'; // mark the destintion cell as part of the path
// 		printPath(path, m, n);
// 		path[i][j] = '0';
// 		return;
// 	}

// 	if (maze[i][j] == 'X') {
// 		return;
// 	}

// 	if (path[i][j] == '1') {
// 		// (i, j)th cell is already part of the path
// 		return;
// 	}

// 	// recursive case

// 	path[i][j] = '1';

// 	// decide the next step

// 	// move right

// 	f(maze, path, m, n, i, j + 1);

// 	// move left

// 	f(maze, path, m, n, i, j - 1);

// 	// move down

// 	f(maze, path, m, n, i + 1, j);

// 	// move up

// 	f(maze, path, m, n, i - 1, j);

// 	path[i][j] = '0';

// }


// void f(char maze[][10], char path[][10], int m, int n, int i, int j) {

// 	// base case

// 	if (i == -1 || i == m || j == n || j == -1) { // rat has gone outside the maze
// 		return;
// 	}

// 	if (i == m - 1 and j == n - 1) {
// 		// print path
// 		path[i][j] = '1'; // mark the destintion cell as part of the path
// 		printPath(path, m, n);
// 		path[i][j] = '0';
// 		return;
// 	}

// 	if (maze[i][j] == 'X') {
// 		return;
// 	}

// 	// recursive case

// 	path[i][j] = '1';
// 	maze[i][j] = 'X';

// 	// decide the next step

// 	// move right

// 	f(maze, path, m, n, i, j + 1);

// 	// move left

// 	f(maze, path, m, n, i, j - 1);

// 	// move down

// 	f(maze, path, m, n, i + 1, j);

// 	// move up

// 	f(maze, path, m, n, i - 1, j);

// 	path[i][j] = '0';
// 	maze[i][j] = '0';

// }

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void f(char maze[][10], char path[][10], int m, int n, int i, int j) {

	// base case

	if (i == -1 || i == m || j == n || j == -1) { // rat has gone outside the maze
		return;
	}

	if (i == m - 1 and j == n - 1) {
		// print path
		path[i][j] = '1'; // mark the destintion cell as part of the path
		printPath(path, m, n);
		path[i][j] = '0';
		return;
	}

	if (maze[i][j] == 'X') {
		return;
	}

	// recursive case

	path[i][j] = '1';
	maze[i][j] = 'X';

	// decide the next step

	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		f(maze, path, m, n, nx, ny);
	}

	path[i][j] = '0';
	maze[i][j] = '0';

}


int main() {

	char maze[][10] = {"0X00",
	                   "000X",
	                   "X0X0",
	                   "X00X",
	                   "XX00"
	                  };

	char path[][10] = {"0000",
	                   "0000",
	                   "0000",
	                   "0000",
	                   "0000"
	                  };
	int m = 5;
	int n = 4;

	f(maze, path, m, n, 0, 0);

	return 0;
}
