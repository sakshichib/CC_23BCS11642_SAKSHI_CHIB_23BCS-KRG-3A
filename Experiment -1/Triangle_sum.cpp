#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int cnt = n;
    int i = 0; 
    while (cnt > 0) {
        for (int i = 0; i < cnt - 1; i++) {
            arr[i] = (arr[i] + arr[i + 1]) % 10;
        }
        cnt--;
    }
    cout << arr[0];

    return 0;
}
