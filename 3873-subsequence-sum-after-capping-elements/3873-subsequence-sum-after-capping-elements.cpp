class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, until = min(k,n);
        vector<int> freq(4040);
        for(auto& n : nums) freq[n]++, sum += n;
        if(sum < k) return vector<bool>(n,false);
        while(freq.size() and freq.back() == 0) freq.pop_back();
        until = min(until, (int) freq.size() - 1);
        vector<bool> res(n,true);
        bitset<4040> dp;
        dp[0] = 1;
        for(int i = 1, cnt = n; i <= until; i++) {
            cnt -= freq[i];
            while(freq[i]--) dp |= (dp<<i);
            if(dp[k]) return res;
            res[i-1] = false;
            for(int j = k - i, ccnt = cnt; ccnt > 0 and j >= 0; j -= i, ccnt--) {
                if(dp[j]) {
                    res[i-1] = true;
                    break;
                }
            }
        }
        for(int i = until + 1; i <= n; i++) res[i-1] = false;
        return res;
    }
};
