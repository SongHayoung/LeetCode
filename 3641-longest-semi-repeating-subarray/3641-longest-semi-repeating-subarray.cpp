class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), res = 0, rep = 0;
        unordered_map<int,int> freq;
        auto add = [&](int x) {
            freq[x]++;
            if(freq[x] == 2) rep++;
        };
        auto del = [&](int x) {
            --freq[x];
            if(freq[x] == 1) rep--;
            if(freq[x] == 0) freq.erase(x);
        };
        while(r < n) {
            if(rep <= k) {
                add(nums[r]);
                r++;
            } else {
                del(nums[l]);
                l++;
            }
            if(rep <= k) res = max(res, r - l);
        }
        return res;
    }
};