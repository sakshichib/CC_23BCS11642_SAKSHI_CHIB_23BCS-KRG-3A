#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int computeGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int maxResult = 0;

        for (int i = 0; i < n; i++) {
            map<pair<int,int>, int> slopeCount;
            int samePoint = 1;

            for (int j = i + 1; j < n; j++) {
                int deltaX = points[j][0] - points[i][0];
                int deltaY = points[j][1] - points[i][1];

                if (deltaX == 0 && deltaY == 0) {
                    samePoint++;
                    continue;
                }

                int gcd = computeGCD(deltaX, deltaY);
                deltaX /= gcd;
                deltaY /= gcd;

                if (deltaX < 0) {
                    deltaX *= -1;
                    deltaY *= -1;
                } else if (deltaX == 0) {
                    deltaY = 1;
                } else if (deltaY == 0) {
                    deltaX = 1;
                }

                slopeCount[{deltaX, deltaY}]++;
            }

            int localMax = 0;
            for (auto &entry : slopeCount) {
                localMax = max(localMax, entry.second);
            }

            maxResult = max(maxResult, localMax + samePoint);
        }

        return maxResult;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> pts = {{1,1}, {2,2}, {3,3}, {3,4}, {5,6}};

    cout << "Max points on same line: "
         << obj.maxPoints(pts) << endl;

    return 0;
}
