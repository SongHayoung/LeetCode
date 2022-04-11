class Solution {
    int dp[101][101];
    vector<int> seq[26];
    int helper(string& k, int p, int selected, int append) {
        if(p == k.length())
            return 0;
        if(dp[p][selected] != -1) return dp[p][selected];
        dp[p][selected] = INT_MAX;
        for(auto n : seq[k[p]-'a']) {
            int move = min({abs(selected-n), abs(selected+append-n),abs(n - selected),abs(n + append - selected)});
            dp[p][selected] = min(dp[p][selected],helper(k,p+1,n, append) + move);
        }
        return dp[p][selected];
    }
public:
    int findRotateSteps(string ring, string key) {
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < ring.size(); i++) {
            seq[ring[i]-'a'].push_back(i);
        }   
        
        return helper(key,0,0,ring.length()) + key.length();
    }
};