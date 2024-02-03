class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, now = 0;
        for(auto& x : nums) {
            now = x ? now + 1 : 0;
            res = max(res, now);
        }
        return res;
    }
};