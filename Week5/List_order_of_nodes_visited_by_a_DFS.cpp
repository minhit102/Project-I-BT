#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& gh, vector<bool>& check, vector<int>& kqua, int node) {
    check[node] = true;
    kqua.push_back(node);
    vector<int> nbrors = gh[node];
    sort(nbrors.begin(), nbrors.end());  // Sort nbrors in lexicoghic order

    for (int nbror : nbrors) {
        if (!check[nbror]) {
            dfs(gh, check, kqua, nbror);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gh(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gh[u].push_back(v);
        gh[v].push_back(u);
    }

    vector<bool> check(n + 1, false);
    vector<int> kqua;

    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            dfs(gh, check, kqua, i);
        }
    }

    for (int i = 0; i < kqua.size(); i++) {
        cout << kqua[i];
        if (i < kqua.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}