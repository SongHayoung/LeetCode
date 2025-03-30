
long long dp[1010][1010];
class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        long long n = nums.size(), res = 1e18;
        vector<long long> preN(n + 1, 0), preC(n + 1, 0);
        for(int i=0;i<n;i++){
            preN[i + 1] = preN[i] + nums[i];
            preC[i + 1] = preC[i] + cost[i];
        }
        memset(dp,0x3f3f3f3f3f3f3f3fLL,sizeof(dp));
        dp[0][0] = 0;

        for(int m=1; m<=n; m++) {
            deque<pair<long long,long long>> A{{0,dp[m-1][0]}};
            auto calc = [&](pair<long long,long long>& A, long long x) {
                return A.first * x + A.second;
            };
            auto ok = [](pair<long long,long long>& A, pair<long long,long long>& B, pair<long long,long long>& C) {
                return 1. * (B.second - A.second) / (A.first - B.first) >= 1. * (C.second - A.second) / (A.first - C.first);
            };
            auto push = [&](pair<long long,long long> elem) {
                while(A.size() >= 2 and ok(A[A.size() - 2], A[A.size() - 1], elem)) A.pop_back();
                A.push_back(elem);
            };
            for(int i = 1; i <= n; i++) {
                long long X = preN[i] + k * m;
                while(A.size() >= 2 and calc(A[0],X) >= calc(A[1], X)) A.pop_front();
                dp[m][i] = preN[i] * preC[i] + preC[i] * k * m + calc(A[0], X);
                push({-preC[i], dp[m - 1][i]});
            }
            res = min(res, dp[m][n]);
        }

        return res;
    }
};