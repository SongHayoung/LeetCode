class Solution {
    vector<vector<int>> jumpTo;
    vector<vector<int>> dp;
    int helper(int pos, bool odd, int target) {
        if(pos == target) return 1;
        if(dp[pos][odd] != -1) return dp[pos][odd];
        dp[pos][odd] = 0;
        if(jumpTo[pos][odd] != -1)
            dp[pos][odd] = helper(jumpTo[pos][odd], !odd, target);
        return dp[pos][odd];
    }
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        jumpTo = vector<vector<int>>(n, vector<int>(2,-1));
        dp = vector<vector<int>>(n, vector<int>(2,-1));
        map<int, int> mp;
        for(int i = n - 1; i >= 0; i--) {
            auto it = mp.lower_bound(arr[i]);
            if(it != end(mp))
                jumpTo[i][1] = it->second;
            if(it != end(mp) and it->first == arr[i])
                jumpTo[i][0] = it->second;
            else if(it != begin(mp))
                jumpTo[i][0] = prev(it)->second;
            mp[arr[i]] = i; 
        }
        
        
        int res =0;
        for(int i = 0; i < n; i++) {
            res += helper(i,true,n-1);
        }
        return res;
    }
};