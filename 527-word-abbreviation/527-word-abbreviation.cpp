struct Trie {
    Trie* next[26];
    int cnt;
public:
    Trie():cnt(0){
        memset(next,0,sizeof(next));
    }
    void insert(string str, int i) {
        if(i != str.length()) {
            if(!next[str[i]-'a']) next[str[i]-'a'] = new Trie();
            next[str[i]-'a']->insert(str,i+1);
        }
        cnt++;
    }
    int find(string str, int i) {
        if(i == str.length()) return i;
        if(cnt == 1) return i-1;
        return next[str[i]-'a']->find(str,i+1);
    }

};
class Solution {
    string abbreviation(string str) {
        string abb = str[0] + to_string(str.length()-2) + str[str.length() - 1];
        if(abb.length() < str.length()) return abb;
        return str;
    }
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        
        unordered_map<string, vector<pair<int,string>>> table;
        vector<string> res(words.size());
        for(int i = 0; i < words.size(); i++) {
            string abb = abbreviation(words[i]);
            table[abb].push_back({i,words[i]});
            res[i] = abb;
        }

        
        for(auto [k, v]: table) {
            if(v.size() == 1) continue;
            Trie* trie = new Trie();
            for(auto [_, str] : v) {
                trie->insert(str,0);
            }
            for(auto [idx, str] : v) {
                auto sep = trie->find(str,0);
                res[idx] = str.substr(0,sep) + abbreviation(str.substr(sep));
            }
        }

        return res;
    }
};