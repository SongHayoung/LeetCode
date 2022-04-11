class Solution {
    int lastMatch(string& s) {
        vector<int> pi(s.length());
        for(int i = 1, j = 0; i < s.length(); i++) {
            while(j > 0 and s[i] != s[j])
                j = pi[j-1];
            if(s[i] == s[j]) {
                pi[i] = ++j;
            }
        }
        return pi.back();
    }
    
public:
    string shortestPalindrome(string s) {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        tmp = s + '#' + tmp;
        int pos = lastMatch(tmp);
        string rev = s.substr(pos);
        reverse(rev.begin(), rev.end());
        return rev + s;
    }
};