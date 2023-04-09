class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, INT_MAX));
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> row[m];
        dp[0][0] = 1;
        for(int i = 0; i < n; i++) {
            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> col;
            for(int j = 0; j < m; j++) {
                while(row[j].size() and row[j].top().second < i) row[j].pop();
                while(col.size() and col.top().second < j) col.pop();
                if(row[j].size()) dp[i][j] = min(dp[i][j], row[j].top().first + 1);
                if(col.size()) dp[i][j] = min(dp[i][j], col.top().first + 1);
                row[j].push({dp[i][j], i + A[i][j]});
                col.push({dp[i][j], j + A[i][j]});
            }
        }
        return dp[n-1][m-1] >= INT_MAX ? -1 : dp[n-1][m-1];
    }
};