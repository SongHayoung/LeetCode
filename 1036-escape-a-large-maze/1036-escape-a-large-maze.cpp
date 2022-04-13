class Solution {
    unordered_set<long> b;
    void bfs(queue<pair<int,int>>& q) {
        int sz = q.size();
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        while(sz--) {
            auto [y, x] = q.front(); q.pop();
            
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= nx and nx < 1000000 and 0 <= ny and ny < 1000000 and !b.count(ny * 1l * 1e6 + nx)) {
                    q.push({ny, nx});
                    b.insert(ny * 1l * 1e6 + nx);
                }
            }
        }
    }
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int maxMove = blocked.size();
        
        for(auto block : blocked) {
            b.insert(1l * block[0] * 1e6 + block[1]);
        }
        
        queue<pair<int, int>> sourceQ, targetQ;
        sourceQ.push({source[0],source[1]});
        targetQ.push({target[0],target[1]});
        b.insert(source[0] * 1l * 1e6 + source[1]);
        long targetKey = target[0] * 1l * 1e6 + target[1];
        while(maxMove--) {
            if(b.count(targetKey)) return true;
            if(sourceQ.empty()) return false;
            bfs(sourceQ);
        }
        if(b.count(targetKey)) return true;
        b.insert(targetKey);
        
        maxMove = blocked.size();
        
        while(maxMove--) {
            if(targetQ.empty()) return false;
            bfs(targetQ);
        }
        return !sourceQ.empty() and !targetQ.empty();
    }
};