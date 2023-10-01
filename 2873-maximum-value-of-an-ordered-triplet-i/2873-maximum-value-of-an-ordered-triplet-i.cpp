class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ma = -1e9, best = 0, res = 0;
        for(auto n : nums) {
            res = max(res, best * n);
            best = max(best, ma - n);
            ma = max(ma, 1ll * n);
        }
        return res;
    }
};