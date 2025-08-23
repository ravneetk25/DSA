#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int parent[MAXN];
pair<int, int> bfs(int start, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthest = start;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
                if (dist[neighbor] > dist[farthest])
                    farthest = neighbor;
            }
        }
    }
    return {farthest, dist[farthest]};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int u = bfs(1, n).first;
    int v = bfs(u, n).first;
    int diameter = bfs(u, n).second;

    set<int> path;
    for (int x = v; x != u; x = parent[x])
        path.insert(x);
    path.insert(u);

    vector<int> dist(n + 1, -1);
    queue<int> q;
    for (int node : path) {
        dist[node] = 0;
        q.push(node);
    }

    int max_extra = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                max_extra = max(max_extra, dist[neighbor]);
                q.push(neighbor);
            }
        }
    }

    cout << diameter + max_extra << '\n';
    return 0;
}
