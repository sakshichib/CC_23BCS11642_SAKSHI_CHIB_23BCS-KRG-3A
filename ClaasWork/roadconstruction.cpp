#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int a, int b, int &maxSize) {
        a = find(a);
        b = find(b);

        if (a != b) {
            // union by size
            if (size[a] < size[b]) swap(a, b);

            parent[b] = a;
            size[a] += size[b];

            maxSize = max(maxSize, size[a]);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    int components = n;
    int maxSize = 1;

    while (m--) {
        int a, b;
        cin >> a >> b;

        int rootA = dsu.find(a);
        int rootB = dsu.find(b);

        if (rootA != rootB) {
            dsu.unite(a, b, maxSize);
            components--;
        }

        cout << components << " " << maxSize << "\n";
    }
}
