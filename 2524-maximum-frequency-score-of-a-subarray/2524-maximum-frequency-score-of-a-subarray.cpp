class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, int k) {
        unordered_map<long long, vector<long long>> mp;
        long long res = 0, now = 0, mod = 1e9 + 7;
        for(int i = 0; i < nums.size(); i++) {
            if(i >= k) {
                now = (now - mp[nums[i-k]].back() + mod) % mod;
                mp[nums[i-k]].pop_back();
                if(mp[nums[i-k]].size()) {
                    now = (now + mp[nums[i-k]].back()) % mod;
                }
            }
            if(mp[nums[i]].size() == 0) {
                mp[nums[i]].push_back(nums[i]);
                now = (now + nums[i]) % mod;
            } else {
                now = (now - mp[nums[i]].back() + mod) % mod;
                mp[nums[i]].push_back(mp[nums[i]].back() * nums[i] % mod);
                now = (now + mp[nums[i]].back()) % mod;
            }
            if(i + 1 >= k) res = max(res, now);
        }
        return res;
    }
};