#include <iostream>
#include<iomanip>
#include <vector>
#include <queue>
#include <list>

using namespace std;

void bfs(vector< list<int> > adj) {
	queue<int> Q;
	int n = adj.size();
	int visited[100]{ 0 };
	Q.push(1); 
	visited[1] = 2;

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		cout << u << endl;
		for (int i : adj[u]) {
			if (visited[i] == 0) {
				Q.push(i);
				visited[i] = 1;
			}
		}
		visited[u] = 2;
	}
}

int main() {
	cout << "Ho va ten: Le Ha Hung" << endl;
	cout << "MSSV: 20183757" << endl;
	int n = 7;
	vector< list<int> > adj;
	adj.resize(n + 1);
	adj[1].push_back(2);
	adj[2].push_back(4);
	adj[1].push_back(3);
	adj[3].push_back(4);
	adj[3].push_back(5);
	adj[5].push_back(2);
	adj[2].push_back(7);
	adj[6].push_back(7);

	bfs(adj);
	return 0;
}

