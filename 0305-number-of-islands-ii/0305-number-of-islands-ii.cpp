class Solution {
    unordered_map<int, int> uf;
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    bool uni(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        uf[pu] = uf[pv] = min(pu, pv);
        return true;
    }
public:
    vector<int> numIslands2(int n, int m, vector<vector<int>>& positions) {
        auto id = [&](int y, int x) {
            return y * m + x;
        };
        uf.clear();
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        vector<int> res;
        int count = 0;
        for(auto& p : positions) {
            int y = p[0], x = p[1];
            if(!uf.count(id(y,x))) {
                count++;
                uf[id(y,x)] = id(y,x);
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and uf.count(id(ny,nx))) {
                    count -= uni(id(y,x), id(ny,nx));
                }
            }
            }
            res.push_back(count);
        }
        return res;
    }
};