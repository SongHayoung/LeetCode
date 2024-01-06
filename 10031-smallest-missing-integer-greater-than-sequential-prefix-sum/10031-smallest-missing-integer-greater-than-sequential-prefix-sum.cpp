class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1] + 1) res += nums[i];
            else break;
        }
        unordered_set<int> us(begin(nums), end(nums));
        while(us.count(res)) res += 1;
        return res;
    }
};