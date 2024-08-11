
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        long long mod = 1e9 + 7, n = nums.size();
        vector<long long> dp(1001);
        for(int i = 0; i <= nums[0]; i++) dp[i] = 1;
        for(int i = 1; i < n; i++) {
            vector<long long> dpp(1001);
            long long pre = 0;
            queue<pair<int,int>> q;
            for(int j = 0; j <= nums[i]; j++) {
                int k = nums[i] - j, pk = nums[i-1] - j;
                q.push({pk,j});
                while(q.size() and q.front().first >= k) {
                    auto [_,pj] = q.front(); q.pop();
                    pre = (pre + dp[pj]) % mod;
                }
                dpp[j] = pre;
            }
            swap(dp,dpp);
        }
        long long res = 0;
        for(int i = 0; i <= 1000; i++) res = (res + dp[i]) % mod;
        return res;
    }
};
