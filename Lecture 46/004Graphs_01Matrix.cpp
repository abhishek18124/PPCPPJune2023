// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

// 1. brute-force approach - time : O(m^2.n^2)

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				for (int ii = 0; ii < m; ii++) {
					for (int jj = 0; jj < n; jj++) {
						dist[ii][jj] = min(dist[ii][jj], abs(ii - i) + abs(jj - j));
					}
				}
			}
		}
	}

	return dist;

}

vector<vector<int>> updateMatrixOptimised(const vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dist(m, vector<int>(n, -1)); // -1 means distances of no vertex has been computed so far
	queue<pair<int, int>> q;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// (i, j)th cell is a source
				dist[i][j] = 0;
				q.push({i, j}); // q.push(make_pair(i, j))
			}
		}
	}

	int dx[] = {0, 0, -1, 1};
	int dy[] = {1, -1, 0, 0};

	while (!q.empty()) {

		pair<int, int> front = q.front(); q.pop();
		int i = front.first;
		int j =  front.second; // {i, j} represents the front node

		for (int k = 0; k < 4; k++) {

			int ii = i + dx[k];
			int jj = j + dy[k];

			if (ii >= 0 and ii < m and jj >= 0 and jj < n and dist[ii][jj] == -1) {

				// {ii, jj} is not yet visited since it dist is not calculated

				dist[ii][jj] = dist[i][j] + 1;
				q.push({ii, jj});

			}

		}

	}

	return dist;

}


int main() {

	vector<vector<int>> mat = {
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 0}
	};

	// vector<vector<int>> dist = updateMatrix(mat);

	vector<vector<int>> dist = updateMatrixOptimised(mat);

	for (vector<int> row : dist) {
		for (int col : row) {
			cout << col << " ";
		}
		cout << endl;
	}

	return 0;
}