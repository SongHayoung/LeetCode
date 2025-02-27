class Solution {
    unordered_map<int, int> mp;
    int dp[1010][1010];
    int helper(vector<int>& A, int i, int j) {
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 2;
        
        if(mp.count(A[i] + A[j]))
            dp[i][j] = 1 + helper(A, j, mp[A[i] + A[j]]);
        
        return dp[i][j];
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < arr.size(); i++) mp[arr[i]] = i;
        memset(dp, -1, sizeof dp);
        int res = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                res = max(res, helper(arr, i, j));
            }
        }
        
        return res > 2 ? res : 0;
    }
};