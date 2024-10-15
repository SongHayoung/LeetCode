class Solution {
public:
    int minimumTime(vector<int>& A, vector<int>& B, int x) {
        vector<pair<long long, long long>> S;
        for(int i = 0; i < A.size(); i++) S.push_back({B[i], A[i]});
        sort(begin(S), end(S));
        vector<long long> dp(A.size() + 1, 0);
        for(auto& [b,a] : S) {
            for(int i = A.size() - 1; i >= 0; i--) {
                dp[i+1] = max(dp[i+1], dp[i] + (i + 1) * b + a);
            }
        }
        long long sum1 = accumulate(begin(B), end(B), 0ll), sum2 = accumulate(begin(A), end(A), 0ll);
        for(int i = 0; i <= A.size(); i++) {
            if(sum1 * i + sum2 - dp[i] <= x) return i;
        }
        return -1;
    }
};