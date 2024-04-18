class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& A, vector<int>& P, vector<int>& S, int k) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> res, vis(n, vector<int>(m));
        queue<pair<int, int>> q;
        auto push = [&](int y, int x) {
            if(!vis[y][x] and A[y][x]) {
                q.push({y,x});
                vis[y][x] = true;
            }
        };
        push(S[0],S[1]);
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        while(res.size() < k and q.size()) {
            vector<pair<int,int>> now;
            int qsz = q.size();
            while(qsz--) {
                auto [y,x] = q.front(); q.pop();
                if(P[0] <= A[y][x] and A[y][x] <= P[1]) now.push_back({y,x});
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and A[ny][nx]) {
                        push(ny,nx);
                    }
                }
            }
            sort(begin(now), end(now), [&](auto a, auto b){
                auto [ya,xa] = a;
                auto [yb,xb] = b;
                if(A[ya][xa] != A[yb][xb]) return A[ya][xa] > A[yb][xb];
                if(ya != yb) return ya > yb;
                return xa > xb;
            });
            while(now.size() and res.size() < k) {
                res.push_back({now.back().first, now.back().second});
                now.pop_back();
            }
        }
        return res;
    }
};