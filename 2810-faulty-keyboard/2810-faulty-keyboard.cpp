class Solution {
public:
    string finalString(string s) {
        string res = "";
        for(auto& ch : s) {
            if(ch == 'i') {
                reverse(begin(res), end(res));
            } else res.push_back(ch);
        }
        return res;
    }
};