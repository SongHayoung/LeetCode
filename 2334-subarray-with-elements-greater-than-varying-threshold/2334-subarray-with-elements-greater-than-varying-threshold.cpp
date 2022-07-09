class Solution {
public:
    int validSubarraySize(vector<int>& A, int k) {
        int n = A.size();
        vector<int> dp(n);
        priority_queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) q.push({A[i],i});
        int ma = 0;
        for(int res = 1; res <= n; res++) {
            double target = 1.0 * k / res;
            while(!q.empty() and q.top().first > target) {
                auto [_, idx] = q.top(); q.pop();
                dp[idx] += 1;
                if(idx and dp[idx-1] and idx + 1 < n and dp[idx+1]) {
                    int left = dp[idx-1];
                    int right = dp[idx+1];
                    int sum = left + right + 1;
                    dp[idx-left] = sum;
                    dp[idx + right] = sum;
                    dp[idx] = sum;
                } else if(idx and dp[idx-1]) {
                    int left = dp[idx-1];
                    dp[idx] = dp[idx-left] = left + 1;
                } else if(idx + 1 < n and dp[idx+1]) {
                    int right = dp[idx+1];
                    dp[idx] = dp[idx + right] = right + 1;
                }
                
                ma = max(ma, dp[idx]);
                if(ma >= res) return res;
            }
            if(ma >= res) return res;
        }
        return -1;
    }
};
