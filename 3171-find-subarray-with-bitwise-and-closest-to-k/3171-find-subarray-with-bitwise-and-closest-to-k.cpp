class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        vector<int> dp;
        int res = INT_MAX;
        for(int i = nums.size() - 1; i >= 0; i--) {
            vector<int> dpp{nums[i]};
            res = min(res, abs(dpp.back() - k));
            for(auto& x : dp) {
                int now = dpp.back() & x;
                if(now == dpp.back()) continue;
                dpp.push_back(now);
                res = min(res, abs(k-now));
            }
            swap(dp,dpp);
        }
        return res;
    }
};