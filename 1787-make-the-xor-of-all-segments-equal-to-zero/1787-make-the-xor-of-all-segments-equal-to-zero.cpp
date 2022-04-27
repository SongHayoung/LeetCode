#define INF 987654321
class Solution {
    int dp[2000][2000];
    int helper(vector<int>& S, vector<unordered_map<int,int>>& F, int p, int x) {
        if(p == S.size()) return x ? INF : 0;
        if(dp[p][x] != -1) return dp[p][x];
        int& res = dp[p][x] = INF;
        for(auto& [n, f] : F[p]) {
            res = min(res,
                      S[p] - f + helper(S,F,p+1,n^x)
                     );
        }
        return res;
    }
public:
    int minChanges(vector<int>& A, int k) {
        memset(dp, -1, sizeof dp);
        vector<int> sum(k), best(k);
        vector<unordered_map<int,int>> freq(k);
        int n = A.size(), res = INF, change = 0;
        for(int i = 0; i < n; i++) {
            sum[i % k]++;
            best[i % k] = max(best[i % k], ++freq[i % k][A[i]]);
        }
        
        for(int i = 0; i < k; i++) {
            change += sum[i] - best[i];
        }
        
        for(int i = 0; i < k; i++) {
            res = min({res,
                       change + best[i],
                       helper(sum, freq, 0, 0)
                      });
        }
        return res;
    }
};