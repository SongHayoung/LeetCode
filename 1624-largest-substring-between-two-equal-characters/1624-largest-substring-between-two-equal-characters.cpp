class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> freq(26,-1);
        int res = -1;
        for(int i = 0; i < s.length(); i++) {
            int x = s[i] - 'a';
            if(freq[x] == -1) freq[x] = i;
            else res = max(res, i - freq[x] - 1);
        }
        return res;
    }
};