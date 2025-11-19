class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> us;
        for(auto& n : nums) us.insert(n);
        int res = original;
        while(us.count(res)) res<<=1;
        return res;
    }
};