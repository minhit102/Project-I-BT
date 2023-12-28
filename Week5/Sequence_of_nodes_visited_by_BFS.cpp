#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& gh, vector<bool>& vted, vector<int>& rlt, int start) {
    queue<int> q;
    q.push(start);
    vted[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        rlt.push_back(node);

        // Sort nbrors in lexicoghic order
        vector<int> nbrors = gh[node];
        sort(nbrors.begin(), nbrors.end());

        for (int nbror : nbrors) {
            if (!vted[nbror]) {
                vted[nbror] = true;
                q.push(nbror);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gh(n + 1);
    vector<bool> vted(n + 1, false);
    vector<int> rlt;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        gh[u].push_back(v);
        gh[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        // Sort initial edges in lexicoghic order
        sort(gh[i].begin(), gh[i].end());
    }

    for (int i = 1; i <= n; i++) {
        if (!vted[i]) {
            bfs(gh, vted, rlt, i);
        }
    }

    for (int i = 0; i < rlt.size(); i++) {
        cout << rlt[i];
        if (i < rlt.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}
