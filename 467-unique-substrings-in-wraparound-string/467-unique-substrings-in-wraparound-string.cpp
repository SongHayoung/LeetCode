class Solution {
    bool isNext(char prev, char next) {
        return next == 'a' ? prev == 'z' : next == prev + 1;
    }
public:
    int findSubstringInWraproundString(string p) {
        unordered_map<char, int> m;
        int maxLen = 1;
        m[p[0]] = maxLen;
        for(int i = 1; i < p.length(); i++) {
            maxLen = isNext(p[i - 1], p[i]) ? maxLen + 1 : 1;
            m[p[i]] = max(maxLen, m[p[i]]);
        }
        return accumulate(m.begin(), m.end(), 0, [](const int prev, const pair<const char, int>& p) { return prev + p.second; });
    }
};