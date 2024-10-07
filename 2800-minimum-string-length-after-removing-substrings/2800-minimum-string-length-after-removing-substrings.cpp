class Solution {
public:
    int minLength(string s) {
        string res = "";
        for(auto ch : s) {
            if(ch == 'B' and res.size() and res.back() == 'A') res.pop_back();
            else if(ch == 'D' and res.size() and res.back() == 'C') res.pop_back();
            else res.push_back(ch);
        }
        return res.size();
    }
};