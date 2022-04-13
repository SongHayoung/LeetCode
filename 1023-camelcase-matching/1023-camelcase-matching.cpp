class Trie {
    unordered_map<char, Trie*> next;
    int eof;
    bool isNEOF(char c) {
        return ('A' <= c and c <= 'Z') or ('a' <= c and c <= 'z');
    }
public:
    Trie(): eof(-1){}

    void insert(int idx, const char* word) {
        if(!isNEOF(*word)) eof = idx;
        else {
            if(!next.count(*word)) next[*word] = new Trie();
            next[*word]->insert(idx, word+1);
        }
    }

    void match(const char* pattern, vector<bool>& res) {
        if(!isNEOF(*pattern)) {
            if(eof != -1) res[eof] = true;
            for(char c = 'a'; c <= 'z'; c++) {
                if(next.count(c)) {
                    next[c]->match(pattern, res);
                }
            }
        } else {
            if('A' <= *pattern and *pattern <= 'Z' and next.count(*pattern)) {
                next[*pattern]->match(pattern + 1, res);
            }
            for(char c = 'a'; c <= 'z'; c++) {
                if(next.count(c)) {
                    next[c]->match(c == *pattern ? pattern + 1 : pattern, res);
                }
            }
        }
    }
};
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res(queries.size(), false);
        Trie* trie = new Trie();
        for(int i = 0; i < queries.size(); i++) {
            trie->insert(i, queries[i].c_str());
        }
        trie->match(pattern.c_str(), res);
        return res;
    }
};