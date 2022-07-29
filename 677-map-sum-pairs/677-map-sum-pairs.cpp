struct Trie {
    Trie* next[26];
    int sum;
    int score;
    Trie():sum(0),score(0) {
        memset(next,0,sizeof next);
    }
    int insert(string& s, int val, int p = 0) {
        if(p == s.length()) {
            int modify = val - score;
            score = val;
            sum += modify;
            return modify;
        } else {
            if(!next[s[p]-'a']) next[s[p]-'a'] = new Trie();
            int modify = next[s[p]-'a']->insert(s,val,p+1);
            sum += modify;
            return modify;
        }
    }
    int query(string& s, int p = 0) {
        if(s.length() == p) return sum;
        return next[s[p]-'a'] ? next[s[p]-'a']->query(s,p+1) : 0;
    }
};
class MapSum {
    Trie* trie;
public:
    MapSum(): trie(new Trie()) {}
    
    void insert(string key, int val) {
        trie->insert(key, val);
    }
    
    int sum(string prefix) {
        return trie->query(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */