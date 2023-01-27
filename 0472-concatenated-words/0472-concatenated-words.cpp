struct Trie{
    Trie* next[26];
    bool eof;
    Trie(): eof(false) {
        memset(next,0,sizeof(next));
    }
};
class Solution {
    Trie* root;
    void insert(string& word) {
        Trie* trie = root;
        for(auto ch : word) {
            if(!trie->next[ch-'a'])
                trie->next[ch-'a'] = new Trie();
            trie = trie->next[ch-'a'];
        }
        trie->eof = true;
    }
    bool find(string& word, int i, bool concated = false) {
        Trie* trie = root;
        while(i < word.length()) {
            if(!trie->next[word[i]-'a']) return false;
            trie = trie->next[word[i++]-'a'];
            if(trie->eof) {
                if(i == word.length()) return concated;
                else if(find(word, i, true))
                    return true;
            }
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new Trie();
        vector<string> res;
        for(auto& word : words)
            insert(word);
        for(auto& word : words)
            if(find(word, 0))
                res.push_back(word);
        return res;
    }
};