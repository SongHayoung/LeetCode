struct Trie {
    Trie* next[26];
    bool isFinish;
public:
    Trie(): isFinish(false) {
        memset(next,0,sizeof(next));
    }
    
    void insert(const char* str) {
        if('a' <= *str and *str <= 'z') {
            if(!next[*str-'a']) next[*str-'a'] = new Trie();
            next[*str-'a']->insert(str + 1);
        } else isFinish = true;
    }
    
    bool has(char ch) {
        return next[ch-'a'];
    }
    
    Trie* get(char ch) {
        return next[ch-'a'];
    }
};
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie* trie = new Trie();
        for(auto& s : wordDict) {
            trie->insert(s.c_str());
        }
        vector<string> res;
        string str = "";
        backTracking(res,s,trie,str,0);
        return res;
    }
    void backTracking(vector<string>& res, string& s, Trie* root, string tmp, int p) {
        if(p == s.length()) {
            tmp.pop_back();
            res.push_back(tmp);
            return;
        }
        Trie* trie = root;
        for(int i = p; i < s.length(); i++) {
            if(trie->has(s[i])) {
                trie = trie->get(s[i]);
                tmp += s[i];
                if(trie->isFinish) {
                    tmp += ' ';
                    backTracking(res, s, root, tmp, i + 1);
                    tmp.pop_back();
                }
            } else return;
        }
    }
};