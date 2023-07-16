class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        vector<int> le(nums.size(), -1), ri(nums.size(), -1);
        unordered_map<int, int> fle, fri;
        for(int i = 0, best = 0; i < nums.size(); i++) {
            fle[nums[i]] += 1;
            if(fle[nums[i]] > fle[best]) best = nums[i];
            if(fle[best] * 2 > (i + 1)) le[i] = best;
        }
        for(int i = nums.size() - 1, best = 0; i >= 0; i--) {
            fri[nums[i]] += 1;
            if(fri[nums[i]] > fri[best]) best = nums[i];
            if(fri[best] * 2 > (nums.size() - i)) ri[i] = best;
        }
        for(int i = 0; i < nums.size() - 1; i++) {
            if(le[i] == -1) continue;
            if(le[i] == ri[i+1]) return i;
        }
        return -1;
    }
};
