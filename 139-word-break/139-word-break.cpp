struct Trie {
    Trie* next[26];
    bool eof;
    Trie(): eof(false) {
        memset(next,0,sizeof(next));
    }

    void insert(const char* k) {
        if('a' <= *k and *k <= 'z') {
            if(!next[*k-'a']) next[*k-'a'] = new Trie();
            next[*k-'a']->insert(k+1);
        } else eof = true;
    }

    bool has(char ch) {
        return next[ch - 'a'];
    }

    Trie* get(char ch) {
        return next[ch - 'a'];
    }
};
class Solution {
    int dp[300];
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        Trie *trie = new Trie();
        for(auto& w : wordDict)
            trie->insert(w.c_str());
        return solution(s,trie,0);
    }

    bool solution(string& s, Trie* root, int p) {
        if(s.length() == p) return true;
        if(dp[p] != -1) return dp[p];
        Trie* c = root;
        for(int i = p; i < s.length() and c->has(s[i]); i++) {
            c = c->get(s[i]);
            if(c->eof and solution(s,root,i+1)) {
                return dp[p] = true;
            }

        }
        return dp[p] = false;
    }
};