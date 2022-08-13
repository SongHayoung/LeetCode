class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length(), res = 0;
        vector<pair<int, int>> fe(26, {INT_MAX - 1, INT_MIN});
        for(int i = 0; i < n; i++) {
            fe[s[i]-'a'].first = min(fe[s[i]-'a'].first, i);
            fe[s[i]-'a'].second = max(fe[s[i]-'a'].second, i);
        }
        for(int i = 0; i < 26; i++) {
            auto [f, e] = fe[i];
            int mask = 0;
            for(int j = f + 1; j < e; j++) {
                mask |= 1<<(s[j] - 'a');
            }
            res += __builtin_popcount(mask);
        }
        return res;
    }
};