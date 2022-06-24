class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        for(int i = s.length() - 1; i >= 0; i--) {
            res.push_back(s[i]);
            if(!spaces.empty() and spaces.back() == i) {
                res.push_back(' ');
                spaces.pop_back();
            }
        }
        reverse(begin(res), end(res));
        return res;
    }
};