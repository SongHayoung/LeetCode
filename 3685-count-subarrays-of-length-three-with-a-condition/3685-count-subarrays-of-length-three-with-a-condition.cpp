class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 0; i < n - 3; i++) {
            if(2 * nums[i] + 2 * nums[i+2] == nums[i+1]) res++;
        }
        return res;
    }
};