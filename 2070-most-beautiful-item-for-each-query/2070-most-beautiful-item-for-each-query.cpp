class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& A, vector<int>& B) {
        vector<pair<int,int>> Q;
        int n = A.size(), m = B.size();
        vector<int> res(m);
        for(int i = 0; i < m; i++) {
            Q.push_back({B[i], i});
        }
        sort(begin(Q), end(Q));
        sort(begin(A), end(A));
        vector<pair<int, int>> pmax {{0,0}};
        int ma = 0, p = 0;
        while(p < n) {
            int price = A[p][0];
            while(p < n and A[p][0] == price) {
                ma = max(ma, A[p++][1]);
            }
            pmax.push_back({price, ma});
        }
        p = 0;
        for(int i = 0; i < m; i++) {
            auto [req, idx] = Q[i];
            while(p + 1 < pmax.size() and pmax[p + 1].first <= req) p++;
            if(pmax[p].first <= req) res[idx] = pmax[p].second;
        }
        return res;
    }
};