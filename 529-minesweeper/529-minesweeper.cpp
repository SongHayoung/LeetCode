class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& b, vector<int>& c) {
        char& t = b[c.front()][c.back()];
        if(isdigit(t) || t == 'B' || t == 'X') return b;
        if(t == 'M') {t = 'X'; return b;}
        queue<pair<int, int>> q;
        int dx[8]{-1,0,1,1,1,0,-1,-1}, dy[8]{-1,-1,-1,0,1,1,1,0}, m = b[0].size(), n = b.size();
        q.push({c.front(), c.back()});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            if(b[p.first][p.second] != 'E') continue;
            char open = '0';
            for(int i = 0; i < 8; i++) {
                int ny = p.first + dy[i], nx = p.second + dx[i];
                if(0 <= ny && ny < n && 0 <= nx && nx < m && (b[ny][nx] == 'M' || b[ny][nx] == 'X')) open++;
            }
            if(open != '0') b[p.first][p.second] = open;
            else {
                b[p.first][p.second] = 'B';
                for(int i = 0; i < 8; i++) {
                    int ny = p.first + dy[i], nx = p.second + dx[i];
                    if(0 <= ny && ny < n && 0 <= nx && nx < m && b[ny][nx] == 'E') q.push({ny,nx});
                }
            }
        }
        return b;
    }
};