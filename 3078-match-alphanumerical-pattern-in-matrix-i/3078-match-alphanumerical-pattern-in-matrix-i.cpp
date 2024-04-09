class Solution {
    bool match(vector<vector<int>>& A, vector<string>& P, int y, int x) {
        unordered_map<char, int> vis;
        unordered_map<int, char> rvis;
        for(int i = 0; i < P.size(); i++) {
            for(int j = 0; j < P[0].size(); j++) {
                if(isdigit(P[i][j])) {
                    if(A[i+y][j+x] != P[i][j] - '0') return false;
                } else {
                    char ch = P[i][j];
                    int val = A[i+y][j+x];
                    if(vis.count(ch) and rvis.count(val)) {
                        if(vis[ch] != val or rvis[val] != ch) return false;
                    } else if(vis.count(ch) or rvis.count(val)) return false;
                    else {
                        vis[ch] = val;
                        rvis[val] = ch;
                    }
                }
            }
        }
        return true;
    }
public:
    vector<int> findPattern(vector<vector<int>>& board, vector<string>& pattern) {
        for(int i = 0; i < board.size() - pattern.size() + 1; i++) for(int j = 0; j < board[0].size() - pattern[0].size() + 1; j++) {
            if(match(board, pattern, i, j)) return {i,j};
        }
        return {-1,-1};
    }
};