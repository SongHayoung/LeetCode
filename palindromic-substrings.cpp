class Solution {
    int compare(string& s, int start, int end) {
        int res = 0;
        while(start != -1 && end != s.length()) {
            if(s[start] == s[end]) {
                start--, end++, res++;
            } else {
                return res;
            }
        }
        return res;
    }
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            res += 1 + compare(s, i - 1, i + 1) + compare(s, i, i + 1);
        }

        return res;
    }
};
