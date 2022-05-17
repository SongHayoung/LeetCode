class Solution {
    int n;
    vector<int> oddTable;
    vector<int> evenTable;
    vector<vector<int>> dp;
    int helper(int pos, bool odd) {
        if(dp[pos][odd] != -1) return dp[pos][odd];
        if(odd) {
            if(oddTable[pos] == -1) return dp[pos][odd] = 0;
            return dp[pos][odd] = helper(oddTable[pos], !odd);
        } else {
            if(evenTable[pos] == -1) return dp[pos][odd] = 0;
            return dp[pos][odd] = helper(evenTable[pos], !odd);
        }
    }
public:
    int oddEvenJumps(vector<int>& arr) {
        n = arr.size();
        oddTable = vector<int>(n, -1);
        evenTable = vector<int>(n, -1);
        dp = vector<vector<int>>(n, vector<int>(2,-1));
        dp[n - 1][0] = dp[n - 1][1] = 1;
        
        map<int, int> mp;
        for(int i = n - 1; i >= 0; i--) {
            auto lb = mp.lower_bound(arr[i]);
            if(lb != end(mp)) {
                oddTable[i] = lb->second;
            }
            auto ub = mp.upper_bound(arr[i]);
            if(ub != begin(mp)) {
                --ub;
                evenTable[i] = ub->second;
            }
            
            mp[arr[i]] = i;
        }
        
        
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            res += helper(i, true);
        }
        
        return res;
    }
};