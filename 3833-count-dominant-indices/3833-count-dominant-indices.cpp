class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int res = 0;
        for(int i = nums.size() - 1, cnt = 1, sum = 0; i >= 0; i--, cnt++) {
            sum += nums[i];
            if(nums[i] * cnt > sum) res++;
        }
        return res;
    }
};