class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<int> freq(1e5+1);
        for(auto& n : nums) freq[n]++;
        int res = 0;
        for(int i = 0, l = 0, r = 0, cnt = 0; i <= 1e5; i++) {
            while(r <= 1e5 and r <= i + k) cnt += freq[r++];
            while(l < i - k) cnt -= freq[l++];
            res = max(res, freq[i] + min(cnt - freq[i], numOperations));
        }
        return res;
    }
};