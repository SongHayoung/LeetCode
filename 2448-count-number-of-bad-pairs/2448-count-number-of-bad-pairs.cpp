class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res = 0;
        unordered_map<long long, long long> freq;
        for(long long i = 0; i < nums.size(); i++) {
            res += i - freq[i-nums[i]];
            freq[i-nums[i]]++;
        }
        return res;
    }
};