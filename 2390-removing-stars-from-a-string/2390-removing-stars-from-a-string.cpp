class Solution {
public:
    string removeStars(string s) {
        string res = "";
        for(auto& ch : s) {
            if(ch == '*') {
                if(!res.empty()) res.pop_back();
            } else res.push_back(ch);
        }
        return res;
    }
};