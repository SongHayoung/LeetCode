class Solution {
    unordered_map<string,vector<string>> mp[3][5];
    vector<vector<string>> res;
    void helper(vector<string>& A, int x, int p) {
        if(p == x) res.push_back(A);
        else {
            string base = "";
            for(int i = 0; i < p; i++) base.push_back(A[i][p]);
            if(!mp[base.length() - 1][x].count(base)) return;
            for(auto& w : mp[base.length() - 1][x][base]) {
                A[p] = w;
                helper(A,x,p+1);
            }
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        for(int i = 0; i < 3; i++) for(int j = 0; j < 5; j++) mp[i][j] = {};
        for(auto& w : words) {
            string now = "";
            for(int i = 0; i < w.length() - 1; i++) {
                now.push_back(w[i]);
                mp[i][w.length()][now].push_back(w);
            }
        }
        res = {};
        for(auto& w : words) {
            vector<string> A(w.length());
            A[0] = w;
            helper(A,w.length(),1);
        }
        return res;
    }
};