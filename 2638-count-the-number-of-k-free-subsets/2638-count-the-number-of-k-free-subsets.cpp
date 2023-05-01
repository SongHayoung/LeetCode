class Solution {
    long long dp[2][55];
    void helper(int n) {
        if(dp[0][n] != -1) return;
        helper(n-1);
        dp[0][n] = dp[0][n-1] + dp[1][n-1];
        dp[1][n] = dp[0][n-1];
    }
    long long query(int n) {
        helper(n);
        return dp[0][n] + dp[1][n];
    }
public:
    long long countTheNumOfKFreeSubsets(vector<int>& A, int k) {
        memset(dp, -1, sizeof dp);
        dp[1][1] = dp[0][1] = 1;
        unordered_map<int, int> freq;
        sort(begin(A), end(A));
        for(auto n : A) {
            if(freq.count(n - k)) {
                freq[n] = freq[n-k] + 1;
                freq.erase(n-k);
            } else freq[n] = 1;
        }
        long long res = 1;
        for(auto [k,v] : freq) res *= query(v);
        return res;
    }
};