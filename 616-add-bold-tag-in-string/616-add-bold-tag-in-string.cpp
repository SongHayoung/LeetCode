class Trie {
    Trie* next[76];
    bool endOfWord;

public:
    Trie() {
        memset(next, 0, sizeof(next));
        endOfWord = false;
    }

    void insert(const char* word) {
        if(*word == '\0') {
            endOfWord = true;
        } else {
            if(!next[*word - '0']) next[*word - '0'] = new Trie();
            next[*word - '0']->insert(word + 1);
        }
    }

    int find(const char* word, int length = 0, int res = -1) {
        if(*word == '\0' || !next[*word - '0']) {
            return endOfWord ? length - 1 : res;
        } else {
            return endOfWord ? next[*word - '0']->find(word + 1, length + 1, length) : next[*word - '0']->find(word + 1, length + 1, res);
        }
    }
};
class Solution {
    bool canMerge(pair<int, int> p1, pair<int, int> p2) {
        return p1.first <= p2.first && p2.first <= p1.second + 1;
    }
public:
    string addBoldTag(string s, vector<string>& words) {
        vector<pair<int, int>> boldRange;
        Trie* trie = new Trie();
        const char* str = s.c_str();
        stringstream ss;

        for(auto word : words) {
            trie->insert(word.c_str());
        }

        for(int i = 0; i < s.length(); i++) {
            int find = trie->find(str + i);
            if(find == -1) continue;
            pair<int, int> range = {i, i + find};
            if(boldRange.empty() || !canMerge(boldRange.back(), range)) boldRange.push_back(range);
            else boldRange.back().second = max(boldRange.back().second, range.second);
        }

        for(int i = 0, idx = 0; i < s.length(); i++) {
            if(boldRange.size() <= idx) return ss.str() + (str + i);
            if(boldRange[idx].first == i) ss << "<b>";
            ss << s[i];
            if(boldRange[idx].second == i) ss << "</b>", idx++;
        }


        return ss.str();
    }
};