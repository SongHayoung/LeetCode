
class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        map<long long, long long> at;
        for(auto& r : requests) {
            at[r[1]] = max(at[r[1]], (long long)r[0]);
        }

        vector<pair<long long, long long>> A;
        for(auto& [pos, t] : at) A.push_back({pos, t});

        int m = A.size();
        const long long inf = LLONG_MAX / 4;

        auto check = [&](long long finish) {
            long long dp[555][555][2];

            for(int l = 0; l < m; l++) {
                for(int r = 0; r < m; r++) {
                    dp[l][r][0] = dp[l][r][1] = inf;
                }
            }

            for(int i = 0; i < m; i++) {
                if(A[i].second <= finish) {
                    dp[i][i][0] = dp[i][i][1] = 0;
                }
            }

            for(int len = 1; len <= m; len++) {
                for(int l = 0; l + len - 1 < m; l++) {
                    int r = l + len - 1;

                    if(l > 0) {
                        long long arrive = min(
                            dp[l][r][0] + A[l].first - A[l - 1].first,
                            dp[l][r][1] + A[r].first - A[l - 1].first
                        );

                        if(arrive <= finish - A[l - 1].second) {
                            dp[l - 1][r][0] = min(
                                dp[l - 1][r][0],
                                arrive
                            );
                        }
                    }

                    if(r + 1 < m) {
                        long long arrive = min(
                            dp[l][r][0] + A[r + 1].first - A[l].first,
                            dp[l][r][1] + A[r + 1].first - A[r].first
                        );

                        if(arrive <= finish - A[r + 1].second) {
                            dp[l][r + 1][1] = min(
                                dp[l][r + 1][1],
                                arrive
                            );
                        }
                    }
                }
            }

            return min(
                dp[0][m - 1][0] + abs(A[0].first - start),
                dp[0][m - 1][1] + abs(A[m - 1].first - start)
            ) <= finish;
        };

        long long l = 0, r = 3000000000LL, res = r;

        while(l <= r) {
            long long m = l + (r - l) / 2;

            if(check(m)) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }

        return res;
    }
};