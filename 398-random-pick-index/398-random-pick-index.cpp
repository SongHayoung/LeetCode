class Solution {
    unordered_map<int, vector<int>> m;
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        auto& v = m[target];
        auto idx = rand()%v.size();
        
        return v[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
