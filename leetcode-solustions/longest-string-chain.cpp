class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& s1, const string& s2){return s1.length() < s2.length(); });
        unordered_map<string, int> dp;
        for(auto& s : words) {
            string str = s.substr(1);
            dp[s] = max(dp[s], dp.find(str) == dp.end() ? 1 : dp[str] + 1);
            for(int i = 0; i < s.length() - 1; i++) {
                str[i] = s[i];
                dp[s] = max(dp[s], dp.find(str) == dp.end() ? 1 : dp[str] + 1);
            }
        }
        return max_element(dp.begin(), dp.end(), [](const auto& e1, const auto& e2) {return e1.second < e2.second; })->second;
    }
};
