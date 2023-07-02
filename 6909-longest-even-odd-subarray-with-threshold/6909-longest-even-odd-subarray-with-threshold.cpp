class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 1 or nums[i] > threshold) continue;
            int j = i + 1;
            res = max(res, 1);
            for(; j < nums.size(); j++) {
                if(nums[j] > threshold) break;
                if(nums[j] % 2 == nums[j-1] % 2) break;
                res = max(res, j - i + 1);
            }
            i = j - 1;
        }
        return res;
    }
};