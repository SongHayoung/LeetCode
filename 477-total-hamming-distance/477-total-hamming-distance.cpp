class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, freq[32] = {}, count = 0;
        for(auto& n : nums) {
            for(int i = 0; i < 32; i++) {
                int mask = n & (1<<i);
                if(mask) {
                    res += count - freq[i];
                    freq[i]++;
                } else {
                    res += freq[i];
                }
            }
            count++;
        }
        return res;
    }
};