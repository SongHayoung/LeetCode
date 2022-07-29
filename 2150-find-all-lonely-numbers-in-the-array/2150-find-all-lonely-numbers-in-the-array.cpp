class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto& n : nums) freq[n]++;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(freq[nums[i]] > 1) continue;
            if(freq.count(nums[i] - 1)) continue;
            if(freq.count(nums[i] + 1)) continue;
            res.push_back(nums[i]);
        }
        return res;
    }
};