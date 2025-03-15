struct Trie {
    int cnt, depth, k;
    int best;
    Trie *next[26];
    Trie(int k) : cnt(0), depth(0), k(k), best(0) {
        memset(next, 0, sizeof next);
    }
    void update() {
        best = 0;
        if(cnt >= k) {
            best = max(best, depth);
            for(int i = 0; i < 26; i++) {
                if(next[i]) best = max(best, next[i]->best);
            }
        }
    }
    void insert(string& s, int pos = 0) {
        cnt++, depth = pos;
        if(pos != s.size()) {
            if(!next[s[pos]-'a']) next[s[pos]-'a'] = new Trie(k);
            next[s[pos]-'a']->insert(s,pos+1);
        }
        update();
    }
    void clean(string& s, int pos = 0) {
        cnt--, depth = pos;
        if(pos != s.size()) {
            next[s[pos]-'a']->clean(s,pos+1);
        }
        update();
    }
};

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        Trie* t = new Trie(k);
        for(auto& w : words) t->insert(w);
        vector<int> res;
        for(auto& w : words) {
            t->clean(w);
            res.push_back(t->best);
            t->insert(w);
        }
        return res;
    }
};