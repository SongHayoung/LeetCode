long long dp[50505][3][26];
pair<int,int> go[50505][3][26];
class Solution {
    long long helper(string& s, int pos, int cons, int ch) {
        if(dp[pos][cons][ch] != -1) return dp[pos][cons][ch];
        long long& res = dp[pos][cons][ch] = INT_MAX;
        pair<int,int>& g = go[pos][cons][ch] = {-1,-1};
        long long c = abs(ch - (s[pos] - 'a'));
        if(pos + 1 == s.length()) return res = (cons == 2 ? c : INT_MAX);
        if(cons == 2) {
            for(int i = 0; i < 26; i++) {
                int cc = i == ch ? 2 : 0;
                long long now = helper(s,pos + 1, cc,i) + c;
                if(now < res) {
                    res = now;
                    g = {cc,i};
                }
            }
        } else {
            res = helper(s,pos + 1, cons + 1, ch) + c;
            g = {cons + 1, ch};
        }
        return res;
    }
public:
    string minCostGoodCaption(string& caption) {
        if(caption.size() <= 2) return "";
        memset(dp,-1,sizeof dp);
        long long target = 0, cost = INT_MAX;
        for(int i = 0; i < 26; i++) {
            long long now = helper(caption,0,0,i);
            if(now < cost) {
                cost = now;
                target = i;
            }
        }
        int c = 0;
        string res = "";
        for(int i = 0; i < caption.size(); i++) {
            auto [cc, tt] = go[i][c][target];
            res.push_back(target + 'a');
            c = cc, target = tt;
        }
        return res;
    }
};