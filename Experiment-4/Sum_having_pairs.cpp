int solve(vector<int>& A) {

    const int MOD = 1000000007;
    long long ans = 0;
    int n = A.size();

    for(int bit = 0; bit < 32; bit++) {

        long long ones = 0;

        for(int x : A)
            if(x & (1LL << bit))
                ones++;

        long long zeros = n - ones;

        ans = (ans + (ones * zeros % MOD) * 2) % MOD;
    }

    return ans;
}
