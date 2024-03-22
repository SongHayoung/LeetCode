class Solution {
public:
    string removeVowels(string s) {
        string res = "";
        for(auto ch : s) {
            if(ch == 'a' or ch == 'i' or ch == 'e' or ch == 'o' or ch == 'u') continue;
            res.push_back(ch);
        }
        return res;
    }
};