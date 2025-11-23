vector<int> pi(string& p) {
    vector<int> PI(p.length());
    for(int i = 1, j = 0; i < p.length(); i++) {
        while(j and p[i] != p[j]) j = PI[j-1];
        if(p[i] == p[j]) PI[i] = ++j;
    }
    return PI;
}
vector<int> kmp(string& s, string& p) {
    auto PI = pi(p);
    vector<int> res;
    for(int i = 0, j = 0; i < s.length(); i++) {
        while(j and s[i] != p[j]) j = PI[j-1];
        if(s[i] == p[j]) {
            if(++j == p.length()) {
                res.push_back(i);
                j = PI[j-1];
            }
        }
    }
    return res;
}
class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        vector<vector<int>> match(target.length());
        for(int i = 0; i < words.size(); i++) {
            auto at = kmp(target, words[i]);
            for(auto& p : at) match[p].push_back(i);
        }
        vector<long long> dp(target.length(), INT_MAX);
        for(int i = 0; i < target.length(); i++) {
            for(auto& p : match[i]) {
                int at = i - words[p].length();
                long long cost = at == -1 ? 0 : dp[at];
                dp[i] = min(dp[i], cost + costs[p]);
            }
        }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};