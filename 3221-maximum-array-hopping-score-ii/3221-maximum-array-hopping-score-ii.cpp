class Solution {
public:
    long long maxScore(vector<int>& nums) {
        long long res = 0;
        int best = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            best = max(best, nums[i]);
            res += best;
        }
        return res - best;
    }
};