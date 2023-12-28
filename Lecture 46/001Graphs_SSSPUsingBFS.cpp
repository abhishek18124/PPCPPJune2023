/*

Computing SSSP using the BFS algorithm in an unweighted graph.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;

template <typename T>
class graph {

	map<T, list<T>> neighbourMap; // to store the graph representation
	bool isDirected; // to indicate if the graph is directed or not

public :

	graph(bool isDirected = false) {
		this->isDirected = isDirected;
	}

	void addEdge(T u, T v) {

		// adds an edge b/w vertex u and v

		neighbourMap[u].push_back(v);

		if (!isDirected) {
			neighbourMap[v].push_back(u);
		}

	}

	void bfs(T s, T d) {

		map<T, int> distMap; // to store the mapping between vertices &
		// their shortest dist from the src vertex
		distMap[s] = 0;

		map<T, T> parentMap;
		parentMap[s] = s; // assume parent of 's' is 's'

		unordered_set<T> visited; // to keep track of visited vertices
		queue<T> q; // to keep track of visited & un-explored vertices

		// mark 's' as visited
		visited.insert(s);
		q.push(s);

		while (!q.empty()) {
			T front = q.front();
			q.pop();

			// explore 'front'

			list<T> neighbourList = neighbourMap[front];
			for (T neighbour : neighbourList) {
				if (visited.find(neighbour) == visited.end()) {

					visited.insert(neighbour);
					q.push(neighbour);

					distMap[neighbour] = distMap[front] + 1; // since we are visiting 'neighbour' because of 'front', in the bfs tree 'front' is the parent of 'neighbour'
					parentMap[neighbour] = front;
				}
			}

		}

		for (pair<T, int> p : distMap) {
			T vertexLabel = p.first;
			int shortestDist = p.second;
			cout << vertexLabel << " " << shortestDist << endl;
		}

		cout << "length of the shortest path from " << s << " to " << d << " = " << distMap[d] << endl;

		for (pair<T, T> p : parentMap) {
			T vertexLabel = p.first;
			T parentLabel = p.second;
			cout << vertexLabel << " " << parentLabel << endl;
		}

		vector<T> path;

		T temp = d;

		while (parentMap[temp] != temp) {

			// cout << temp << "<-";
			path.push_back(temp);
			temp = parentMap[temp];

		}

		// cout << temp << endl;
		path.push_back(temp); // path.push_back(s)

		reverse(path.begin(), path.end());

		for (T vertex : path) {
			cout << vertex << " ";
		}

		cout << endl;
	}
};


int main() {

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('B', 'D');
	g.addEdge('B', 'E');
	g.addEdge('C', 'E');
	g.addEdge('C', 'F');
	g.addEdge('D', 'G');
	g.addEdge('E', 'G');
	g.addEdge('E', 'H');
	g.addEdge('F', 'H');
	g.addEdge('G', 'I');
	g.addEdge('H', 'I');

	g.bfs('A', 'I');

	return 0;
}