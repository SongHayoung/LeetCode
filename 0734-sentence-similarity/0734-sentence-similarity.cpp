class Solution {
public:
    bool areSentencesSimilar(vector<string>& s1, vector<string>& s2, vector<vector<string>>& similarPairs) {
        if(s1.size() != s2.size()) return false;
        map<string, unordered_set<string>> p;
        for(auto vec : similarPairs) {
            p[vec[0]].insert(vec[1]);
            p[vec[1]].insert(vec[0]);
        }
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] == s2[i] or p[s1[i]].count(s2[i])) continue;
            return false;
        }
        return true;
    }
};