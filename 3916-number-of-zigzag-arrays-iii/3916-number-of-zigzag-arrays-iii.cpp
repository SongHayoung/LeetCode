class Solution {
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;
        while(b) {
            if(b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long calc(int n, int m) {
        if(m == 0) return 0;

        vector<long long> dp(m, 1);

        for(int len = 1; len < n; len++) {
            long long sum = 0;

            for(int i = 0; i < m; i++) {
                long long cur = dp[i];
                dp[i] = sum;
                sum = (sum + cur) % MOD;
            }

            reverse(dp.begin(), dp.end());
        }

        long long res = 0;
        for(auto x : dp)
            res = (res + x) % MOD;

        return res * 2 % MOD;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        long long x = 1LL * r - l + 1;

        vector<long long> y(n + 1);

        for(int m = 0; m <= n; m++)
            y[m] = calc(n, m);

        if(x <= n)
            return y[x];

        vector<long long> fact(n + 1, 1), invFact(n + 1, 1);

        for(int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = power(fact[n], MOD - 2);

        for(int i = n; i; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        vector<long long> pre(n + 2, 1), suf(n + 2, 1);

        for(int i = 0; i <= n; i++)
            pre[i + 1] = pre[i] * ((x - i) % MOD) % MOD;

        for(int i = n; i >= 0; i--)
            suf[i] = suf[i + 1] * ((x - i) % MOD) % MOD;

        long long res = 0;

        for(int i = 0; i <= n; i++) {
            long long num = pre[i] * suf[i + 1] % MOD;

            long long den =
                invFact[i] * invFact[n - i] % MOD;

            if((n - i) & 1)
                den = MOD - den;

            res = (res + y[i] * num % MOD * den) % MOD;
        }

        return res;
    }
};