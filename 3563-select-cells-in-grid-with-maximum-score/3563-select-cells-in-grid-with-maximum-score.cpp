class Solution {
public:
    int maxScore(vector<vector<int>>& A) {
       int n = A.size();
       vector<vector<bool>> dp(1<<n, vector<bool>(101));
       for(int i = 0; i < n; i++) {
           sort(rbegin(A[i]), rend(A[i]));
       }
       for(int i = 0; i < 1<<n; i++) {
           for(int j = 0; j < n; j++) {
               if(!((i>>j) & 1)) continue;
               int oth = i ^ (1<<j);
               vector<bool> now = dp[i ^ (1<<j)];
               for(auto& x : A[j]) {
                   if(now[100-x]) continue;
                   now[100-x] = 1;
                   break;
               }
               dp[i] = max(dp[i], now);
           }
       }
       int res = 0;
       for(int i = 0; i <= 100; i++) if(dp.back()[100-i]) {
           res += i;
       }
       return res;
    }
};