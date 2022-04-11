struct Trie{
    Trie* next[26];
    bool eof;
    Trie():eof(false) {
        memset(next, 0, sizeof(next));
    }

    void insert(string s, int i) {
        if(i == s.length()) eof = true;
        else {
            if(!next[s[i]-'a']) next[s[i]-'a'] = new Trie();
            next[s[i]-'a']->insert(s,i+1);
        }
    }

    bool search(string s, int i, bool changed) {
        if(s.length() == i) return eof && changed;
        if(changed) {
            if(!next[s[i]-'a']) return false;
            return next[s[i]-'a']->search(s,i+1,changed);
        } else {
            bool res = false;
            if(next[s[i]-'a']) res = next[s[i]-'a']->search(s, i + 1, changed);

            for(int p = 0; p < 26 and !res; p++) {
                if(!next[p] or p == s[i]-'a') continue;
                res |= next[p]->search(s, i + 1, true);
            }

            return res;
        }
    }
};

class MagicDictionary {
    Trie* trie;
public:
    MagicDictionary() {
        trie = new Trie();
    }

    void buildDict(vector<string> dictionary) {
        for(auto dict : dictionary)
            trie->insert(dict, 0);
    }

    bool search(string searchWord) {
        return trie->search(searchWord, 0, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */