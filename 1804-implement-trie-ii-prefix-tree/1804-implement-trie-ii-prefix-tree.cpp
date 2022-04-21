struct PrefixTree{
    int eof = 0;
    int prefix = 0;
    PrefixTree* next[26];
    
    PrefixTree() {
        memset(next, 0, sizeof(next));
    }
    
    void insert(string& s, int p) {
        prefix++;
        if(p == s.length()) eof++;
        else {
            if(!next[s[p]-'a']) next[s[p]-'a'] = new PrefixTree();
            next[s[p]-'a']->insert(s, p + 1);
        }
    }
    
    int equal(string& s, int p) {
        if(p == s.length()) return eof;
        if(!prefix) return 0;
        if(next[s[p] - 'a']) return next[s[p] - 'a']->equal(s, p + 1);
        return 0;
    }
    
    int prefixEqual(string& s, int p) {
        if(p == s.length()) return prefix;
        if(!prefix) return 0;
        if(next[s[p] - 'a']) return next[s[p] - 'a']->prefixEqual(s, p + 1);
        return 0;
    }
    
    bool remove(string& s, int p) {
        if(p == s.length()) {
            if(eof) {--eof; --prefix; return true;}
            return false;
        }
        if(next[s[p] - 'a']) {
            if(!prefix) return 0;
            if(next[s[p] - 'a']->remove(s, p + 1)) {
                --prefix;
                return true;
            }
            return false;
        }
        return false;
    }
};
class Trie {
    PrefixTree* pt;
public:
    Trie() {
        pt = new PrefixTree();
    }
    
    void insert(string word) {
        pt->insert(word, 0);
    }
    
    int countWordsEqualTo(string word) {
        return pt->equal(word, 0);
    }
    
    int countWordsStartingWith(string prefix) {
        return pt->prefixEqual(prefix, 0);
    }
    
    void erase(string word) {
        pt->remove(word, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */