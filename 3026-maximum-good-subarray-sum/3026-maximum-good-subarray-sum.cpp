class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long, long long> freq;
        long long sum = 0, res = LLONG_MIN;
        for(auto& x : nums) {
            sum += x;
            if(freq.count(x + k)) res = max(res, sum - freq[x+k] + (x + k));
            if(freq.count(x - k)) res = max(res, sum - freq[x-k] + (x - k));
            if(!freq.count(x)) freq[x] = sum;
            freq[x] = min(freq[x], sum);
        }
        if(res == LLONG_MIN) return 0;
        return res;
    }
};