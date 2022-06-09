class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int sum = 0, mod = 26, n = s.length();
        for(int i = n - 1; i >= 0; i--) {
            sum = (sum + shifts[i]) % mod;
            int offset = s[i] - 'a';
            offset = (offset + sum) % mod;
            s[i] = offset + 'a';
        }
        return s;
    }
};