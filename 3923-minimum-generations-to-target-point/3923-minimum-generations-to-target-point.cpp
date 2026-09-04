

int vis[11][11][11];
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        vector<vector<int>> p;
        deque<vector<int>> q(begin(points), end(points));
        memset(vis,-1,sizeof vis);
        for(auto& p : points) vis[p[0]][p[1]][p[2]] = 0;
        auto merge = [&](vector<int>& A, vector<int>& B) {
            vector<int> res;
            for(int i = 0; i < 3; i++) res.push_back((A[i] + B[i]) / 2);
            return res;
        };
        while(q.size() and vis[target[0]][target[1]][target[2]] == -1) {
            auto now = q.front(); q.pop_front();
            for(auto& ps : p) {
                auto nxt = merge(now,ps);
                if(vis[nxt[0]][nxt[1]][nxt[2]] == -1) {
                    vis[nxt[0]][nxt[1]][nxt[2]] = vis[now[0]][now[1]][now[2]] + 1;
                    q.push_back(nxt);
                }
            }
            p.push_back(now);
        }
        return vis[target[0]][target[1]][target[2]];
    }
};
