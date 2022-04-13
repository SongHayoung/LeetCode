class Trie {
    Trie* next[26] = {};
    bool eof;
public:
    Trie(): eof(false) {};

    void insert(string& w, int pos) {
        if(pos == -1) eof = true;
        else {
            if(next[w[pos]-'a'] == nullptr) {
                next[w[pos]-'a'] = new Trie();
            }
            next[w[pos]-'a']->insert(w, pos-1);
        }
    }
    bool find(string& w, int pos) {
        if(pos == -1 || eof) return eof;
        if(next[w[pos]-'a'] == nullptr) return false;
        return next[w[pos]-'a']->find(w, pos-1);
    }
};

class StreamChecker {
    string s;
    Trie* trie;
public:
    StreamChecker(vector<string>& words) {
        this->trie = new Trie();
        for(auto& w : words) {
            trie->insert(w, w.length() - 1);
        }
    }

    bool query(char letter) {
        s += letter;
        return trie->find(s, s.length() - 1);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */