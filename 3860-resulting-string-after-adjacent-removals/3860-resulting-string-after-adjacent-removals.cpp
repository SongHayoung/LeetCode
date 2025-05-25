class Solution {
    bool cons(char a, char b) {
        int d = abs(a-b);
        return d == 1 or d == 25;
    }
public:
    string resultingString(string s) {
        string res = "";
        for(auto& ch : s) {
            if(res.length() and cons(res.back(), ch)) res.pop_back();
            else res.push_back(ch);
        }
        return res;
    }
};