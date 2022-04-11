class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, st = INT_MAX;
        for(auto& n : prices) {
            st = min(st, n);
            res = max(res , n - st);
        }
        return res;
    }
};
