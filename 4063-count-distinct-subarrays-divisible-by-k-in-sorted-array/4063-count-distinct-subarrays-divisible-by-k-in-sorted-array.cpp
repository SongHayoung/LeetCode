class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        map<long long, long long> freq{{0,1}};
        map<long long, long long> cnt;
        long long sum = 0, res = 0;
        for(auto& n : nums) {
            cnt[n]++;
            sum = (sum + n) % k;
            res += freq[sum];
            freq[sum]++;
        }
        for(auto& [v,c] : cnt) {
            freq = {{0,0}};
            sum = 0;
            for(int i = 0; i < c; i++) {
                sum = (sum + v) % k;
                res -= freq[sum];
                freq[sum]++;
            }
        }

        return res;
    }
};
