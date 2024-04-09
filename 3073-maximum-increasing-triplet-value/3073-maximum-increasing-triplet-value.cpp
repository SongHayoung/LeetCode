class Solution {
public:
    int maximumTripletValue(vector<int>& nums) {
        set<int> st;
        vector<int> dp(nums.size(),1e9);
        for(int i = 0; i < dp.size(); i++) {
            auto it = st.lower_bound(nums[i]);
            if(it != begin(st)) {
                dp[i] = *prev(it) - nums[i];
            }
            st.insert(nums[i]);
        }
        int res = -1e9, best = -1e9;
        for(int i = dp.size() - 1; i >= 0; i--) {
            if(dp[i] != 1e9 and best > nums[i]) {
                res = max(res, best + dp[i]);
            }
            best = max(best, nums[i]);
        }
        return res;
    }
};