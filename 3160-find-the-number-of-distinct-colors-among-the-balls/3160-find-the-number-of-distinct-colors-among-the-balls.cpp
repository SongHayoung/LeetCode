class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& Q) {
        unordered_map<int,int> c,rc;
        vector<int> res;
        for(auto& q : Q) {
            int b = q[0], col = q[1];
            if(c.count(b)) {
                if(--rc[c[b]] == 0) rc.erase(c[b]);
            }
            c[b] = col;
            rc[col]++;
            res.push_back(rc.size());
        }
        return res;
    }
};
