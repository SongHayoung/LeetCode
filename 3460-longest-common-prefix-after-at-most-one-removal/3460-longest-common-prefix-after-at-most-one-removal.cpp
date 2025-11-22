class Solution {
public:
    int longestCommonPrefix(string s, string t) {
        int i = 0, j = 0, res = 0;
        while(i < s.length() and j < t.length() and abs(i-j) <= 1) {
            if(s[i] == t[j]) i++,j++,res++;
            else i++;
        }
        return res;
    }
};