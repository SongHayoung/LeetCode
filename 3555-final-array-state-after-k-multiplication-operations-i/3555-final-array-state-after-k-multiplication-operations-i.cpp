class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        multiset<pair<int,int>> ms;
        for(int i = 0; i < nums.size(); i++) ms.insert({nums[i], i});
        while(k--) {
            auto [val, idx] = *begin(ms); ms.erase(begin(ms));
            ms.insert({nums[idx] = val * multiplier, idx});
        }
        return nums;
    }
};