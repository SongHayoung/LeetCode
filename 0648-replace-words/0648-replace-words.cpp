struct Trie {
    Trie* next[26];
    bool eof = false;
    string res = "";
    Trie() {memset(next, 0, sizeof next);}
    
    void insert(string& s, int p = 0) {
        if(s.length() == p) eof = true, res = s;
        else {
            if(!next[s[p]-'a']) next[s[p]-'a'] = new Trie();
            next[s[p]-'a']->insert(s, p + 1);
        }
    }
    
    string query(string& s, int p = 0) {
        if(s.length() == p) return s;
        if(eof) return res;
        else {
            if(!next[s[p]-'a']) return s;
            return next[s[p]-'a']->query(s, p + 1);
        }
    }
};

class Solution {
    string parse(string& s, int& p) {
        int n = s.length();
        string res = "";
        while(p < n and s[p] != ' ') {
            res.push_back(s[p++]);
        }
        p++;
        return res;
    }
public:
    string replaceWords(vector<string>& dict, string s) {
        Trie* t = new Trie();
        for(auto& d : dict) t->insert(d);
        
        string res = "";
        int i = 0, n = s.length();
        while(i < n) {
            string word = parse(s, i);
            res += t->query(word) + " ";
        }
        res.pop_back();
        return res;
    }
};