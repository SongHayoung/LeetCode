class Solution {
public:
    int minLengthAfterRemovals(string s) {
        return (int)s.length() - count(begin(s), end(s), 'b') * 2;
    }
};