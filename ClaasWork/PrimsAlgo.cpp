#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    vector<bool> visited(n + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 1});

    long long mst_cost = 0;

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;

        visited[node] = true;
        mst_cost += weight;

        for (auto [w, next] : adj[node]) {
            if (!visited[next]) {
                pq.push({w, next});
            }
        }
    }

    cout << mst_cost << "\n";
}
