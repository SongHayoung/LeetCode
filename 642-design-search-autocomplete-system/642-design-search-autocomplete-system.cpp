struct Trie {
    unordered_map<char, Trie*> next;
    unordered_map<string, int> count;
    vector<pair<string, int>> top;

    Trie() {}
    void order(string s, int times) {
        auto sorting = [](pair<string, int> p1, pair<string,int> p2) {
            if(p1.second == p2.second) return p1.first < p2.first;
            return p1.second > p2.second;
        };
        bool contain = false;
        for(int i = 0; i < top.size(); i++) {
            if(top[i].first == s) {
                contain = true;
                top[i].second = times;
            }
        }
        if(!contain)
            top.push_back({s,times});
        sort(top.begin(),top.end(), sorting);
        if(top.size() > 3) top.pop_back();
    }
    void insert(string s, int times, int i = 0) {
        if(i > s.length()) return;
        else {
            if(!next.count(s[i])) next[s[i]] = new Trie();
            next[s[i]]->insert(s,times,i+1);
        }
        count[s] += times;
        order(s,count[s]);
    }

    pair<Trie*, vector<string>> getNext(char ch) {
        if(!next.count(ch)) return {NULL, {}};
        auto node = next[ch];
        vector<string> res;
        for(auto [str, cnt] : node->top) {
            res.push_back(str);
        }
        return {node, res};
    }

};
class AutocompleteSystem {
    Trie* root;
    Trie* cur;
    string history;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Trie();
        for(int i = 0; i < sentences.size(); i++) {
            root->insert(sentences[i], times[i]);
        }
        cur = root;
        history = "";
    }

    vector<string> input(char c) {
        if(c == '#') {
            cur = root;
            root->insert(history, 1);
            history = "";
            return {};
        }
        history += c;
        if(!cur) return {};
        auto [node, res] = cur->getNext(c);
        cur = node;
        return res;
    }
};