class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> res(5);
        res[0] = 1ll * (m - 1) * (n - 1);
        set<pair<long long, long long>> st;
        set<pair<long long, long long>> blk;
        auto push = [&](int x, int y) {
            if(0 <= x and x < m - 1 and 0 <= y and y < n - 1) {
                st.insert({x,y});
            }
        };
        for(auto c : coordinates) {
            int x = c[0], y = c[1];
            push(x-1,y-1);
            push(x-1,y);
            push(x,y-1);
            push(x,y);
            blk.insert({x,y});
        }
        int dy[4]{0,1,0,1}, dx[4]{0,0,1,1};
        for(auto& [x,y] : st) {
            int cnt = 0;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(blk.count({nx,ny})) cnt += 1;
            }
            res[0] -= 1;
            res[cnt] += 1;
        }
        return res;
    }
};
