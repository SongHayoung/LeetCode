class Solution {
    //k, r, c
    int dp[10][51][51];
    int n, m, mod = 1e9+7;
    bool valid(vector<string>& pizza, int r, int c) {
        for(int i = r; i < n; i++) {
            for(int j = c; j < m; j++) {
                if(pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }
    int solution(vector<string>& p, int k, int r, int c) {
        if(r == n or c == m) return 0;
        if(dp[k][r][c] != -1) return dp[k][r][c];
        if(!k) return dp[k][r][c] = valid(p,r,c);

        int nr = r, nc = c;
        bool brk = false;
        for(; nr < n and !brk; nr++) {
            for(int i = c; i < m and !brk; i++) {
                if(p[nr][i] == 'A') brk = true;
            }
        }

        brk = false;
        for(; nc < m and !brk; nc++) {
            for(int i = r; i < n and !brk; i++) {
                if(p[i][nc] == 'A') brk = true;
            }
        }

        dp[k][r][c] = 0;

        for(; nr < n; nr++) {
            dp[k][r][c] = (dp[k][r][c] + solution(p,k-1,nr,c)) % mod;
        }

        for(; nc < m; nc++) {
            dp[k][r][c] = (dp[k][r][c] + solution(p,k-1,r,nc)) % mod;
        }

        return dp[k][r][c];
    }
public:
    int ways(vector<string>& pizza, int k) {
        memset(dp,-1,sizeof(dp));
        n = pizza.size(), m = pizza[0].size();
        return solution(pizza, k-1, 0,0);
    }
};