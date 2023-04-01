
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int mi = 0, now = 0, res = 0;
        unordered_map<char, int> sc;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            sc[ch] = ch - 'a' + 1; 
        }
        for(int i = 0; i < chars.size(); i++) sc[chars[i]] = vals[i];
        for(int i = 0; i < s.length(); i++) {
            now += sc[s[i]];
            res = max(res, now - mi);
            mi = min(mi, now);
        }
        return res;
    }
};

