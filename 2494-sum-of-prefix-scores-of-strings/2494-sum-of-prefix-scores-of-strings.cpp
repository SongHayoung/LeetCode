struct Trie {
    Trie* next[26];
    int count;
    Trie():count(0) {memset(next,0,sizeof next);}

    void insert(string& s, int p = 0) {
        count++;
        if(p == s.length()) return;
        else {
            if(!next[s[p]-'a']) next[s[p]-'a'] = new Trie();
            next[s[p]-'a']->insert(s,p + 1);
        }
    }

    int query(string s, int p = 0) {
        if(p == s.length()) return count;
        else {
            return count + next[s[p]-'a']->query(s,p+1);
        }
    }
};
class Solution {
    Trie* trie;
    int query(string s) {
        int res = 0;
        Trie* runner = trie;
        for(int i = 0; i < s.length(); i++) {
            res += runner->count;
            runner = runner->next[s[i]-'a'];
        }
        return res + runner->count;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        trie = new Trie();
        for(auto& w : words) trie->insert(w);
        vector<int> res;
        for(auto& w : words) res.push_back(query(w) - words.size());
        return res;

    }
};