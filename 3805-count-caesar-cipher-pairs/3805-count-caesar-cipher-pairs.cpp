
struct Trie {
    int cnt;
    Trie* next[26];
    Trie() {
        memset(next, 0, sizeof next);
        cnt = 0;
    }
    int insert(string& s, int pos) {
        if(s.length() == pos) {
            cnt++;
            return cnt - 1;
        } else {
            if(!next[s[pos]-'a']) next[s[pos]-'a'] = new Trie();
            return next[s[pos]-'a']->insert(s,pos+1);
        }
    }
};
class Solution {
    string convert(string& s) {
        int diff = s[0] - 'a';
        for(auto& ch : s) ch = (ch - 'a' - diff + 26) % 26 + 'a'; 
        return s;
    }
public:
    long long countPairs(vector<string>& words) {
        long long res = 0;
        Trie* t = new Trie();
        for(auto& w : words) {
            string s = convert(w);
            res += t->insert(s,0);
        }
        return res;
    }
};