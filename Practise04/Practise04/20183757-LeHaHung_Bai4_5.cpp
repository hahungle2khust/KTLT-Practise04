#include <iostream>
#include <vector>
#include <iomanip>
#include <list>
#include <stack>

using namespace std;

void dfs(vector< list<int> > adj) {
	stack<int> S;
	int n = adj.size();
	bool visited[100]{ false };
	S.push(1); 

	while (!S.empty()) {
		int k = S.top();
		S.pop();
		if (!visited[k]) {
			visited[k] = true;
			cout << k << endl;
			adj[k].reverse();
		}
		for (int i : adj[k]) {
			if (!visited[i]) {
				S.push(i);
			}
		}
	}
}

int main() {
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

	dfs(adj);
	return 0;
}
