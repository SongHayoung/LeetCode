class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        map<pair<int,int>,int> freq;
        auto gcdPair = [&](int i, int j) {
            int g = __gcd(nums[i], nums[j]);
            return pair<int,int>{nums[i] / g, nums[j] / g};
        };
        
        long long res = 0, n = nums.size();
        for(int r = 4; r < n; r++) {
            for(int s = r + 2; s < n; s++) {
                freq[gcdPair(s,r)]++;
            }
        }
        for(int q = 2; q < n; q++) {
            for(int p = 0; p + 1 < q; p++) {
                res += freq[gcdPair(p,q)];
            }
            for(int r = q + 2, s = r + 2; s < n; s++) {
                freq[gcdPair(s,r)]--;
            }
        }
        return res;
    }
};