class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        for(int i = 0, cnt = 0; i < nums.size(); i++) {
            if(nums[i]) cnt = 0;
            else cnt += 1;
            res += cnt;
        }
        return res;
    }
};