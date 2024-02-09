class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& A) {
        int n = A.size(), ma = 0, st = 0;
        sort(begin(A), end(A));
        vector<int> dp(n, 0), path(n, -1);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < i; j++) {
                if(A[i] % A[j] == 0) {
                    if(dp[j] < dp[i] + 1) {
                        dp[j] = dp[i] + 1;
                        path[j] = i;
                        if(dp[j] > ma) {
                            ma = dp[j];
                            st = j;
                        }
                    }
                }
            }
        }
        vector<int> res;
        while(st != -1) {
            res.push_back(A[st]);
            st = path[st];
        }
        return res;
    }
};
