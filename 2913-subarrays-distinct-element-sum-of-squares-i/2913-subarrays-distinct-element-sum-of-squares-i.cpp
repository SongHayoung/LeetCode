class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            unordered_set<int> us;
            int sum = 0;
            for(int j = i; j < nums.size(); j++) {
                us.insert(nums[j]);
                res += us.size() * us.size();
            }
        }
        return res;
    }
};