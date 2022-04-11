class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        long long res = 0;
        int mod = 1e9 + 7;
        int sz = nums.size();
        vector<int> freq(sz, 0);
        for(auto request : requests) {
            freq[request[0]]++;
            if(request[1] + 1 < sz)
                freq[request[1] + 1]--;
        }
        for(int i = 1; i < sz; i++) {
            freq[i] += freq[i - 1];
        }
        
        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());
    
        for(int i = sz - 1; i >= 0 && freq[i]; i--) {
            res = (res + 1L * freq[i] * nums[i]) % mod;
        }
        
        return res;

    }
};
