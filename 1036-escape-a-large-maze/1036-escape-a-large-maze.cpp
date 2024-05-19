class Solution {
    long long makeKey(int x, int y) {return (((long long)x)<<32) + y;}
    bool bfs(unordered_set<long long>& v, vector<int>& from, vector<int>& to, int block) {
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        queue<pair<int, int>> q;
        q.push({from[0], from[1]});
        for(int step = 0; step <= 400 and !q.empty() and q.size() < block; step++) {
            int size = q.size();
            while(size--) {
                auto [x, y] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(0 <= nx && nx < 1000000 && 0 <= ny && ny < 1000000 and v.insert(makeKey(nx, ny)).second) {
                        if(nx == to[0] and ny == to[1]) return true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return !q.empty();
    }
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.empty()) return true;
        unordered_set<long long> vs, vt;
        for(auto& b : blocked) {
            vs.insert(makeKey(b[0], b[1]));
            vt.insert(makeKey(b[0], b[1]));
        }

        return bfs(vs, source, target, blocked.size()) && bfs(vt, target, source, blocked.size()) ;
    }
};
