class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int p = 2;
        while (s.size() < n) s += string(s[p++] & 0b1111, s.back()^3);
        return count(s.begin(), s.begin() + n, '1');
    }
};