class Solution {
    vector<int> pi(string& p) {
        vector<int> PI(p.length());
        for(int i = 1, j = 0; i < p.length(); i++) {
            while(j and p[i] != p[j]) j = PI[j-1];
            if(p[i] == p[j]) PI[i] = ++j;
        }
        return PI;
    }
    vector<int> kmp(string& s, string& p) {
        vector<int> PI = pi(p);
        vector<int> at;
        for(int i = 0, j = 0; i < s.length(); i++) {
            while(j and s[i] != p[j]) j = PI[j-1];
            if(s[i] == p[j]) {
                if(++j == p.length()) {
                    at.push_back(i - p.length() + 1);
                    j = PI[j-1];
                }
            }
        }
        vector<int> res;
        for(int i = 0, pos = 0; i < at.size(); i++) {
            pos = max(pos, at[i]);
            while(pos < at[i] + p.length()) res.push_back(pos++);
        }
        return res;
    }
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        string ho = "", ve = "";
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            ho.push_back(grid[i][j]);
        }
        for(int j = 0; j < m; j++) for(int i = 0; i < n; i++) {
            ve.push_back(grid[i][j]);
        }
        vector<vector<int>> mask(n, vector<int>(m));
        
        vector<int> hoo = kmp(ho,pattern), vee = kmp(ve,pattern);
        for(auto& h : hoo) mask[h/m][h%m] |= 1;
        for(auto& v : vee) mask[v%n][v/n] |= 2;
        
        int res = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(mask[i][j] == 3) res++;
        return res;
    }
};
