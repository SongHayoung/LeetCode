class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& A, vector<int>& queries) {
        int n = A.size(), m = A[0].size();
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        unordered_map<int, int> score;
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> q;
        q.push({A[0][0],0,0});
        score[A[0][0]+1] += 1;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0] = true;
        int ma = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ma = max(ma, A[i][j]);
        for(int i = A[0][0] + 1; i <= ma + 1;) {
            while(q.size() and q.top()[0] < i) {
                auto [_,y,x] = q.top(); q.pop();
                for(int j = 0; j < 4; j++) {
                    int ny = y + dy[j], nx = x + dx[j];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and !vis[ny][nx]) {
                        int num = A[ny][nx];
                        if(num < i) {
                            q.push({num,ny,nx});
                            score[i] += 1;
                            vis[ny][nx] = true;
                        } else {
                            q.push({num,ny,nx});
                            score[num + 1] += 1;
                            vis[ny][nx] = true;
                        }
                    }
                }
            }
            if(q.size()) i = q.top()[0] + 1;
            else i = ma + 2;
        }
        vector<pair<int,int>> S;
        for(auto& [k,v] : score) S.push_back({k,v});
        sort(begin(S), end(S));
        for(int i = 1; i < S.size(); i++) S[i].second += S[i-1].second;
        vector<int> res;
        for(auto& q : queries) {
            int now = min(q,ma + 1);
            auto ub = upper_bound(begin(S), end(S), make_pair(now, INT_MAX));
            if(ub == begin(S)) res.push_back(0);
            else {
                auto p = prev(ub);
                res.push_back(p->second);
            }
        }
        return res;
    }
};
