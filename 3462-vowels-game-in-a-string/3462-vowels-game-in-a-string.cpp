class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> v{'a','e','i','o','u'};
        for(auto& ch : s) {
            if(v.count(ch)) return true;
        }
        return false;
    }
};