class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp{{0,1}};
        int res = 0;
        for(int i = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            res += mp[sum-goal];
            mp[sum]++;
        }
        return res;
    }
};