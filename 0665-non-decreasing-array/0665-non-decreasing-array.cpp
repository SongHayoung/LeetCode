class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        vector<bool> suf(nums.size() + 1);
        suf[n] = suf[n-1] = true;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] > nums[i+1]) break;
            suf[i] = true;
        }
        bool ok = true;
        for(int i = 0; i < n and ok; i++) {
            if(ok and suf[i+1]) {
                if(i == 0) return true;
                if(i + 1 == n) return true;
                if(nums[i-1] <= nums[i+1]) return true;
            }
            if(i and nums[i] < nums[i-1]) ok = false;
        }
        return false;
    }
};