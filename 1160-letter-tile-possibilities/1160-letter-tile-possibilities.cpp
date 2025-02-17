class Solution {
    int helper(vector<int>& chars) {
        int res = 0;
        for(int i = 0; i < 26; i++) {
            if(chars[i]) {
                chars[i]--;
                res = res + helper(chars) + 1;
                chars[i]++;
            }
        }
        return res;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> chars(26,0);
        for(auto ch : tiles) chars[ch-'A']++;
        return helper(chars);
    }
};