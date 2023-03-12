class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long bit = 0, res = 0;
        unordered_map<long long, long long> freq{{0,1}};
        for(auto n : nums) {
            bit ^= n;
            if(freq.count(bit)) res += freq[bit];
            freq[bit] += 1;
        }
        return res;
    }
};