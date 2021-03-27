class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> mark((limit + 1)<<1, 0);
        int sz = nums.size(), half = sz>>1;
        mark[0] = sz;
        for(int i = 0; i < half; i++) {
            int sum = nums[i] + nums[sz - i - 1];
            mark[min(nums[i], nums[sz - i - 1]) + 1] -= 1;
            mark[sum] -= 1;
            mark[sum + 1] += 1;
            mark[max(nums[i], nums[sz - i - 1]) + limit + 1] += 1;
        }
        int res = mark[0];
        for(int i = 1; i < mark.size(); i++) {
            res = min(res, mark[i] += mark[i - 1]);
        }

        return res;
    }
};
