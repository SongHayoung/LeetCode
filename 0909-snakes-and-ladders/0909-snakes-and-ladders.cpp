class Solution {
    unordered_map<int, pair<int, int>> build(int n) {
        unordered_map<int, pair<int, int>> res;
        int index = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = !((n - i + 1) % 2) ? 0 : n - 1; j != -1 && j != n; j += !((n - i + 1) % 2) ? 1 : -1) {
                res[index++] = {i, j};
            }
        }
        return res;
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int, pair<int, int>> m = build(n);
        if(board[m[n*n].first][m[n*n].second] != -1) return -1;
        queue<pair<int, int>> q;
        q.push({1, 0});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if(p.first + 6 >= n * n) return p.second + 1;
            for(int i = p.first + 1; i <= p.first + 6; i++) {
                if(m.count(i)) {
                    auto pos = m[i];
                    if(board[pos.first][pos.second] == n * n) return p.second + 1;
                    q.push({board[pos.first][pos.second] == -1 ? i : board[pos.first][pos.second], p.second + 1});
                    m.erase(i);
                }
            }
        }

        return -1;
    }
};