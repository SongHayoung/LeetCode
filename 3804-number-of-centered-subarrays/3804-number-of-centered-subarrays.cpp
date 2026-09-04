class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            unordered_set<int> us;
            for(int j = i, sum = 0; j < n; j++) {
                us.insert(nums[j]);
                sum += nums[j];
                if(us.count(sum)) res++;
            }
        }
        return res;
    }
};