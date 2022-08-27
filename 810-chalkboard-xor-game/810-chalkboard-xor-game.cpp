class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int res = 0;
        for(auto& n : nums) res ^= n;
        return !res or nums.size() % 2 == 0;
    }
};