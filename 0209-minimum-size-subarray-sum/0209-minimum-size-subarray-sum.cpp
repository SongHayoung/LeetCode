class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX, n = nums.size();
        vector<int> p{0};
        for(int l = 0, r = 0; r < n; r++) {
            p.push_back(p.back() + nums[r]);
            while(l <= r and p[r+1] - p[l] >= target) {
                res = min(res, r + 1 - l++);
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};