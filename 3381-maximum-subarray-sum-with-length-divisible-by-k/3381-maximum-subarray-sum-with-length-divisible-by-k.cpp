class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long res = LLONG_MIN;
        unordered_map<long long, long long> mi;
        for(long long i = 0, sum = 0; i <= nums.size(); i++) {
            if(!mi.count(i%k)) mi[i] = sum;
            else {
                res = max(res, sum - mi[i%k]);
                mi[i%k] = min(mi[i%k], sum);
            }
            if(i != nums.size()) sum += nums[i];
        }
        return res;
    }
};