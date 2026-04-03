#include <bits/stdc++.h>
using namespace std;

vector<int> adj[26];
int visited[26]; // 0 = unvisited, 1 = visiting, 2 = visited
string ans;

bool dfs(int node) {
    visited[node] = 1;
    
    for (auto it : adj[node]) {
        if (visited[it] == 0) {
            if (!dfs(it)) return false;
        }
        else if (visited[it] == 1) {
            return false; // cycle detected
        }
    }
    
    visited[node] = 2;
    ans.push_back(node + 'a');
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // build graph
    for (int i = 0; i < n - 1; i++) {
        string a = v[i];
        string b = v[i + 1];
        
        int len = min(a.size(), b.size());
        bool found = false;
        
        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                adj[a[j] - 'a'].push_back(b[j] - 'a');
                found = true;
                break;
            }
        }
        
        if (!found && a.size() > b.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    // topological sort
    for (int i = 0; i < 26; i++) {
        if (visited[i] == 0) {
            if (!dfs(i)) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}