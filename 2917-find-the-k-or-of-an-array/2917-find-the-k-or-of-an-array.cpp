class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> freq(32);
        for(auto n : nums) {
            for(int i = 0; i < 32; i++) {
                if(n & (1ll<<i)) freq[i] += 1;
            }
        }
        int res = 0;
        for(int i = 0; i < 32; i++) {
            if(freq[i] < k) continue;
            res |= 1ll<<i;
        }
        return res;
    }
};
