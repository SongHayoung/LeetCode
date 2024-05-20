class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size(), res = 1;
        vector<int> r(n), c(m);
        priority_queue<array<int,3>> q;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            q.push({A[i][j],i,j});
        }
        while(q.size()) {
            auto x = q.top()[0];
            unordered_map<int,int> rr,cc;
            while(q.size() and q.top()[0] == x) {
                auto [_,y,x] = q.top(); q.pop();
                int best = max(r[y], c[x]) + 1;
                res = max(res, best);
                rr[y] = max(rr[y], best);
                cc[x] = max(cc[x], best);
            }
            for(auto& [k,v] : rr) r[k] = v;
            for(auto& [k,v] : cc) c[k] = v;
        }
        return res;
    }
};