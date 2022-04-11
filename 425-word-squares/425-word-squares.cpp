struct Trie {
    unordered_set<string> s;
    Trie* next[26];
    Trie() {
        memset(next,0,sizeof(next));
    }
    void insert(string str, int i = 0) {
        if(i == str.length()) {
            s.insert(str);
        } else {
            if(!next[str[i]-'a']) next[str[i]-'a'] = new Trie();
            next[str[i]-'a']->insert(str,i+1);
        }
    }
    unordered_set<string> find(string str, int maxStep, int i = 0) {
        if(i == maxStep) {
            return s;
        } else if(str[i] != '#') {
            if(!next[str[i]-'a']) return {};
            return next[str[i]-'a']->find(str, maxStep, i+1);
        } else {
            unordered_set<string> res;
            for(int j = 0; j < 26; j++) {
                if(next[j]) {
                    auto words = next[j]->find(str, maxStep, i +1);
                    res.insert(words.begin(),words.end());
                }
            }
            return res;
        }
    }
};
class Solution {
    Trie* trie;
    vector<vector<string>> res;
    void backTracking(vector<string>& sq, int step, int maxStep) {
        if(step == maxStep) {
            vector<string> ans;
            for(int i = 0; i < maxStep; i++) {
                ans.push_back(sq[i].substr(0,maxStep));
            }
            res.push_back(ans);
            return;
        }
        unordered_set<string> words = trie->find(sq[step].substr(0,maxStep), maxStep);
        
        for(auto w : words) {
            for(int i = 0; i < w.length(); i++)
                sq[i][step] = sq[step][i] = w[i];
            backTracking(sq, step + 1, maxStep);
        }
        for(int i = step; i < 4; i++) sq[step][i] = sq[i][step] = '#';
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        trie = new Trie();
        for(auto w : words) {
            trie->insert(w);
        }
        vector<string> tmp = {"####", "####","####","####"};
        for(auto w : words) {
            for(int i = 0; i < w.length(); i++)
                tmp[i][0] = tmp[0][i] = w[i];
            backTracking(tmp, 1, w.length());
            for(int i = 0; i < 4; i++) tmp[0][i] = tmp[i][0] = '#';
        }
        return res;
    }
};