class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,long long> freq;
        long long n = nums.size(), mod = 1e9 + 7, res = 0;
        vector<long long> le(n);
        for(int i = 0; i < nums.size(); i++) {
            le[i] = freq[nums[i] * 2];
            freq[nums[i]]++;
        }
        freq = {};
        for(int i = n - 1; i >= 0; i--) {
            res = (res + freq[nums[i] * 2] * le[i] % mod) % mod;
            freq[nums[i]]++;
        }
        return res;
    }
};