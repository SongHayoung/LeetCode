class Solution {
    bool search(int k, vector<int>& req, vector<int>& has, vector<int>& c, long long m) {
        for(int i = 0; i < req.size(); i++) {
            long long buy = max(0ll, 1ll * req[i] * m - has[i]);
            if(buy * c[i] > k) return false;
            k -= buy * c[i];
        }
        return k >= 0;
    }
    int helper(int k, vector<int>& req, vector<int>& has, vector<int>& c) {
        long long l = 0, r = INT_MAX, res = 0;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = search(k,req,has,c,m);
            if(ok) {
                res = max(res, m);
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int res = 0;
        for(int i = 0; i < k; i++) {
            res = max(res, helper(budget, composition[i], stock, cost));
        }
        return res;
    }
};
