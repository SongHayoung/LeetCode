class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++) res = max(res, abs(nums[i] - nums[(i+1)%n]));
        return res;
    }
};