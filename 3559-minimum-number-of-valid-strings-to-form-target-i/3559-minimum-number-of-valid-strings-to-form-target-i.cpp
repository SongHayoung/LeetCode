long long mem[50505];
struct Trie{
    Trie* next[26];
    Trie() {
        memset(next, 0, sizeof next);
    }
    void insert(string& s, int p = 0) {
        if(p == s.length()) return;
        if(!next[s[p]-'a']) next[s[p]-'a'] = new Trie();
        next[s[p]-'a']->insert(s,p+1);
    }
    void query(string& s, int p, long long c) {
        if(p == s.length()) return;
        if(!next[s[p]-'a']) return;
        mem[p+1] = min(mem[p+1], c + 1);
        next[s[p]-'a']->query(s,p+1,c);
    }
};
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        memset(mem, -1, sizeof mem);
        mem[0] = 0;
        Trie* t = new Trie();
        for(auto& w : words) t->insert(w);
        for(int i = 1; i <= target.length(); i++) mem[i] = INT_MAX;
        for(int i = 0; i < target.length(); i++) {
            if(mem[i] == INT_MAX) continue;
            t->query(target,i,mem[i]);
        }
        return mem[target.length()] == INT_MAX ? -1 : mem[target.length()];
    }
};

