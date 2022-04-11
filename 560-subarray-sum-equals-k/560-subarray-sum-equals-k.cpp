class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cache{{0,1}};
        int sum = 0, res = 0;
        for(auto& n : nums) {
            sum += n;
            res += cache[sum-k];
            cache[sum]++;
        }
        return res;
    }
};