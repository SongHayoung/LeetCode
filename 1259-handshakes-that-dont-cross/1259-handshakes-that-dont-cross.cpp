class Solution {
    vector<long> dp;
    int mod = 1e9 + 7;
    long solution(int n) {
        if(n == 0) return 1;      
        if(dp[n/2] != 0) return dp[n/2];
        long& res = dp[n/2];
        for(int i = 0; i < n; i += 2) {
            res = (solution(i) * solution(n - i - 2) % mod + res) % mod;
        }
        
        return res;
    }
public:
    int numberOfWays(int numPeople) {
        dp = vector<long>(numPeople / 2 + 1, 0);
        return solution(numPeople);
    }
};