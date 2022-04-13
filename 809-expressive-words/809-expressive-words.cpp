class Solution {
    bool equal(char a, char b, char c) {
        return a == b && b == c;
    }
    bool compare(string& s, string &w) {
        int j(0), slen(s.length()), wlen(w.length());
        for(int i(0);i < slen; i++) {
            if(s[i] == w[j] and j < wlen) j++;
            else if(0 < i and i < slen - 1 and equal(s[i - 1], s[i], s[i + 1]));
            else if(i > 1 and equal(s[i - 2], s[i - 1], s[i]));
            else return false;
        }
        return j == wlen;
    }
public:
    int expressiveWords(string s, vector<string>& words) {
        int res(0);
        for(auto& w : words) {
            if(compare(s, w)) ++res;
        }
        return res;
    }
};