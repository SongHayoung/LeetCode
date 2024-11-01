class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        for(auto& ch : s) {
            if(res.size() >= 2 and res.back() == ch and res[res.size()-2] == ch) continue;
            res.push_back(ch);
        }
        return res;
    }
};