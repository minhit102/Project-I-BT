#include<bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i <= n; i++) {
        d[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    // Output the result
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) {
                cout << -1 << " ";
            } else {
                cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
