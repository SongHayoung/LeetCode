class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long tot = 0, res = 0;
        for(int i = 0; i < nums.size() && tot < n && nums[i] <= n; i++) {
            while(tot + 1 < nums[i]) {
                tot = tot + tot + 1;
                res++;
            }
            tot += nums[i];
        }
        while(tot < n) {
            tot = tot + tot + 1;
            res++;
        }
        return res;
    }
};