class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long res = 0;
        int MOD = 1e9 + 7;
        unordered_map<int, long> dp;
        sort(arr.begin(), arr.end());
        for(auto& num : arr) {
            if(!dp.count(num)) {
                long cnt = 1;
                for(int i = 2; i * i <= num; i++) {
                    if(!(num % i) && dp.count(i)) {
                        cnt += (dp[num/i] * dp[i]) * (i * i == num ? 1 : 2);
                    }
                }
                dp[num] = cnt;
            }
            res = (res + dp[num]) % MOD;
        }

        return res;
    }
};
