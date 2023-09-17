class Solution {
public:
    int countWays(vector<int>& nums) {
        int res = 0;
        sort(begin(nums), end(nums));
        for(int i = 0; i < nums.size(); i++) {
            int now = nums[i], nxt = i + 1 == nums.size() ? INT_MAX : nums[i+1];
            if((i + 1) > now and (i + 1) < nxt) res += 1;
        }
        if(nums[0] != 0) res += 1;
        return res;
    }
};
