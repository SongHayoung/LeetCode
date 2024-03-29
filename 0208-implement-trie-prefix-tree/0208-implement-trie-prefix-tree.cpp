class Trie {
    unordered_set<string> _prefix;
    unordered_set<string> _search;
public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        stringstream ss;
        for(int i = 0; i < word.size(); i++) {
            ss << word[i];
            _prefix.insert(ss.str());
        }
        _search.insert(ss.str());
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return _search.count(word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return _prefix.count(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */