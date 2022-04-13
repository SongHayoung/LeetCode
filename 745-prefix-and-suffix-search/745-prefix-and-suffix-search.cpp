struct Trie {
    unordered_map<char, Trie*> next;
    int index;
    Trie(int idx):index(idx) {}
    void insert(const char* ch, int idx) {
        if(('a' <= * ch and *ch <= 'z') or *ch == '#')  {
            if(!next.count(*ch)) next[*ch] = new Trie(idx);
            next[*ch]->insert(ch+1, idx);
        }
    }
    int find(const char* ch) {
        if(('a' <= * ch and *ch <= 'z') or *ch == '#') {
            if(!next.count(*ch)) return -1;
            return next[*ch]->find(ch + 1);
        }
        return index;
    }
};
class WordFilter {
    Trie* inverseTrie;
public:
    WordFilter(vector<string>& words) { //o(n^2)
        inverseTrie = new Trie(-1);
        unordered_set<string> contain;
        for(int i = words.size() - 1; i >= 0; i--) {
            if(contain.count(words[i])) continue;
            contain.insert(words[i]);
            int len = words[i].length();
            words[i] = words[i] + '#' + words[i];
            for(int j = 0; j < len; j++) {
                inverseTrie->insert(words[i].c_str() + j, i);
            }
        }
    }

    int f(string prefix, string suffix) { //o(nm)
        string str = suffix + '#' + prefix;
        return inverseTrie->find(str.c_str());
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */