class Solution {
    int varify(int& mask, vector<vector<int>>& req, int& sz, int& n) {
        vector<int> counter(n,0);
        int bi = 0;
        for(int i = 0; i < sz; i++) {
            if(mask & (1<<i)) {
                counter[req[i][0]]--;
                counter[req[i][1]]++;
                bi++;
            }
        }
        for(auto c : counter) if(c) return 0;
        
        return bi;
    }
public:
    int maximumRequests(int n, vector<vector<int>>& req) {
        int res = 0, self = 0;
        int sz = 0;
        
        for(int i = 0; i < req.size(); i++) {
            if(req[i][0] == req[i][1]) self++;
            else {
                req[sz++] = req[i];
            }
        }
        
        res = self;
        for(int mask = 0; mask < 1<<sz; mask++) {
            res = max(res, varify(mask, req, sz, n) + self);
        }
        return res;
    }
};