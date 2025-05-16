class Solution {
    bool ok(string& a, string& b) {
        int d = 0;
        for(int i = 0; i < a.length() and d < 2; i++) {
            if(a[i] != b[i]) d++;
        }
        return d == 1;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& W, vector<int>& G) {
        vector<int> dp(W.size(), 1);
        vector<int> go(W.size(), -1);
        int n = W.size(), res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(W[i].length() != W[j].length()) continue;
                if(G[i] == G[j]) continue;
                if(dp[i] >= dp[j] + 1) continue;
                if(ok(W[i], W[j])) {
                    dp[i] = dp[j] + 1;
                    go[i] = j;
                }
            }
            if(dp[res] < dp[i]) res = i;
        }
        vector<string> vs;
        while(res >= 0) {
            vs.push_back(W[res]);
            res = go[res];
        }
        reverse(begin(vs), end(vs));
        return vs;
    }
};