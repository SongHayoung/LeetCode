class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        if(n == 3) return 0;
        int res = INT_MAX;
        for(int i = 0, j = n - 3; i < 3; i++,j++) {
            res = min(res, nums[j] - nums[i]);
        }
        return res;
    }
};
