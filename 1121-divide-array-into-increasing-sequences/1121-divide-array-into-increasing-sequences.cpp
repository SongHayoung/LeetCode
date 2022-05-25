class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        int mafreq = 0, l = 0, r = 0, n = nums.size();
        while(r < n) {
            while(r < n and nums[r] == nums[l]) r++;
            mafreq = max(mafreq, r - l);
            l = r;
        }
        return mafreq * k <= n;
    }
};