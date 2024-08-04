class Solution {
    int cost(vector<int> freq) {
        int ma = 0, buc[2]{};
        for(auto& f : freq) ma = max(ma, ++buc[f]);
        return freq.size() - ma;
    }
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < m / 2; j++) {
                res += cost({grid[i][j], grid[i][m-j-1], grid[n-i-1][j], grid[n-i-1][m-j-1]});
            }
        }
        vector<vector<int>> cnt(2,vector<int>(2));
        if(n & 1) {
            for(int l = 0, r = m - 1; l < r; l++,r--) {
                int a = grid[n/2][l], b = grid[n/2][r];
                if(a > b) swap(a,b);
                cnt[a][b]++;
            }
        }
        if(m & 1) {
            for(int l = 0, r = n - 1; l < r; l++,r--) {
                int a = grid[l][m/2], b = grid[r][m/2];
                if(a > b) swap(a,b);
                cnt[a][b]++;
            }
        }
        if(cnt[1][1] % 2 == 0) {
            res += cnt[0][1];
        } else {
            res += cnt[0][1];
            if(cnt[0][1] == 0) res += 2;
        }
        if(n & 1 and m & 1 and grid[n/2][m/2]) res++;
        return res;
    }
};
