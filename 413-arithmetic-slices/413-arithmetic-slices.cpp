 class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() <= 2) return 0;
        int res = 0, cnt = 0;
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] + nums[i-2] == 2 * nums[i-1]) cnt++;
            else {
                res += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
        }
        return res + cnt * (cnt + 1) / 2;
    }
};