class Solution {
public:
    vector<int> elementInNums(vector<int>& A, vector<vector<int>>& queries) {
        vector<array<int,3>> Q;
        for(int i = 0; i < queries.size(); i++) {
            int t = queries[i][0], idx = queries[i][1];
            Q.push_back({t,idx,i});
        }
        vector<int> res(queries.size());
        sort(rbegin(Q), rend(Q));
        int l = 0, r = A.size(), n = A.size(), now = 0;
        bool pop = true;
        while(!Q.empty()) {
            auto [t, p, idx] = Q.back();
            if(now != t) {
                if(pop) {
                    if(++l == n) {
                        pop = !pop;
                        l = r = 0;
                    }
                } else {
                    if(++r == n) {
                        pop = !pop;
                    }
                }
                now++;
            } else {
                Q.pop_back();
                int window = r - l - 1;
                if(p > window) res[idx] = -1;
                else {
                    res[idx] = A[p + l];
                }
            }
        }
        return res;
    }
};