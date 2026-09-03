class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        vector<long long> A;
        for(int x : requests) {
            if(x != start) A.push_back(x);
        }

        int m = A.size();
        A.push_back(start);
        sort(A.begin(), A.end());

        int s = lower_bound(A.begin(), A.end(), start) - A.begin();
        int sz = m + 1;
        const long long inf = LLONG_MAX / 4;

        vector<vector<array<long long, 2>>> dp(
            sz, vector<array<long long, 2>>(sz, {inf, inf})
        );

        dp[s][s][0] = dp[s][s][1] = 0;

        for(int len = 1; len <= sz; len++) {
            int served = len - 1;
            int remaining = m - served;

            for(int l = 0; l + len - 1 < sz; l++) {
                int r = l + len - 1;
                if(l > s or r < s) continue;

                if(l > 0) {
                    dp[l - 1][r][0] = min(
                        dp[l - 1][r][0],
                        dp[l][r][0] + (A[l] - A[l - 1]) * remaining
                    );

                    dp[l - 1][r][0] = min(
                        dp[l - 1][r][0],
                        dp[l][r][1] + (A[r] - A[l - 1]) * remaining
                    );
                }

                if(r + 1 < sz) {
                    dp[l][r + 1][1] = min(
                        dp[l][r + 1][1],
                        dp[l][r][0] + (A[r + 1] - A[l]) * remaining
                    );

                    dp[l][r + 1][1] = min(
                        dp[l][r + 1][1],
                        dp[l][r][1] + (A[r + 1] - A[r]) * remaining
                    );
                }
            }
        }

        return min(dp[0][sz - 1][0], dp[0][sz - 1][1]);
    }
};