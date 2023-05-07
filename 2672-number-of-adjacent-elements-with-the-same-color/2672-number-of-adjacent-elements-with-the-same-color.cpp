class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> C(n+2);
        vector<int> res;
        auto good = [&](int idx) {
            int res = 0;
            if(C[idx-1] and C[idx] and C[idx-1] == C[idx]) res += 1;
            if(C[idx+1] and C[idx] and C[idx+1] == C[idx]) res += 1;
            return res;
        };
        int now = 0;
        for(auto q : queries) {
            int idx = q[0] + 1, c = q[1];
            now -= good(idx);
            C[idx] = c;
            now += good(idx);
            
            
            res.push_back(now);
        }
        return res;
    }
};