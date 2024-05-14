struct Trie {
    Trie* next[26];
    Trie() {
        memset(next, 0, sizeof next);
    }
    bool insert(string& s, int p) {
        if(p == s.length()) return true;
        if(!next[s[p]-'a']) {
            if(p != s.length() - 1) return false;
            next[s[p]-'a'] = new Trie();
        }
        return next[s[p]-'a']->insert(s,p+1);
    }
};
class Solution {
public:
    string longestWord(vector<string>& A) {
        sort(begin(A), end(A), [&](string& a, string& b) {
            if(a.length() == b.length()) return a > b;
            return a.length() < b.length();
        });
        string res = "";
        Trie* t = new Trie();
        for(auto& x : A) {
            if(t->insert(x,0)) res = x;
        }
        return res;
    }
};