class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string res = "";
        for(auto w : words) res.push_back(w[0]);
        return res == s;
    }
};