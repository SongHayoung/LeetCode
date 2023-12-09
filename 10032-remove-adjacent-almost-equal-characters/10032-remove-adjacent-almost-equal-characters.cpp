class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        vector<int> dp(26,1);
        dp[s[0] - 'a'] = 0;
        for(int i = 1; i < s.length(); i++) {
            vector<int> dpp(26,INT_MAX);
            int x = s[i] - 'a';
            for(int j = 0; j < 26; j++) {
                int c = (x != j), best = INT_MAX;
                for(int k = 0; k < 26; k++) {
                    if(abs(j-k) <= 1) continue;
                    best = min(best, dp[k]);
                }
                dpp[j] = min(dpp[j], c + best);
            }
            swap(dp,dpp);
        }
        return *min_element(begin(dp),end(dp));
    }
};