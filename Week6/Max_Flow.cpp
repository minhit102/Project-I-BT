#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

bool bfs(vector<vector<int>>& graph, int source, int sink, vector<int>& parent) {
    int V = graph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[sink];
}

int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int V = graph.size();
    vector<int> parent(V);
    int maxFlow = 0;

    while (bfs(graph, source, sink, parent)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, graph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= pathFlow;
            graph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int N, M;
    cin >> N >> M;
    int s, t;
    cin >> s >> t;

    vector<vector<int>> graph(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u - 1][v - 1] = c;
    }

    int maxFlow = fordFulkerson(graph, s - 1, t - 1);

    cout << maxFlow << endl;

    return 0;
}
