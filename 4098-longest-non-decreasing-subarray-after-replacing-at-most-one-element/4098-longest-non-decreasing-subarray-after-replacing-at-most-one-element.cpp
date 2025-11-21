class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        vector<pair<int,int>> range{{0,0}};
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i-1]) range.push_back({i,i});
            range.back().second = i;
        }
        int res = 0;
        for(int i = 0; i < range.size(); i++) {
            res = max(res, range[i].second - range[i].first + 2);
            if(i + 1 < range.size()) {
                auto [l,r] = range[i+1];
                if(l == r) {
                    res = max(res, range[i].second - range[i].first + 2);
                    if(i + 2 < range.size()) {
                        if(nums[range[i].second] <= nums[r+1]) res = max(res, range[i+2].second - range[i].first + 1);
                    }
                } else if(nums[range[i].second] <= nums[l+1]) {
                    res = max(res, r - range[i].first + 1);
                }
            }
            if(i) {
                auto [l,r] = range[i-1];
                if(l == r) {
                    res = max(res, range[i].second - range[i].first + 2);
                    if(i >= 2) {
                        if(nums[range[i].first] >= nums[l-1]) res = max(res, range[i].second - range[i-2].first + 1);
                    }
                } else if(nums[range[i].first] >= nums[r-1]) {
                    res = max(res, range[i].second - l + 1);
                }
            }
        }
        return min(res,n);
    }
};