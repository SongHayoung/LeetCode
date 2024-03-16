class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int diff = 0, res = 0;
        m[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            diff += (nums[i] ? 1 : -1);
            if(m.count(diff)) {
                res = max(res, i - m[diff]);
            } else m[diff] = i;
        }
        return res;
    }
};