class Solution {
    int helper(int x) {
        for(int i = 1; i <= x; i++) {
            if((i | (i + 1)) == x) return i;
        }
        return -1;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(auto& n : nums) res.push_back(helper(n));
        return res;
    }
};