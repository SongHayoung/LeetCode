struct RollingHash {
    vector<long long> hash, po;
    long long base, mod;
    RollingHash(string& s) : base(131), mod(1e9 + 7) {
        hash = vector<long long>(s.length() + 1), po = vector<long long>(s.length() + 1);
        po[0] = 1;
        for(int i = 0; i < s.length(); i++) {
            po[i+1] = po[i] * base % mod;
            hash[i+1] = (hash[i] * base + s[i] - 'a') % mod;
        }
    }
    long long get(int pos, int len) {
        return (hash[pos + len] - hash[pos] * po[len] % mod + mod) % mod;
    }
};

class Solution {
    vector<int> rh(string& s, string& p) {
        RollingHash srh(s), prh(p);
        vector<int> at;
        long long hash = prh.get(0,p.length());
        for(int i = 0; i <= s.length() - p.length(); i++) {
            if(hash == srh.get(i,p.length())) at.push_back(i);
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

        vector<int> hoo = rh(ho,pattern), vee = rh(ve,pattern);
        for(auto& h : hoo) mask[h/m][h%m] |= 1;
        for(auto& v : vee) mask[v%n][v/n] |= 2;

        int res = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(mask[i][j] == 3) res++;
        return res;
    }
};