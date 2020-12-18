#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> ii;
int findN(const vector< vector< pair<int, int> > >& adj) {
    int maxN = 0;
    for (vector<ii> v : adj) {
        for (ii i : v) {
            if (i.first > maxN) maxN = i.first;
        }
    }
    return maxN + 1;
}
struct cmp {
    bool operator()(ii a, ii b) {
        return a.second < b.second;
    }
};
vector<int> dijkstra(const vector< vector< pair<int, int> > >& adj) {
    //////////////////

    int n = findN(adj);
    int d[100000];
    for (int i = 0; i < n; i++) {
        d[i] = INT_MAX;
    }
    d[0] = 0;
    priority_queue<ii, vector<ii>, cmp> pQ;
    pQ.push(ii(0, 0));

    while (pQ.size()) {
        int u = pQ.top().first;
        int du = pQ.top().second;
        pQ.pop();
        if (du != d[u]) continue;
        int N = adj[u].size();
        for (int i = 0; i < N; i++) {
            int v = adj[u][i].first;
            int uv = adj[u][i].second;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pQ.push(ii(v, d[v]));
            }
        }
    }
    vector<int> res(d, d + n);
    return res;
}

int main() {
    cout << "Ho va ten: Le Ha Hung" << endl;
    cout << "MSSV: 20183757" << endl;
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj](int u, int v, int w) {
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}
