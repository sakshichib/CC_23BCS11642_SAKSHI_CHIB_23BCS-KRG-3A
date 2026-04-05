#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; i++) cin >> names[i];
    
    vector<vector<bool>> edge(26, vector<bool>(26, false));
    vector<int> indegree(26, 0);
    bool impossible = false;
    
    for (int i = 0; i < n - 1; i++) {
        string& s = names[i];
        string& t = names[i + 1];
        int len = min(s.size(), t.size());
        bool found = false;
        
        for (int j = 0; j < len; j++) {
            if (s[j] != t[j]) {
                int a = s[j] - 'a';
                int b = t[j] - 'a';
                // a must come before b
                if (!edge[a][b]) {
                    edge[a][b] = true;
                    indegree[b]++;
                }
                found = true;
                break;
            }
        }
        
        if (!found && s.size() > t.size()) {
            impossible = true;
            break;
        }
    }
    
    if (impossible) {
        cout << "Impossible" << endl;
        return 0;
    }
    
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    string result = "";
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        result += (char)('a' + cur);
        
        for (int next = 0; next < 26; next++) {
            if (edge[cur][next]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }
    }
    
    if (result.size() < 26) {
        cout << "Impossible" << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}
