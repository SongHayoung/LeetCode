class Solution {
public:
    int minLengthAfterRemovals(string s) {
        return abs((int)s.length() - count(begin(s), end(s), 'a') * 2);
    }
};