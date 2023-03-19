class Trie {
public:
    Trie* child[26];
    bool endOfWord = false;
    Trie() {
        memset(child,0,sizeof(child));
    }
    void createChild(char c) {
        child[c-'a'] = new Trie();
    }
};

class WordDictionary {
    Trie* root = new Trie();
    bool _search(string& word, Trie* node, int i = 0) {
        for(; node && i < word.length(); i++) {
            if(word[i] != '.') {
                if(!node->child[word[i]-'a']) return false;
                node = node->child[word[i]-'a'];
            } else {
                for(int j = 0; j < 26; j++) {
                    if(node->child[j] && _search(word, node->child[j], i + 1))
                        return true;
                }
                return false;
            }
        }
        return node && node->endOfWord;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {}

    void addWord(string word) {
        Trie* node = root;
        for(auto& c : word) {
            if(!node->child[c-'a']) node->createChild(c);
            node = node->child[c-'a'];
        }
        node->endOfWord = true;
    }

    bool search(string word) {
        return _search(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */