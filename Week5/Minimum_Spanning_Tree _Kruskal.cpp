#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100001;

struct Eg {
    int v, w;
    Eg(int vt, int wt) : v(vt), w(wt) {}
};

vector<Eg> graph[MAXN];
bool ved[MAXN];

int prim(int n) {
    int minST = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 1}); // Start from vt 1

    while (!pq.empty()) {
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (ved[u])
            continue;

        minST += wt;
        ved[u] = true;

        for (const Eg& Eg : graph[u]) {
            int v = Eg.v;
            int w = Eg.w;
            if (!ved[v])
                pq.push({w, v});
        }
    }

    return minST;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    int minST = prim(N);

    cout << minST << endl;

    return 0;
}
