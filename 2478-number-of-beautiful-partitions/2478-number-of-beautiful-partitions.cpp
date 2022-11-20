#include <bits/stdc++.h>

long long dp[1010][1010];
class Solution {
    bool prime(char ch) {
        return ch == '2' or ch == '3' or ch == '5' or ch == '7';
    }
    long long mod = 1e9 + 7;
    vector<int> np;
    long long helper(string& s, int p, int k, int& len) {
        if(p >= s.length() or k < 0) return 0;
        if(k == 0) return prime(s.front()) and s.size() - p >= len;
        long long& res = dp[p][k];
        if(res != -1) return res;
        dp[p][k] = 0;
        if(!prime(s.front())) return 0;
        auto lb = lower_bound(begin(np), end(np), p + len - 1) - begin(np);
        for(int i = np.size() - 1; i >= 0 and np[i] >= p + len - 1; i--) {
            res = (res + helper(s, np[i] + 1, k - 1, len)) % mod;
        }
        return res;
    }
public:
    int beautifulPartitions(string s, int k, int minLength) {
        if(!prime(s.front()) or prime(s.back())) return 0;
        int n = s.length();
        np.clear();
        for(int i = 0; i < n - 1; i++) {
            if(!prime(s[i]) and prime(s[i + 1])) np.push_back(i);
        }
        np.push_back(n-1);
        memset(dp,-1,sizeof dp);
        return helper(s,0, k-1,minLength);
    }
};