class Solution {
private:
    const int MOD = 1000000007;

    long long findGCD(long long x, long long y) {
        while (y != 0) {
            long long temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }

    long long findLCM(long long x, long long y) {
        return (x / findGCD(x, y)) * y;
    }

public:
    int nthMagicalNumber(int n, int a, int b) {

        long long left = min(a, b);
        long long right = 1LL * n * min(a, b);
        long long lcmValue = findLCM(a, b);

        while (left < right) {

            long long middle = left + (right - left) / 2;

            long long total =
                middle / a +
                middle / b -
                middle / lcmValue;

            if (total >= n)
                right = middle;
            else
                left = middle + 1;
        }

        return left % MOD;
    }
};
