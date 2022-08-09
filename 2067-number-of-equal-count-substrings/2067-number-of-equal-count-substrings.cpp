class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        int res = 0, n = s.length();
        for(int unique = 1; unique <= 26; unique++) {
            int len = unique * count, now = 0;
            unordered_map<char, int> freq;
            for(int i = 0; i < n; i++) {
                if(++freq[s[i]] == count) now++;
                if(i >= len and --freq[s[i-len]] == count - 1) now--;
                res += now == unique;
            }
        }
        return res;
    }
};