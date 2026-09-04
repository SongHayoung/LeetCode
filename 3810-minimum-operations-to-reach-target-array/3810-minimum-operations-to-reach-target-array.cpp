class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> us;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != target[i]) us.insert(nums[i]);
        }
        return us.size();
    }
};