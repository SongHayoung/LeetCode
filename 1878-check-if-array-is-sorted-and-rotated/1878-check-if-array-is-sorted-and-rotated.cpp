class Solution {
public:
    bool check(vector<int>& nums) {
        int ok = 0;
        for(int i = 0, n = nums.size(); i < n and ok <= 1; i++) {
            ok += nums[(i - 1 + n) % n] > nums[i];
        }
        return ok <= 1;
    }
};