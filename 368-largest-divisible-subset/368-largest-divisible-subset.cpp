class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& A) {
        int n = A.size(), ma = 0;
        sort(begin(A), end(A));
        vector<int> dp(n, 1), pos(n, -1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(A[i] % A[j] == 0 and dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pos[i] = j;
                    if(dp[i] > dp[ma])
                        ma = i;
                }
            }
        }
        
        vector<int> res;
        while(ma != -1) {
            res.push_back(A[ma]);
            ma = pos[ma];
        }
        return res;
    }
};