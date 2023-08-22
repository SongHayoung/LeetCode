struct pair_hash{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const{
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};
class Solution {
    bool equal(int x, int y, int z) {
        return x == y && y == z;
    }
    bool crush(vector<vector<int>>& b) {
        int n = b.size(), m = b[0].size();
        bool res = true;
        set<pair<int,int>> s;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!b[i][j]) continue;
                if(i <= n - 3 && equal(b[i][j], b[i + 1][j], b[i + 2][j])) {
                    res = false;
                    s.insert({i,j});
                    s.insert({i + 1,j});
                    s.insert({i + 2,j});
                }
                if(j <= m - 3 && equal(b[i][j], b[i][j + 1], b[i][j + 2])) {
                    res = false;
                    s.insert({i,j});
                    s.insert({i,j + 1});
                    s.insert({i,j + 2});
                }
            }
        }
        for(auto& p : s) {
            b[p.first][p.second] = 0;
        }
        return res;
    }
    void fillEmptySpace(vector<vector<int>>& b) {
        int n = b.size(), m = b[0].size();
        for(int j = 0; j < m; j++) {
            for(int i = n - 2; i >= 0; i--) {
                if(!b[i][j]) continue;
                int k = i + 1;
                for(; k < n && !b[k][j]; k++){}
                swap(b[i][j], b[k - 1][j]);
            }
        }
    }
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while(!crush(board)) {
            fillEmptySpace(board);
        }
        return board;
    }
};