
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<int> cnt;
        for(int i = 0, now = 0, ok = false; i < nums.size(); i++) {
            if(nums[i] == 0) now += 1;
            if(nums[i] == 1) {
                if(ok) cnt.push_back(now);
                now = 0;
            }
            if(nums[i] == 1) ok = true;
            if(i == nums.size() - 1 and !ok) return 0;
        }
        long long res = 1, mod = 1e9 + 7;
        for(int i = 0; i < cnt.size(); i++) {
            res = res * (cnt[i] + 1) % mod;
        }
        return res;
    }
};
