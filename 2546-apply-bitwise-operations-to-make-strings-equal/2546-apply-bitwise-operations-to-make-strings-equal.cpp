class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if(count(begin(target), end(target), '0') == target.length()) return s == target;
        if(count(begin(s), end(s), '0') == s.length()) return false;
        return true;
    }
};