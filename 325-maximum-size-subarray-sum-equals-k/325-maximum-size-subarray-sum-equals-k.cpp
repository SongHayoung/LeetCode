class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        //value, index;
        unordered_map<int, int> lookup{{0,-1}};
        int sum = 0, res = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(lookup.find(sum - k) != lookup.end()) {
                res = max(res, i - lookup[sum - k]);
            }
            if(lookup.find(sum) == lookup.end())
                lookup[sum] = i;
        }
        return res;
    }
};