class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int cache[26][26]{0,}, res(0), op(INT_MAX - 1), eq(0);
        for(auto& w: words) {
            ++cache[w[0]-'a'][w[1]-'a'];
        }
        for(int i = 0; i < 26; i++) {
            eq |= cache[i][i] & 1;
            res += cache[i][i] & op;
            for(int j = i + 1; j < 26; j++) {
                res += min(cache[i][j], cache[j][i]) << 1;
            }
        }

        return (res + eq)<<1;
    }
};