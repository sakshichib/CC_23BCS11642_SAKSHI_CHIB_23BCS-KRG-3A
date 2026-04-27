#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int stalls[n];
        for (int i = 0; i < n; i++)
            cin >> stalls[i];
        sort(stalls, stalls + n);
        int low = 1, high = stalls[n - 1] - stalls[0], ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int count = 1, last_position = stalls[0];
            for (int i = 1; i < n; i++)
            {
                if (stalls[i] - last_position >= mid)
                {
                    count++;
                    last_position = stalls[i];
                }
            }
            if (count >= c)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}