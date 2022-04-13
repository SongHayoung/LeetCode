class Solution {
    unordered_map<string, string> mp;
    string find(string& s) {
        if(!mp.count(s)) return mp[s] = s;
        return __find(s);
    }
    string __find(string& s) {
        return mp[s] == s ? s : mp[s] = __find(mp[s]);
    }
    void uni(string& a, string& b) {
        string pa = find(a), pb = find(b);
        if(pa > pb) {
            mp[pa] = mp[pb] = pb;
        } else {
            mp[pa] = mp[pb] = pa;
        }
    }
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()) return false;
        for(auto sim : similarPairs) {
            uni(sim[0], sim[1]);
        }
        for(int i = 0; i < sentence1.size(); i++) {
            if(find(sentence1[i]) != find(sentence2[i])) return false;
        }
        
        return true;
    }
};