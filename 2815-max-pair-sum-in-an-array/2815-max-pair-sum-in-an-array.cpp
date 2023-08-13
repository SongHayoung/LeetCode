class Solution {
    int digit(int x) {
        int res = 0;
        while(x) {
            res = max(res, x % 10);
            x /= 10;
        }
        return res;
    }
public:
    int maxSum(vector<int>& nums) {
        int res = -1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(digit(nums[i]) == digit(nums[j])) res = max(res, nums[i] + nums[j]);
            }
        }
        return res;
    }
};
