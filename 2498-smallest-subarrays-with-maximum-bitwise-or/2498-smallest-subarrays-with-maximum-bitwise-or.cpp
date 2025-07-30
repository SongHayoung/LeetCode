class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<deque<long long>> dq(32);
        vector<long long> freq(32);
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            for(long long bit = 0; bit < 32; bit++) {
                if(nums[i] & (1ll<<bit)) {
                    freq[bit]++;
                    dq[bit].push_back(i);
                }
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            long long ma = i;
            for(int j = 0; j < 32; j++) {
                if(freq[j]) ma = max(ma,dq[j].front());
            }
            res.push_back(ma-i+1);
            for(long long bit = 0; bit < 32; bit++) {
                if(nums[i] & (1ll<<bit)) {
                    freq[bit]--;
                    dq[bit].pop_front();
                }
            }
        }
        return res;
    }
};