class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            int l = i - 1, r = i + 1;
            if(i > 0 and nums[i] == nums[i-1]) continue;
            while(l >= 0 and nums[l] == nums[i]) l--;
            while(r < n and nums[r] == nums[i]) r++;
            if(l < 0 or r >= n) continue;
            if(nums[l] < nums[i] and nums[r] < nums[i]) res++;
            else if(nums[l] > nums[i] and nums[r] > nums[i]) res++;
        }
        return res;
    }
};