class Solution {
    string bit(string ori, int y, int x, int m) {
        ori[y*m+x] = '1';
        return ori;
    }
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
public:
    bool exist(vector<vector<char>>& b, string s) {
        int n = b.size(), m = b[0].size();
        unordered_map<string,unordered_set<int>> dp;
        unordered_map<char,int> mp;
        for(auto& ch : s) mp[ch] += 1;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(mp.count(b[i][j])) {
                if(--mp[b[i][j]] == 0) mp.erase(b[i][j]);
            }
            if(b[i][j] != s[0]) continue;
            dp[bit(string(36,'0'),i,j,m)].insert(i * m + j);
        }
        if(mp.size()) return 0;
        for(int i = 1; i < s.length(); i++) {
            unordered_map<string,unordered_set<int>> dpp;
            char ch = s[i];
            for(auto& [bt, st] : dp) {
                for(auto& at : st) {
                    int y = at / m, x = at % m;
                    for(int j = 0; j < 4 ; j++) {
                        int ny = y + dy[j], nx = x + dx[j];
                        if(0 <= ny and ny < n and 0 <= nx and nx < m and b[ny][nx] == ch and bt[ny * m + nx] == '0' ) {
                            dpp[bit(bt,ny,nx,m)].insert(ny * m + nx);
                        }
                    }
                }
            }
            swap(dp,dpp);
        }

        return dp.size();
    }
};
