class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> s, dup;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(s.count(nums[i])) {
                if(!k and !dup.count(nums[i])) {
                    res++;
                    dup.insert(nums[i]);
                }
            } else {
                res += s.count(nums[i] - k);
                res += s.count(nums[i] + k);
                s.insert(nums[i]);
            }
        }
        return res;
    }
};