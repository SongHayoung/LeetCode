class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto& n : nums) freq[n] += 1;
        int res = 0, target = freq.size();
        unordered_map<int, int> now;
        for(int l = 0, r = 0; l < nums.size() and freq.size() == target; l++) {
            while(r < nums.size() and now.size() < target) now[nums[r++]] += 1;
            res += nums.size() - r + 1;
            if(--freq[nums[l]] == 0) freq.erase(nums[l]);
            if(--now[nums[l]] == 0) now.erase(nums[l]);
        }
        return res;
    }
};
