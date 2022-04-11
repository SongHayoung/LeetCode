class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int res = 0;
        for(int l=0, r = 0; r < s.length(); r++) {
            while(m[s[r]]) {
                m[s[l++]]--;
            }
            m[s[r]]++;
            res = max(res, r - l + 1);
        }
        return res;
    }
};